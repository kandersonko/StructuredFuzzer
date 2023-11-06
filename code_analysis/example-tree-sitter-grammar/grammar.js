// tree-sitter grammar for the Structured Text programming language

const unsignedInteger = seq(
  /\d/,
  repeat(choice('_', /\d/))
);

const signedInteger = seq(
  optional(/[\+-]/),
  unsignedInteger
);

module.exports = grammar({
  name: 'StructuredText',

  rules: {
    source_file: $ => repeat(choice($.program, $.configuration, $.function_block)),

    program: $ => seq(
      'PROGRAM', $.identifier,
      repeat($.variable_block),
      repeat($._statement),
      'END_PROGRAM'
    ),

    variable_block: $ => choice(
      $.var_block, $.var_input_block, $.var_output_block, $.var_constant_block
    ),

    configuration: $ => seq(
      'CONFIGURATION', $.identifier,
      'RESOURCE', $.identifier, 'ON', $.identifier,
      repeat($._resource_element),
      'END_RESOURCE',
      'END_CONFIGURATION'
    ),

    function_block: $ => seq(
      'FUNCTION_BLOCK', $.identifier,
      repeat(choice($.var_block, $.var_input_block, $.var_output_block)),
      repeat($._statement),
      'END_FUNCTION_BLOCK'
    ),

    _resource_element: $ => choice(
      $.task,
      $.program_instance
    ),

    task: $ => seq(
      'TASK', $.identifier, 
      '(', 'INTERVAL', ':=', $.time_literal, ',', 'PRIORITY', ':=', $.number, ')', ';'
    ),

    program_instance: $ => seq(
      'PROGRAM', $.identifier, 'WITH', $.identifier, ':', $.identifier, ';'
    ),

    var_block: $ => seq(
      'VAR',
      repeat($.var_declaration),
      'END_VAR'
    ),

    var_input_block: $ => seq(
      'VAR_INPUT',
      repeat($.var_declaration),
      'END_VAR'
    ),

    var_output_block: $ => seq(
      'VAR_OUTPUT',
      repeat($.var_declaration),
      'END_VAR'
    ),

    var_constant_block: $ => seq(
      'VAR_CONSTANT',
      repeat($.var_declaration),
      'END_VAR'
    ),

    var_declaration: $ => seq(
      $.identifier, 
      optional(seq('AT', $.address)), 
      ':', 
      $.data_type, 
      optional(seq(':=', $.constant_expression)), 
      ';'
    ),

    _statement: $ => choice(
      $.assignment,
      $.function_call,
      $.if_statement,
      // ... (add other statement types here)
    ),

    assignment: $ => seq(
      $.identifier, ':=', $._expression, ';'
    ),

    function_call: $ => seq(
      $.identifier,
      '(',
      optional(seq($._expression, repeat(seq(',', $._expression)))),
      ')'
    ),

    if_statement: $ => seq(
      'IF', $._expression, 'THEN',
      repeat($._statement),
      repeat($.elsif_clause),
      optional($.else_clause),
      'END_IF', ';'
    ),

    elsif_clause: $ => seq(
      'ELSIF', $._expression, 'THEN',
      repeat($._statement)
    ),

    else_clause: $ => seq(
      'ELSE',
      repeat($._statement)
    ),
    
    _expression: $ => choice(
      $.identifier,
      $._literal,
      $.parenthesis_expression,
      $.unary_expression,
      $.binary_expression,
      $.logical_expression,
    ),
    

    logical_expression: $ => seq(
      $.logical_operator,
      $.parenthesis_expression,
      ),

    logical_operator: $ => choice(
      'AND', 'OR', 'XOR', 'NOT'
      ),

    parenthesis_expression: $ => seq('(', $._expression, ')'),

    unary_expression: $ => prec(6, choice(
      seq('NOT', $._expression),
      seq('+', $._expression),
      seq('-', $._expression)
    )),

    binary_expression: $ => choice(
      prec.left(5, seq($._expression, '**', $._expression)), // Not supported in Automation Studio
      prec.left(4, seq($._expression, '*', $._expression)),
      prec.left(4, seq($._expression, '/', $._expression)),
      prec.left(4, seq($._expression, 'MOD', $._expression)),
      prec.left(3, seq($._expression, '+', $._expression)),
      prec.left(3, seq($._expression, '-', $._expression)),
      prec.left(2, seq($._expression, '<', $._expression)),
      prec.left(2, seq($._expression, '>', $._expression)),
      prec.left(2, seq($._expression, '<=', $._expression)),
      prec.left(2, seq($._expression, '>=', $._expression)),
      prec.left(1, seq($._expression, '=', $._expression)),
      prec.left(1, seq($._expression, '<>', $._expression)),
      prec.left(0, seq($._expression, 'AND', $._expression)),
      prec.left(0, seq($._expression, 'XOR', $._expression)),
      prec.left(0, seq($._expression, 'OR', $._expression))
    ),

    parameter_assignment: $ => seq(
      alias($.identifier, $.parameter),
      ':=',
      $._expression
    ),

    repetition_expression: $ => seq(
      $._expression,
      '(', $._expression, ')'
    ),

    data_type: $ => choice('BOOL', 'REAL', 'INT'),
    constant_expression: $ => choice($.number, $.address, $.time_literal, $.bool_literal),
    address: $ => /%\w{1,2}\d{1,2}\.\d/,
    time_literal: $ => /T#\d+ms/,
    number: $ => choice(/-?\d+\.\d+/, /\d+/),
    bool_literal: $ => choice('TRUE', 'FALSE'),

    _literal: $ => choice(
      $.boolean,
      $.integer,
      $.floating_point,
      $.binary,
      $.octal,
      $.hexidecimal,
      $.time,
      $.date,
      $.time_of_day,
      $.date_and_time,
      $.string,
      $.wstring
    ),

    boolean: $ => token(choice('TRUE', 'FALSE')),

    integer: $ => {
      return token(unsignedInteger);
    },

    floating_point: $ => {
      const scientific = seq(/[eE]/, signedInteger);
      return token(seq(
        unsignedInteger,
        choice(
          seq(
            '.',
            repeat(choice('_', /\d/)),
            optional(scientific)
          ),
          scientific
        )
      ));
    },

    binary: $ => token(seq('2#', /_*[0-1]/, repeat(choice('_', /[0-1]/)))),

    octal: $ => token(seq('8#', /_*[0-7]/, repeat(choice('_', /[0-7]/)))),

    hexidecimal: $ => token(seq('16#', /_*[0-9a-fA-F]/, repeat(choice('_', /[0-9a-fA-F]/)))),

    time: $ => token(seq(
      'T#',
      optional('-'),
      optional(/\d{1,2}[dD]/),
      optional(/\d{1,3}[hH]/),
      optional(/\d{1,5}[mM]/),
      optional(/\d{1,9}[sS]/),
      optional(/\d{1,9}((ms)|(MS))/)
    )),

    date: $ => token(seq(
      'D#',
      /\d(_?\d){3}/, // Year
      /(-\d(_?\d)?){2}/ // Month and day
    )),

    time_of_day: $ => token(seq(
      'TOD#',
      /\d(_?\d)?/,
      ':',
      /\d(_?\d)?/,
      optional(seq(
        ':',
        /\d(_?\d)?/,
        optional(seq('.', /\d(_?\d)*/))
      ))
    )),

    date_and_time: $ => seq(
      'DT#',
      /\d(_?\d){3}/, // Year
      /(-\d(_?\d)?){3}/, // Month, day, hour
      /(:\d(_?\d)?){1,2}/ // Minute, second
    ),

    string: $ => token(prec.left(seq(
      '\'',
      /.*/,
      '\''
    ))),

    wstring: $ => token(prec.left(seq(
      '"',
      /.*/,
      '"'
    ))),

    inline_comment: $ => token(seq('//', /.*/)),

    // http://stackoverflow.com/questions/13014947/regex-to-match-a-c-style-multiline-comment/36328890#36328890
    block_comment: $ => token(seq(
      '(*',
      /[^*]*\*+([^*)][^*]*\*+)*/,
      ')'
    )),

    identifier: $ => /[a-zA-Z_]\w*/,
    // ... (add more rules for other syntax constructs)
  }
});

function commaSep1(rule) {
  return seq(rule, repeat(seq(',', rule)));
}

function commaSep(rule) {
  return optional(commaSep1(rule));
}
