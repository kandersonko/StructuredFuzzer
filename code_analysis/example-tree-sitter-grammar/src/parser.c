#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#ifdef _MSC_VER
#pragma optimize("", off)
#elif defined(__clang__)
#pragma clang optimize off
#elif defined(__GNUC__)
#pragma GCC optimize ("O0")
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 249
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 113
#define ALIAS_COUNT 0
#define TOKEN_COUNT 74
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 12
#define PRODUCTION_ID_COUNT 1

enum {
  anon_sym_PROGRAM = 1,
  anon_sym_END_PROGRAM = 2,
  anon_sym_CONFIGURATION = 3,
  anon_sym_RESOURCE = 4,
  anon_sym_ON = 5,
  anon_sym_END_RESOURCE = 6,
  anon_sym_END_CONFIGURATION = 7,
  anon_sym_FUNCTION_BLOCK = 8,
  anon_sym_END_FUNCTION_BLOCK = 9,
  anon_sym_TASK = 10,
  anon_sym_LPAREN = 11,
  anon_sym_INTERVAL = 12,
  anon_sym_COLON_EQ = 13,
  anon_sym_COMMA = 14,
  anon_sym_PRIORITY = 15,
  anon_sym_RPAREN = 16,
  anon_sym_SEMI = 17,
  anon_sym_WITH = 18,
  anon_sym_COLON = 19,
  anon_sym_VAR = 20,
  anon_sym_END_VAR = 21,
  anon_sym_VAR_INPUT = 22,
  anon_sym_VAR_OUTPUT = 23,
  anon_sym_VAR_CONSTANT = 24,
  anon_sym_AT = 25,
  anon_sym_IF = 26,
  anon_sym_THEN = 27,
  anon_sym_END_IF = 28,
  anon_sym_ELSIF = 29,
  anon_sym_ELSE = 30,
  anon_sym_AND = 31,
  anon_sym_OR = 32,
  anon_sym_XOR = 33,
  anon_sym_NOT = 34,
  anon_sym_PLUS = 35,
  anon_sym_DASH = 36,
  anon_sym_STAR_STAR = 37,
  anon_sym_STAR = 38,
  anon_sym_SLASH = 39,
  anon_sym_MOD = 40,
  anon_sym_LT = 41,
  anon_sym_GT = 42,
  anon_sym_LT_EQ = 43,
  anon_sym_GT_EQ = 44,
  anon_sym_EQ = 45,
  anon_sym_LT_GT = 46,
  anon_sym_BOOL = 47,
  anon_sym_REAL = 48,
  anon_sym_INT = 49,
  sym_address = 50,
  sym_time_literal = 51,
  aux_sym_number_token1 = 52,
  aux_sym_number_token2 = 53,
  anon_sym_TRUE = 54,
  anon_sym_FALSE = 55,
  sym_boolean = 56,
  sym_integer = 57,
  sym_floating_point = 58,
  sym_binary = 59,
  sym_octal = 60,
  sym_hexidecimal = 61,
  sym_time = 62,
  sym_date = 63,
  sym_time_of_day = 64,
  anon_sym_DT_POUND = 65,
  aux_sym_date_and_time_token1 = 66,
  aux_sym_date_and_time_token2 = 67,
  aux_sym_date_and_time_token3 = 68,
  sym_string = 69,
  sym_wstring = 70,
  sym_inline_comment = 71,
  sym_block_comment = 72,
  sym_identifier = 73,
  sym_source_file = 74,
  sym_program = 75,
  sym_variable_block = 76,
  sym_configuration = 77,
  sym_function_block = 78,
  sym__resource_element = 79,
  sym_task = 80,
  sym_program_instance = 81,
  sym_var_block = 82,
  sym_var_input_block = 83,
  sym_var_output_block = 84,
  sym_var_constant_block = 85,
  sym_var_declaration = 86,
  sym__statement = 87,
  sym_assignment = 88,
  sym_function_call = 89,
  sym_if_statement = 90,
  sym_elsif_clause = 91,
  sym_else_clause = 92,
  sym__expression = 93,
  sym_logical_expression = 94,
  sym_logical_operator = 95,
  sym_parenthesis_expression = 96,
  sym_unary_expression = 97,
  sym_binary_expression = 98,
  sym_data_type = 99,
  sym_constant_expression = 100,
  sym_number = 101,
  sym_bool_literal = 102,
  sym__literal = 103,
  sym_date_and_time = 104,
  aux_sym_source_file_repeat1 = 105,
  aux_sym_program_repeat1 = 106,
  aux_sym_program_repeat2 = 107,
  aux_sym_configuration_repeat1 = 108,
  aux_sym_function_block_repeat1 = 109,
  aux_sym_var_block_repeat1 = 110,
  aux_sym_function_call_repeat1 = 111,
  aux_sym_if_statement_repeat1 = 112,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_PROGRAM] = "PROGRAM",
  [anon_sym_END_PROGRAM] = "END_PROGRAM",
  [anon_sym_CONFIGURATION] = "CONFIGURATION",
  [anon_sym_RESOURCE] = "RESOURCE",
  [anon_sym_ON] = "ON",
  [anon_sym_END_RESOURCE] = "END_RESOURCE",
  [anon_sym_END_CONFIGURATION] = "END_CONFIGURATION",
  [anon_sym_FUNCTION_BLOCK] = "FUNCTION_BLOCK",
  [anon_sym_END_FUNCTION_BLOCK] = "END_FUNCTION_BLOCK",
  [anon_sym_TASK] = "TASK",
  [anon_sym_LPAREN] = "(",
  [anon_sym_INTERVAL] = "INTERVAL",
  [anon_sym_COLON_EQ] = ":=",
  [anon_sym_COMMA] = ",",
  [anon_sym_PRIORITY] = "PRIORITY",
  [anon_sym_RPAREN] = ")",
  [anon_sym_SEMI] = ";",
  [anon_sym_WITH] = "WITH",
  [anon_sym_COLON] = ":",
  [anon_sym_VAR] = "VAR",
  [anon_sym_END_VAR] = "END_VAR",
  [anon_sym_VAR_INPUT] = "VAR_INPUT",
  [anon_sym_VAR_OUTPUT] = "VAR_OUTPUT",
  [anon_sym_VAR_CONSTANT] = "VAR_CONSTANT",
  [anon_sym_AT] = "AT",
  [anon_sym_IF] = "IF",
  [anon_sym_THEN] = "THEN",
  [anon_sym_END_IF] = "END_IF",
  [anon_sym_ELSIF] = "ELSIF",
  [anon_sym_ELSE] = "ELSE",
  [anon_sym_AND] = "AND",
  [anon_sym_OR] = "OR",
  [anon_sym_XOR] = "XOR",
  [anon_sym_NOT] = "NOT",
  [anon_sym_PLUS] = "+",
  [anon_sym_DASH] = "-",
  [anon_sym_STAR_STAR] = "**",
  [anon_sym_STAR] = "*",
  [anon_sym_SLASH] = "/",
  [anon_sym_MOD] = "MOD",
  [anon_sym_LT] = "<",
  [anon_sym_GT] = ">",
  [anon_sym_LT_EQ] = "<=",
  [anon_sym_GT_EQ] = ">=",
  [anon_sym_EQ] = "=",
  [anon_sym_LT_GT] = "<>",
  [anon_sym_BOOL] = "BOOL",
  [anon_sym_REAL] = "REAL",
  [anon_sym_INT] = "INT",
  [sym_address] = "address",
  [sym_time_literal] = "time_literal",
  [aux_sym_number_token1] = "number_token1",
  [aux_sym_number_token2] = "number_token2",
  [anon_sym_TRUE] = "TRUE",
  [anon_sym_FALSE] = "FALSE",
  [sym_boolean] = "boolean",
  [sym_integer] = "integer",
  [sym_floating_point] = "floating_point",
  [sym_binary] = "binary",
  [sym_octal] = "octal",
  [sym_hexidecimal] = "hexidecimal",
  [sym_time] = "time",
  [sym_date] = "date",
  [sym_time_of_day] = "time_of_day",
  [anon_sym_DT_POUND] = "DT#",
  [aux_sym_date_and_time_token1] = "date_and_time_token1",
  [aux_sym_date_and_time_token2] = "date_and_time_token2",
  [aux_sym_date_and_time_token3] = "date_and_time_token3",
  [sym_string] = "string",
  [sym_wstring] = "wstring",
  [sym_inline_comment] = "inline_comment",
  [sym_block_comment] = "block_comment",
  [sym_identifier] = "identifier",
  [sym_source_file] = "source_file",
  [sym_program] = "program",
  [sym_variable_block] = "variable_block",
  [sym_configuration] = "configuration",
  [sym_function_block] = "function_block",
  [sym__resource_element] = "_resource_element",
  [sym_task] = "task",
  [sym_program_instance] = "program_instance",
  [sym_var_block] = "var_block",
  [sym_var_input_block] = "var_input_block",
  [sym_var_output_block] = "var_output_block",
  [sym_var_constant_block] = "var_constant_block",
  [sym_var_declaration] = "var_declaration",
  [sym__statement] = "_statement",
  [sym_assignment] = "assignment",
  [sym_function_call] = "function_call",
  [sym_if_statement] = "if_statement",
  [sym_elsif_clause] = "elsif_clause",
  [sym_else_clause] = "else_clause",
  [sym__expression] = "_expression",
  [sym_logical_expression] = "logical_expression",
  [sym_logical_operator] = "logical_operator",
  [sym_parenthesis_expression] = "parenthesis_expression",
  [sym_unary_expression] = "unary_expression",
  [sym_binary_expression] = "binary_expression",
  [sym_data_type] = "data_type",
  [sym_constant_expression] = "constant_expression",
  [sym_number] = "number",
  [sym_bool_literal] = "bool_literal",
  [sym__literal] = "_literal",
  [sym_date_and_time] = "date_and_time",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_program_repeat1] = "program_repeat1",
  [aux_sym_program_repeat2] = "program_repeat2",
  [aux_sym_configuration_repeat1] = "configuration_repeat1",
  [aux_sym_function_block_repeat1] = "function_block_repeat1",
  [aux_sym_var_block_repeat1] = "var_block_repeat1",
  [aux_sym_function_call_repeat1] = "function_call_repeat1",
  [aux_sym_if_statement_repeat1] = "if_statement_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_PROGRAM] = anon_sym_PROGRAM,
  [anon_sym_END_PROGRAM] = anon_sym_END_PROGRAM,
  [anon_sym_CONFIGURATION] = anon_sym_CONFIGURATION,
  [anon_sym_RESOURCE] = anon_sym_RESOURCE,
  [anon_sym_ON] = anon_sym_ON,
  [anon_sym_END_RESOURCE] = anon_sym_END_RESOURCE,
  [anon_sym_END_CONFIGURATION] = anon_sym_END_CONFIGURATION,
  [anon_sym_FUNCTION_BLOCK] = anon_sym_FUNCTION_BLOCK,
  [anon_sym_END_FUNCTION_BLOCK] = anon_sym_END_FUNCTION_BLOCK,
  [anon_sym_TASK] = anon_sym_TASK,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_INTERVAL] = anon_sym_INTERVAL,
  [anon_sym_COLON_EQ] = anon_sym_COLON_EQ,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_PRIORITY] = anon_sym_PRIORITY,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [anon_sym_WITH] = anon_sym_WITH,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_VAR] = anon_sym_VAR,
  [anon_sym_END_VAR] = anon_sym_END_VAR,
  [anon_sym_VAR_INPUT] = anon_sym_VAR_INPUT,
  [anon_sym_VAR_OUTPUT] = anon_sym_VAR_OUTPUT,
  [anon_sym_VAR_CONSTANT] = anon_sym_VAR_CONSTANT,
  [anon_sym_AT] = anon_sym_AT,
  [anon_sym_IF] = anon_sym_IF,
  [anon_sym_THEN] = anon_sym_THEN,
  [anon_sym_END_IF] = anon_sym_END_IF,
  [anon_sym_ELSIF] = anon_sym_ELSIF,
  [anon_sym_ELSE] = anon_sym_ELSE,
  [anon_sym_AND] = anon_sym_AND,
  [anon_sym_OR] = anon_sym_OR,
  [anon_sym_XOR] = anon_sym_XOR,
  [anon_sym_NOT] = anon_sym_NOT,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_STAR_STAR] = anon_sym_STAR_STAR,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [anon_sym_MOD] = anon_sym_MOD,
  [anon_sym_LT] = anon_sym_LT,
  [anon_sym_GT] = anon_sym_GT,
  [anon_sym_LT_EQ] = anon_sym_LT_EQ,
  [anon_sym_GT_EQ] = anon_sym_GT_EQ,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_LT_GT] = anon_sym_LT_GT,
  [anon_sym_BOOL] = anon_sym_BOOL,
  [anon_sym_REAL] = anon_sym_REAL,
  [anon_sym_INT] = anon_sym_INT,
  [sym_address] = sym_address,
  [sym_time_literal] = sym_time_literal,
  [aux_sym_number_token1] = aux_sym_number_token1,
  [aux_sym_number_token2] = aux_sym_number_token2,
  [anon_sym_TRUE] = anon_sym_TRUE,
  [anon_sym_FALSE] = anon_sym_FALSE,
  [sym_boolean] = sym_boolean,
  [sym_integer] = sym_integer,
  [sym_floating_point] = sym_floating_point,
  [sym_binary] = sym_binary,
  [sym_octal] = sym_octal,
  [sym_hexidecimal] = sym_hexidecimal,
  [sym_time] = sym_time,
  [sym_date] = sym_date,
  [sym_time_of_day] = sym_time_of_day,
  [anon_sym_DT_POUND] = anon_sym_DT_POUND,
  [aux_sym_date_and_time_token1] = aux_sym_date_and_time_token1,
  [aux_sym_date_and_time_token2] = aux_sym_date_and_time_token2,
  [aux_sym_date_and_time_token3] = aux_sym_date_and_time_token3,
  [sym_string] = sym_string,
  [sym_wstring] = sym_wstring,
  [sym_inline_comment] = sym_inline_comment,
  [sym_block_comment] = sym_block_comment,
  [sym_identifier] = sym_identifier,
  [sym_source_file] = sym_source_file,
  [sym_program] = sym_program,
  [sym_variable_block] = sym_variable_block,
  [sym_configuration] = sym_configuration,
  [sym_function_block] = sym_function_block,
  [sym__resource_element] = sym__resource_element,
  [sym_task] = sym_task,
  [sym_program_instance] = sym_program_instance,
  [sym_var_block] = sym_var_block,
  [sym_var_input_block] = sym_var_input_block,
  [sym_var_output_block] = sym_var_output_block,
  [sym_var_constant_block] = sym_var_constant_block,
  [sym_var_declaration] = sym_var_declaration,
  [sym__statement] = sym__statement,
  [sym_assignment] = sym_assignment,
  [sym_function_call] = sym_function_call,
  [sym_if_statement] = sym_if_statement,
  [sym_elsif_clause] = sym_elsif_clause,
  [sym_else_clause] = sym_else_clause,
  [sym__expression] = sym__expression,
  [sym_logical_expression] = sym_logical_expression,
  [sym_logical_operator] = sym_logical_operator,
  [sym_parenthesis_expression] = sym_parenthesis_expression,
  [sym_unary_expression] = sym_unary_expression,
  [sym_binary_expression] = sym_binary_expression,
  [sym_data_type] = sym_data_type,
  [sym_constant_expression] = sym_constant_expression,
  [sym_number] = sym_number,
  [sym_bool_literal] = sym_bool_literal,
  [sym__literal] = sym__literal,
  [sym_date_and_time] = sym_date_and_time,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_program_repeat1] = aux_sym_program_repeat1,
  [aux_sym_program_repeat2] = aux_sym_program_repeat2,
  [aux_sym_configuration_repeat1] = aux_sym_configuration_repeat1,
  [aux_sym_function_block_repeat1] = aux_sym_function_block_repeat1,
  [aux_sym_var_block_repeat1] = aux_sym_var_block_repeat1,
  [aux_sym_function_call_repeat1] = aux_sym_function_call_repeat1,
  [aux_sym_if_statement_repeat1] = aux_sym_if_statement_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_PROGRAM] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_END_PROGRAM] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_CONFIGURATION] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RESOURCE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_END_RESOURCE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_END_CONFIGURATION] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_FUNCTION_BLOCK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_END_FUNCTION_BLOCK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_TASK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_INTERVAL] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PRIORITY] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SEMI] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_WITH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_VAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_END_VAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_VAR_INPUT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_VAR_OUTPUT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_VAR_CONSTANT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_IF] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_THEN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_END_IF] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ELSIF] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ELSE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AND] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_OR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_XOR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_NOT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_MOD] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BOOL] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_REAL] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_INT] = {
    .visible = true,
    .named = false,
  },
  [sym_address] = {
    .visible = true,
    .named = true,
  },
  [sym_time_literal] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_number_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_number_token2] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_TRUE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_FALSE] = {
    .visible = true,
    .named = false,
  },
  [sym_boolean] = {
    .visible = true,
    .named = true,
  },
  [sym_integer] = {
    .visible = true,
    .named = true,
  },
  [sym_floating_point] = {
    .visible = true,
    .named = true,
  },
  [sym_binary] = {
    .visible = true,
    .named = true,
  },
  [sym_octal] = {
    .visible = true,
    .named = true,
  },
  [sym_hexidecimal] = {
    .visible = true,
    .named = true,
  },
  [sym_time] = {
    .visible = true,
    .named = true,
  },
  [sym_date] = {
    .visible = true,
    .named = true,
  },
  [sym_time_of_day] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_DT_POUND] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_date_and_time_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_date_and_time_token2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_date_and_time_token3] = {
    .visible = false,
    .named = false,
  },
  [sym_string] = {
    .visible = true,
    .named = true,
  },
  [sym_wstring] = {
    .visible = true,
    .named = true,
  },
  [sym_inline_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_block_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym_program] = {
    .visible = true,
    .named = true,
  },
  [sym_variable_block] = {
    .visible = true,
    .named = true,
  },
  [sym_configuration] = {
    .visible = true,
    .named = true,
  },
  [sym_function_block] = {
    .visible = true,
    .named = true,
  },
  [sym__resource_element] = {
    .visible = false,
    .named = true,
  },
  [sym_task] = {
    .visible = true,
    .named = true,
  },
  [sym_program_instance] = {
    .visible = true,
    .named = true,
  },
  [sym_var_block] = {
    .visible = true,
    .named = true,
  },
  [sym_var_input_block] = {
    .visible = true,
    .named = true,
  },
  [sym_var_output_block] = {
    .visible = true,
    .named = true,
  },
  [sym_var_constant_block] = {
    .visible = true,
    .named = true,
  },
  [sym_var_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym__statement] = {
    .visible = false,
    .named = true,
  },
  [sym_assignment] = {
    .visible = true,
    .named = true,
  },
  [sym_function_call] = {
    .visible = true,
    .named = true,
  },
  [sym_if_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_elsif_clause] = {
    .visible = true,
    .named = true,
  },
  [sym_else_clause] = {
    .visible = true,
    .named = true,
  },
  [sym__expression] = {
    .visible = false,
    .named = true,
  },
  [sym_logical_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_logical_operator] = {
    .visible = true,
    .named = true,
  },
  [sym_parenthesis_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_unary_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_binary_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_data_type] = {
    .visible = true,
    .named = true,
  },
  [sym_constant_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_number] = {
    .visible = true,
    .named = true,
  },
  [sym_bool_literal] = {
    .visible = true,
    .named = true,
  },
  [sym__literal] = {
    .visible = false,
    .named = true,
  },
  [sym_date_and_time] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_program_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_program_repeat2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_configuration_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_function_block_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_var_block_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_function_call_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_if_statement_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 2,
  [4] = 2,
  [5] = 2,
  [6] = 6,
  [7] = 7,
  [8] = 6,
  [9] = 9,
  [10] = 9,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 6,
  [18] = 18,
  [19] = 6,
  [20] = 9,
  [21] = 9,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 36,
  [38] = 36,
  [39] = 36,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 44,
  [45] = 44,
  [46] = 44,
  [47] = 44,
  [48] = 42,
  [49] = 42,
  [50] = 42,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 54,
  [56] = 56,
  [57] = 56,
  [58] = 54,
  [59] = 56,
  [60] = 60,
  [61] = 56,
  [62] = 54,
  [63] = 63,
  [64] = 64,
  [65] = 65,
  [66] = 66,
  [67] = 67,
  [68] = 68,
  [69] = 69,
  [70] = 70,
  [71] = 63,
  [72] = 72,
  [73] = 73,
  [74] = 74,
  [75] = 63,
  [76] = 63,
  [77] = 77,
  [78] = 78,
  [79] = 79,
  [80] = 80,
  [81] = 81,
  [82] = 82,
  [83] = 83,
  [84] = 84,
  [85] = 85,
  [86] = 86,
  [87] = 87,
  [88] = 88,
  [89] = 89,
  [90] = 90,
  [91] = 91,
  [92] = 92,
  [93] = 92,
  [94] = 94,
  [95] = 94,
  [96] = 94,
  [97] = 85,
  [98] = 80,
  [99] = 90,
  [100] = 86,
  [101] = 91,
  [102] = 92,
  [103] = 92,
  [104] = 94,
  [105] = 87,
  [106] = 106,
  [107] = 107,
  [108] = 108,
  [109] = 109,
  [110] = 110,
  [111] = 111,
  [112] = 112,
  [113] = 113,
  [114] = 114,
  [115] = 115,
  [116] = 116,
  [117] = 117,
  [118] = 118,
  [119] = 117,
  [120] = 120,
  [121] = 121,
  [122] = 115,
  [123] = 121,
  [124] = 124,
  [125] = 125,
  [126] = 126,
  [127] = 127,
  [128] = 128,
  [129] = 129,
  [130] = 130,
  [131] = 126,
  [132] = 132,
  [133] = 129,
  [134] = 130,
  [135] = 135,
  [136] = 136,
  [137] = 137,
  [138] = 138,
  [139] = 139,
  [140] = 140,
  [141] = 108,
  [142] = 110,
  [143] = 109,
  [144] = 106,
  [145] = 140,
  [146] = 146,
  [147] = 140,
  [148] = 108,
  [149] = 149,
  [150] = 113,
  [151] = 111,
  [152] = 152,
  [153] = 114,
  [154] = 154,
  [155] = 106,
  [156] = 110,
  [157] = 112,
  [158] = 108,
  [159] = 111,
  [160] = 111,
  [161] = 112,
  [162] = 114,
  [163] = 113,
  [164] = 106,
  [165] = 109,
  [166] = 110,
  [167] = 113,
  [168] = 109,
  [169] = 114,
  [170] = 140,
  [171] = 112,
  [172] = 172,
  [173] = 172,
  [174] = 174,
  [175] = 175,
  [176] = 176,
  [177] = 177,
  [178] = 178,
  [179] = 179,
  [180] = 172,
  [181] = 181,
  [182] = 172,
  [183] = 183,
  [184] = 184,
  [185] = 185,
  [186] = 186,
  [187] = 187,
  [188] = 188,
  [189] = 189,
  [190] = 190,
  [191] = 191,
  [192] = 192,
  [193] = 193,
  [194] = 194,
  [195] = 189,
  [196] = 196,
  [197] = 191,
  [198] = 198,
  [199] = 199,
  [200] = 200,
  [201] = 201,
  [202] = 202,
  [203] = 189,
  [204] = 204,
  [205] = 191,
  [206] = 198,
  [207] = 199,
  [208] = 208,
  [209] = 209,
  [210] = 210,
  [211] = 189,
  [212] = 212,
  [213] = 191,
  [214] = 198,
  [215] = 199,
  [216] = 216,
  [217] = 217,
  [218] = 218,
  [219] = 190,
  [220] = 220,
  [221] = 221,
  [222] = 193,
  [223] = 223,
  [224] = 224,
  [225] = 225,
  [226] = 226,
  [227] = 227,
  [228] = 190,
  [229] = 199,
  [230] = 230,
  [231] = 193,
  [232] = 232,
  [233] = 224,
  [234] = 234,
  [235] = 235,
  [236] = 236,
  [237] = 190,
  [238] = 238,
  [239] = 239,
  [240] = 193,
  [241] = 224,
  [242] = 224,
  [243] = 198,
  [244] = 244,
  [245] = 245,
  [246] = 246,
  [247] = 247,
  [248] = 248,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(274);
      if (lookahead == '"') ADVANCE(2);
      if (lookahead == '%') ADVANCE(273);
      if (lookahead == '\'') ADVANCE(10);
      if (lookahead == '(') ADVANCE(288);
      if (lookahead == ')') ADVANCE(293);
      if (lookahead == '*') ADVANCE(330);
      if (lookahead == '+') ADVANCE(327);
      if (lookahead == ',') ADVANCE(291);
      if (lookahead == '-') ADVANCE(328);
      if (lookahead == '/') ADVANCE(332);
      if (lookahead == '1') ADVANCE(350);
      if (lookahead == '2') ADVANCE(347);
      if (lookahead == '8') ADVANCE(348);
      if (lookahead == ':') ADVANCE(297);
      if (lookahead == ';') ADVANCE(294);
      if (lookahead == '<') ADVANCE(334);
      if (lookahead == '=') ADVANCE(338);
      if (lookahead == '>') ADVANCE(335);
      if (lookahead == 'A') ADVANCE(140);
      if (lookahead == 'B') ADVANCE(166);
      if (lookahead == 'C') ADVANCE(156);
      if (lookahead == 'D') ADVANCE(3);
      if (lookahead == 'E') ADVANCE(94);
      if (lookahead == 'F') ADVANCE(31);
      if (lookahead == 'I') ADVANCE(72);
      if (lookahead == 'M') ADVANCE(161);
      if (lookahead == 'N') ADVANCE(158);
      if (lookahead == 'O') ADVANCE(141);
      if (lookahead == 'P') ADVANCE(177);
      if (lookahead == 'R') ADVANCE(56);
      if (lookahead == 'T') ADVANCE(4);
      if (lookahead == 'V') ADVANCE(33);
      if (lookahead == 'W') ADVANCE(83);
      if (lookahead == 'X') ADVANCE(160);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(351);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(2);
      if (lookahead == '\'') ADVANCE(10);
      if (lookahead == '(') ADVANCE(287);
      if (lookahead == ')') ADVANCE(293);
      if (lookahead == '+') ADVANCE(327);
      if (lookahead == '-') ADVANCE(328);
      if (lookahead == '1') ADVANCE(362);
      if (lookahead == '2') ADVANCE(359);
      if (lookahead == '8') ADVANCE(360);
      if (lookahead == ':') ADVANCE(29);
      if (lookahead == ';') ADVANCE(294);
      if (lookahead == 'A') ADVANCE(438);
      if (lookahead == 'D') ADVANCE(403);
      if (lookahead == 'F') ADVANCE(407);
      if (lookahead == 'N') ADVANCE(448);
      if (lookahead == 'O') ADVANCE(457);
      if (lookahead == 'T') ADVANCE(406);
      if (lookahead == 'X') ADVANCE(450);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(1)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(368);
      if (('B' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(400);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(2);
      END_STATE();
    case 3:
      if (lookahead == '#') ADVANCE(242);
      if (lookahead == 'T') ADVANCE(5);
      END_STATE();
    case 4:
      if (lookahead == '#') ADVANCE(375);
      if (lookahead == 'A') ADVANCE(191);
      if (lookahead == 'H') ADVANCE(63);
      if (lookahead == 'O') ADVANCE(55);
      if (lookahead == 'R') ADVANCE(211);
      END_STATE();
    case 5:
      if (lookahead == '#') ADVANCE(391);
      END_STATE();
    case 6:
      if (lookahead == '#') ADVANCE(246);
      END_STATE();
    case 7:
      if (lookahead == '#') ADVANCE(257);
      if (lookahead == 'H') ADVANCE(63);
      END_STATE();
    case 8:
      if (lookahead == '#') ADVANCE(257);
      if (lookahead == 'R') ADVANCE(211);
      END_STATE();
    case 9:
      if (lookahead == '%') ADVANCE(273);
      if (lookahead == '-') ADVANCE(266);
      if (lookahead == 'F') ADVANCE(30);
      if (lookahead == 'I') ADVANCE(152);
      if (lookahead == 'T') ADVANCE(8);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(9)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(355);
      END_STATE();
    case 10:
      if (lookahead == '\'') ADVANCE(399);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(10);
      END_STATE();
    case 11:
      if (lookahead == ')') ADVANCE(293);
      if (lookahead == '*') ADVANCE(330);
      if (lookahead == '+') ADVANCE(327);
      if (lookahead == ',') ADVANCE(291);
      if (lookahead == '-') ADVANCE(328);
      if (lookahead == '/') ADVANCE(331);
      if (lookahead == ':') ADVANCE(296);
      if (lookahead == ';') ADVANCE(294);
      if (lookahead == '<') ADVANCE(334);
      if (lookahead == '=') ADVANCE(338);
      if (lookahead == '>') ADVANCE(335);
      if (lookahead == 'A') ADVANCE(140);
      if (lookahead == 'B') ADVANCE(166);
      if (lookahead == 'I') ADVANCE(151);
      if (lookahead == 'M') ADVANCE(161);
      if (lookahead == 'O') ADVANCE(176);
      if (lookahead == 'R') ADVANCE(67);
      if (lookahead == 'T') ADVANCE(7);
      if (lookahead == 'X') ADVANCE(160);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(11)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(233);
      END_STATE();
    case 12:
      if (lookahead == ')') ADVANCE(402);
      if (lookahead == '*') ADVANCE(12);
      if (lookahead != 0) ADVANCE(13);
      END_STATE();
    case 13:
      if (lookahead == '*') ADVANCE(12);
      if (lookahead != 0) ADVANCE(13);
      END_STATE();
    case 14:
      if (lookahead == '-') ADVANCE(250);
      END_STATE();
    case 15:
      if (lookahead == '-') ADVANCE(253);
      END_STATE();
    case 16:
      if (lookahead == '-') ADVANCE(253);
      if (lookahead == '_') ADVANCE(268);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(15);
      END_STATE();
    case 17:
      if (lookahead == '-') ADVANCE(259);
      if (lookahead == 'E') ADVANCE(442);
      if (lookahead == 'I') ADVANCE(425);
      if (lookahead == 'V') ADVANCE(409);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(17)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(355);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 18:
      if (lookahead == '-') ADVANCE(261);
      END_STATE();
    case 19:
      if (lookahead == '-') ADVANCE(261);
      if (lookahead == '_') ADVANCE(271);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(18);
      END_STATE();
    case 20:
      if (lookahead == '-') ADVANCE(269);
      END_STATE();
    case 21:
      if (lookahead == '-') ADVANCE(269);
      if (lookahead == '.') ADVANCE(260);
      if (lookahead == '_') ADVANCE(272);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(22);
      END_STATE();
    case 22:
      if (lookahead == '-') ADVANCE(269);
      if (lookahead == '.') ADVANCE(260);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(26);
      END_STATE();
    case 23:
      if (lookahead == '.') ADVANCE(244);
      END_STATE();
    case 24:
      if (lookahead == '.') ADVANCE(244);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(23);
      END_STATE();
    case 25:
      if (lookahead == '.') ADVANCE(244);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(24);
      END_STATE();
    case 26:
      if (lookahead == '.') ADVANCE(260);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(26);
      END_STATE();
    case 27:
      if (lookahead == ':') ADVANCE(249);
      END_STATE();
    case 28:
      if (lookahead == ':') ADVANCE(249);
      if (lookahead == '_') ADVANCE(248);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(27);
      END_STATE();
    case 29:
      if (lookahead == '=') ADVANCE(290);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(397);
      END_STATE();
    case 30:
      if (lookahead == 'A') ADVANCE(98);
      END_STATE();
    case 31:
      if (lookahead == 'A') ADVANCE(98);
      if (lookahead == 'U') ADVANCE(143);
      END_STATE();
    case 32:
      if (lookahead == 'A') ADVANCE(116);
      END_STATE();
    case 33:
      if (lookahead == 'A') ADVANCE(178);
      END_STATE();
    case 34:
      if (lookahead == 'A') ADVANCE(117);
      END_STATE();
    case 35:
      if (lookahead == 'A') ADVANCE(96);
      END_STATE();
    case 36:
      if (lookahead == 'A') ADVANCE(96);
      if (lookahead == 'S') ADVANCE(159);
      END_STATE();
    case 37:
      if (lookahead == 'A') ADVANCE(97);
      END_STATE();
    case 38:
      if (lookahead == 'A') ADVANCE(150);
      END_STATE();
    case 39:
      if (lookahead == 'A') ADVANCE(181);
      END_STATE();
    case 40:
      if (lookahead == 'A') ADVANCE(207);
      END_STATE();
    case 41:
      if (lookahead == 'A') ADVANCE(208);
      END_STATE();
    case 42:
      if (lookahead == 'B') ADVANCE(99);
      END_STATE();
    case 43:
      if (lookahead == 'B') ADVANCE(100);
      END_STATE();
    case 44:
      if (lookahead == 'C') ADVANCE(92);
      END_STATE();
    case 45:
      if (lookahead == 'C') ADVANCE(93);
      END_STATE();
    case 46:
      if (lookahead == 'C') ADVANCE(204);
      END_STATE();
    case 47:
      if (lookahead == 'C') ADVANCE(60);
      END_STATE();
    case 48:
      if (lookahead == 'C') ADVANCE(61);
      END_STATE();
    case 49:
      if (lookahead == 'C') ADVANCE(165);
      if (lookahead == 'I') ADVANCE(145);
      if (lookahead == 'O') ADVANCE(212);
      END_STATE();
    case 50:
      if (lookahead == 'C') ADVANCE(210);
      END_STATE();
    case 51:
      if (lookahead == 'C') ADVANCE(173);
      if (lookahead == 'F') ADVANCE(219);
      if (lookahead == 'I') ADVANCE(74);
      if (lookahead == 'P') ADVANCE(186);
      if (lookahead == 'R') ADVANCE(65);
      if (lookahead == 'V') ADVANCE(39);
      END_STATE();
    case 52:
      if (lookahead == 'D') ADVANCE(319);
      END_STATE();
    case 53:
      if (lookahead == 'D') ADVANCE(225);
      END_STATE();
    case 54:
      if (lookahead == 'D') ADVANCE(333);
      END_STATE();
    case 55:
      if (lookahead == 'D') ADVANCE(6);
      END_STATE();
    case 56:
      if (lookahead == 'E') ADVANCE(36);
      END_STATE();
    case 57:
      if (lookahead == 'E') ADVANCE(317);
      if (lookahead == 'I') ADVANCE(73);
      END_STATE();
    case 58:
      if (lookahead == 'E') ADVANCE(356);
      END_STATE();
    case 59:
      if (lookahead == 'E') ADVANCE(357);
      END_STATE();
    case 60:
      if (lookahead == 'E') ADVANCE(279);
      END_STATE();
    case 61:
      if (lookahead == 'E') ADVANCE(281);
      END_STATE();
    case 62:
      if (lookahead == 'E') ADVANCE(435);
      if (lookahead == 'I') ADVANCE(425);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(62)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 63:
      if (lookahead == 'E') ADVANCE(144);
      END_STATE();
    case 64:
      if (lookahead == 'E') ADVANCE(180);
      END_STATE();
    case 65:
      if (lookahead == 'E') ADVANCE(195);
      END_STATE();
    case 66:
      if (lookahead == 'E') ADVANCE(442);
      if (lookahead == 'I') ADVANCE(425);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(66)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 67:
      if (lookahead == 'E') ADVANCE(35);
      END_STATE();
    case 68:
      if (lookahead == 'E') ADVANCE(444);
      if (lookahead == 'I') ADVANCE(425);
      if (lookahead == 'V') ADVANCE(411);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(68)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 69:
      if (lookahead == 'E') ADVANCE(444);
      if (lookahead == 'I') ADVANCE(425);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(69)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 70:
      if (lookahead == 'E') ADVANCE(445);
      if (lookahead == 'I') ADVANCE(425);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(70)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 71:
      if (lookahead == 'E') ADVANCE(446);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(71)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 72:
      if (lookahead == 'F') ADVANCE(310);
      if (lookahead == 'N') ADVANCE(196);
      END_STATE();
    case 73:
      if (lookahead == 'F') ADVANCE(315);
      END_STATE();
    case 74:
      if (lookahead == 'F') ADVANCE(313);
      END_STATE();
    case 75:
      if (lookahead == 'F') ADVANCE(82);
      END_STATE();
    case 76:
      if (lookahead == 'F') ADVANCE(90);
      END_STATE();
    case 77:
      if (lookahead == 'G') ADVANCE(182);
      END_STATE();
    case 78:
      if (lookahead == 'G') ADVANCE(185);
      END_STATE();
    case 79:
      if (lookahead == 'G') ADVANCE(216);
      END_STATE();
    case 80:
      if (lookahead == 'G') ADVANCE(218);
      END_STATE();
    case 81:
      if (lookahead == 'H') ADVANCE(295);
      END_STATE();
    case 82:
      if (lookahead == 'I') ADVANCE(79);
      END_STATE();
    case 83:
      if (lookahead == 'I') ADVANCE(198);
      END_STATE();
    case 84:
      if (lookahead == 'I') ADVANCE(199);
      END_STATE();
    case 85:
      if (lookahead == 'I') ADVANCE(164);
      if (lookahead == 'O') ADVANCE(77);
      END_STATE();
    case 86:
      if (lookahead == 'I') ADVANCE(167);
      END_STATE();
    case 87:
      if (lookahead == 'I') ADVANCE(168);
      END_STATE();
    case 88:
      if (lookahead == 'I') ADVANCE(169);
      END_STATE();
    case 89:
      if (lookahead == 'I') ADVANCE(172);
      END_STATE();
    case 90:
      if (lookahead == 'I') ADVANCE(80);
      END_STATE();
    case 91:
      if (lookahead == 'K') ADVANCE(286);
      END_STATE();
    case 92:
      if (lookahead == 'K') ADVANCE(283);
      END_STATE();
    case 93:
      if (lookahead == 'K') ADVANCE(284);
      END_STATE();
    case 94:
      if (lookahead == 'L') ADVANCE(190);
      if (lookahead == 'N') ADVANCE(53);
      END_STATE();
    case 95:
      if (lookahead == 'L') ADVANCE(340);
      END_STATE();
    case 96:
      if (lookahead == 'L') ADVANCE(341);
      END_STATE();
    case 97:
      if (lookahead == 'L') ADVANCE(289);
      END_STATE();
    case 98:
      if (lookahead == 'L') ADVANCE(193);
      END_STATE();
    case 99:
      if (lookahead == 'L') ADVANCE(162);
      END_STATE();
    case 100:
      if (lookahead == 'L') ADVANCE(163);
      END_STATE();
    case 101:
      if (lookahead == 'M') ADVANCE(377);
      if (lookahead == 'm') ADVANCE(379);
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(380);
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(382);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(381);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(102);
      END_STATE();
    case 102:
      if (lookahead == 'M') ADVANCE(377);
      if (lookahead == 'm') ADVANCE(379);
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(380);
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(382);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(381);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(103);
      END_STATE();
    case 103:
      if (lookahead == 'M') ADVANCE(377);
      if (lookahead == 'm') ADVANCE(379);
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(382);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(381);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(104);
      END_STATE();
    case 104:
      if (lookahead == 'M') ADVANCE(377);
      if (lookahead == 'm') ADVANCE(379);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(381);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(105);
      END_STATE();
    case 105:
      if (lookahead == 'M') ADVANCE(377);
      if (lookahead == 'm') ADVANCE(379);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(381);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      END_STATE();
    case 106:
      if (lookahead == 'M') ADVANCE(377);
      if (lookahead == 'm') ADVANCE(378);
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(380);
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(382);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(381);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(107);
      END_STATE();
    case 107:
      if (lookahead == 'M') ADVANCE(377);
      if (lookahead == 'm') ADVANCE(378);
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(380);
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(382);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(381);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(110);
      END_STATE();
    case 108:
      if (lookahead == 'M') ADVANCE(377);
      if (lookahead == 'm') ADVANCE(378);
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(382);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(381);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(110);
      END_STATE();
    case 109:
      if (lookahead == 'M') ADVANCE(377);
      if (lookahead == 'm') ADVANCE(378);
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(382);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(381);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(108);
      END_STATE();
    case 110:
      if (lookahead == 'M') ADVANCE(377);
      if (lookahead == 'm') ADVANCE(378);
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(382);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(381);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(111);
      END_STATE();
    case 111:
      if (lookahead == 'M') ADVANCE(377);
      if (lookahead == 'm') ADVANCE(378);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(381);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(113);
      END_STATE();
    case 112:
      if (lookahead == 'M') ADVANCE(377);
      if (lookahead == 'm') ADVANCE(378);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(381);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(111);
      END_STATE();
    case 113:
      if (lookahead == 'M') ADVANCE(377);
      if (lookahead == 'm') ADVANCE(378);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(381);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(122);
      END_STATE();
    case 114:
      if (lookahead == 'M') ADVANCE(377);
      if (lookahead == 'm') ADVANCE(378);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(381);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(112);
      END_STATE();
    case 115:
      if (lookahead == 'M') ADVANCE(377);
      if (lookahead == 'm') ADVANCE(378);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(381);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(114);
      END_STATE();
    case 116:
      if (lookahead == 'M') ADVANCE(275);
      END_STATE();
    case 117:
      if (lookahead == 'M') ADVANCE(276);
      END_STATE();
    case 118:
      if (lookahead == 'M') ADVANCE(192);
      if (lookahead == 'm') ADVANCE(235);
      END_STATE();
    case 119:
      if (lookahead == 'M') ADVANCE(192);
      if (lookahead == 'm') ADVANCE(235);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(381);
      END_STATE();
    case 120:
      if (lookahead == 'M') ADVANCE(192);
      if (lookahead == 'm') ADVANCE(235);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(381);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(119);
      END_STATE();
    case 121:
      if (lookahead == 'M') ADVANCE(192);
      if (lookahead == 'm') ADVANCE(235);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(381);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(120);
      END_STATE();
    case 122:
      if (lookahead == 'M') ADVANCE(192);
      if (lookahead == 'm') ADVANCE(235);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(381);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(121);
      END_STATE();
    case 123:
      if (lookahead == 'M') ADVANCE(192);
      if (lookahead == 'm') ADVANCE(235);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(381);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(122);
      END_STATE();
    case 124:
      if (lookahead == 'M') ADVANCE(192);
      if (lookahead == 'm') ADVANCE(235);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(381);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(123);
      END_STATE();
    case 125:
      if (lookahead == 'M') ADVANCE(192);
      if (lookahead == 'm') ADVANCE(235);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(381);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(124);
      END_STATE();
    case 126:
      if (lookahead == 'M') ADVANCE(192);
      if (lookahead == 'm') ADVANCE(235);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(381);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(125);
      END_STATE();
    case 127:
      if (lookahead == 'M') ADVANCE(192);
      if (lookahead == 'm') ADVANCE(235);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(381);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(126);
      END_STATE();
    case 128:
      if (lookahead == 'M') ADVANCE(192);
      if (lookahead == 'm') ADVANCE(235);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(118);
      END_STATE();
    case 129:
      if (lookahead == 'M') ADVANCE(192);
      if (lookahead == 'm') ADVANCE(235);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(128);
      END_STATE();
    case 130:
      if (lookahead == 'M') ADVANCE(192);
      if (lookahead == 'm') ADVANCE(235);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(129);
      END_STATE();
    case 131:
      if (lookahead == 'M') ADVANCE(192);
      if (lookahead == 'm') ADVANCE(235);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(130);
      END_STATE();
    case 132:
      if (lookahead == 'M') ADVANCE(192);
      if (lookahead == 'm') ADVANCE(235);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(131);
      END_STATE();
    case 133:
      if (lookahead == 'M') ADVANCE(192);
      if (lookahead == 'm') ADVANCE(235);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(132);
      END_STATE();
    case 134:
      if (lookahead == 'M') ADVANCE(192);
      if (lookahead == 'm') ADVANCE(235);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(133);
      END_STATE();
    case 135:
      if (lookahead == 'M') ADVANCE(192);
      if (lookahead == 'm') ADVANCE(235);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(134);
      END_STATE();
    case 136:
      if (lookahead == 'M') ADVANCE(192);
      if (lookahead == 'm') ADVANCE(236);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(381);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(234);
      END_STATE();
    case 137:
      if (lookahead == 'M') ADVANCE(192);
      if (lookahead == 'm') ADVANCE(236);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(381);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(136);
      END_STATE();
    case 138:
      if (lookahead == 'M') ADVANCE(192);
      if (lookahead == 'm') ADVANCE(236);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(381);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(137);
      END_STATE();
    case 139:
      if (lookahead == 'M') ADVANCE(192);
      if (lookahead == 'm') ADVANCE(236);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(381);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      END_STATE();
    case 140:
      if (lookahead == 'N') ADVANCE(52);
      if (lookahead == 'T') ADVANCE(309);
      END_STATE();
    case 141:
      if (lookahead == 'N') ADVANCE(280);
      if (lookahead == 'R') ADVANCE(321);
      END_STATE();
    case 142:
      if (lookahead == 'N') ADVANCE(75);
      END_STATE();
    case 143:
      if (lookahead == 'N') ADVANCE(46);
      END_STATE();
    case 144:
      if (lookahead == 'N') ADVANCE(312);
      END_STATE();
    case 145:
      if (lookahead == 'N') ADVANCE(174);
      END_STATE();
    case 146:
      if (lookahead == 'N') ADVANCE(278);
      END_STATE();
    case 147:
      if (lookahead == 'N') ADVANCE(282);
      END_STATE();
    case 148:
      if (lookahead == 'N') ADVANCE(226);
      END_STATE();
    case 149:
      if (lookahead == 'N') ADVANCE(194);
      END_STATE();
    case 150:
      if (lookahead == 'N') ADVANCE(202);
      END_STATE();
    case 151:
      if (lookahead == 'N') ADVANCE(203);
      END_STATE();
    case 152:
      if (lookahead == 'N') ADVANCE(206);
      END_STATE();
    case 153:
      if (lookahead == 'N') ADVANCE(232);
      END_STATE();
    case 154:
      if (lookahead == 'N') ADVANCE(50);
      END_STATE();
    case 155:
      if (lookahead == 'N') ADVANCE(76);
      END_STATE();
    case 156:
      if (lookahead == 'O') ADVANCE(142);
      END_STATE();
    case 157:
      if (lookahead == 'O') ADVANCE(95);
      END_STATE();
    case 158:
      if (lookahead == 'O') ADVANCE(197);
      END_STATE();
    case 159:
      if (lookahead == 'O') ADVANCE(213);
      END_STATE();
    case 160:
      if (lookahead == 'O') ADVANCE(179);
      END_STATE();
    case 161:
      if (lookahead == 'O') ADVANCE(54);
      END_STATE();
    case 162:
      if (lookahead == 'O') ADVANCE(44);
      END_STATE();
    case 163:
      if (lookahead == 'O') ADVANCE(45);
      END_STATE();
    case 164:
      if (lookahead == 'O') ADVANCE(187);
      END_STATE();
    case 165:
      if (lookahead == 'O') ADVANCE(149);
      END_STATE();
    case 166:
      if (lookahead == 'O') ADVANCE(157);
      END_STATE();
    case 167:
      if (lookahead == 'O') ADVANCE(148);
      END_STATE();
    case 168:
      if (lookahead == 'O') ADVANCE(146);
      END_STATE();
    case 169:
      if (lookahead == 'O') ADVANCE(147);
      END_STATE();
    case 170:
      if (lookahead == 'O') ADVANCE(78);
      END_STATE();
    case 171:
      if (lookahead == 'O') ADVANCE(217);
      END_STATE();
    case 172:
      if (lookahead == 'O') ADVANCE(153);
      END_STATE();
    case 173:
      if (lookahead == 'O') ADVANCE(155);
      END_STATE();
    case 174:
      if (lookahead == 'P') ADVANCE(214);
      END_STATE();
    case 175:
      if (lookahead == 'P') ADVANCE(215);
      END_STATE();
    case 176:
      if (lookahead == 'R') ADVANCE(321);
      END_STATE();
    case 177:
      if (lookahead == 'R') ADVANCE(85);
      END_STATE();
    case 178:
      if (lookahead == 'R') ADVANCE(298);
      END_STATE();
    case 179:
      if (lookahead == 'R') ADVANCE(323);
      END_STATE();
    case 180:
      if (lookahead == 'R') ADVANCE(220);
      END_STATE();
    case 181:
      if (lookahead == 'R') ADVANCE(301);
      END_STATE();
    case 182:
      if (lookahead == 'R') ADVANCE(32);
      END_STATE();
    case 183:
      if (lookahead == 'R') ADVANCE(47);
      END_STATE();
    case 184:
      if (lookahead == 'R') ADVANCE(40);
      END_STATE();
    case 185:
      if (lookahead == 'R') ADVANCE(34);
      END_STATE();
    case 186:
      if (lookahead == 'R') ADVANCE(170);
      END_STATE();
    case 187:
      if (lookahead == 'R') ADVANCE(84);
      END_STATE();
    case 188:
      if (lookahead == 'R') ADVANCE(48);
      END_STATE();
    case 189:
      if (lookahead == 'R') ADVANCE(41);
      END_STATE();
    case 190:
      if (lookahead == 'S') ADVANCE(57);
      END_STATE();
    case 191:
      if (lookahead == 'S') ADVANCE(91);
      END_STATE();
    case 192:
      if (lookahead == 'S') ADVANCE(374);
      END_STATE();
    case 193:
      if (lookahead == 'S') ADVANCE(59);
      END_STATE();
    case 194:
      if (lookahead == 'S') ADVANCE(205);
      END_STATE();
    case 195:
      if (lookahead == 'S') ADVANCE(171);
      END_STATE();
    case 196:
      if (lookahead == 'T') ADVANCE(343);
      END_STATE();
    case 197:
      if (lookahead == 'T') ADVANCE(325);
      END_STATE();
    case 198:
      if (lookahead == 'T') ADVANCE(81);
      END_STATE();
    case 199:
      if (lookahead == 'T') ADVANCE(221);
      END_STATE();
    case 200:
      if (lookahead == 'T') ADVANCE(303);
      END_STATE();
    case 201:
      if (lookahead == 'T') ADVANCE(305);
      END_STATE();
    case 202:
      if (lookahead == 'T') ADVANCE(307);
      END_STATE();
    case 203:
      if (lookahead == 'T') ADVANCE(342);
      END_STATE();
    case 204:
      if (lookahead == 'T') ADVANCE(86);
      END_STATE();
    case 205:
      if (lookahead == 'T') ADVANCE(38);
      END_STATE();
    case 206:
      if (lookahead == 'T') ADVANCE(64);
      END_STATE();
    case 207:
      if (lookahead == 'T') ADVANCE(87);
      END_STATE();
    case 208:
      if (lookahead == 'T') ADVANCE(88);
      END_STATE();
    case 209:
      if (lookahead == 'T') ADVANCE(175);
      END_STATE();
    case 210:
      if (lookahead == 'T') ADVANCE(89);
      END_STATE();
    case 211:
      if (lookahead == 'U') ADVANCE(58);
      END_STATE();
    case 212:
      if (lookahead == 'U') ADVANCE(209);
      END_STATE();
    case 213:
      if (lookahead == 'U') ADVANCE(183);
      END_STATE();
    case 214:
      if (lookahead == 'U') ADVANCE(200);
      END_STATE();
    case 215:
      if (lookahead == 'U') ADVANCE(201);
      END_STATE();
    case 216:
      if (lookahead == 'U') ADVANCE(184);
      END_STATE();
    case 217:
      if (lookahead == 'U') ADVANCE(188);
      END_STATE();
    case 218:
      if (lookahead == 'U') ADVANCE(189);
      END_STATE();
    case 219:
      if (lookahead == 'U') ADVANCE(154);
      END_STATE();
    case 220:
      if (lookahead == 'V') ADVANCE(37);
      END_STATE();
    case 221:
      if (lookahead == 'Y') ADVANCE(292);
      END_STATE();
    case 222:
      if (lookahead == '_') ADVANCE(222);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(371);
      END_STATE();
    case 223:
      if (lookahead == '_') ADVANCE(223);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(372);
      END_STATE();
    case 224:
      if (lookahead == '_') ADVANCE(224);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(373);
      END_STATE();
    case 225:
      if (lookahead == '_') ADVANCE(51);
      END_STATE();
    case 226:
      if (lookahead == '_') ADVANCE(42);
      END_STATE();
    case 227:
      if (lookahead == '_') ADVANCE(247);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(14);
      END_STATE();
    case 228:
      if (lookahead == '_') ADVANCE(258);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(392);
      END_STATE();
    case 229:
      if (lookahead == '_') ADVANCE(264);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(227);
      END_STATE();
    case 230:
      if (lookahead == '_') ADVANCE(265);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(228);
      END_STATE();
    case 231:
      if (lookahead == '_') ADVANCE(267);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(229);
      END_STATE();
    case 232:
      if (lookahead == '_') ADVANCE(43);
      END_STATE();
    case 233:
      if (lookahead == '_') ADVANCE(270);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(230);
      END_STATE();
    case 234:
      if (lookahead == 'm') ADVANCE(236);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(234);
      END_STATE();
    case 235:
      if (lookahead == 's') ADVANCE(374);
      END_STATE();
    case 236:
      if (lookahead == 's') ADVANCE(345);
      END_STATE();
    case 237:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(240);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(370);
      END_STATE();
    case 238:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(238)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 239:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(25);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(263);
      END_STATE();
    case 240:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(370);
      END_STATE();
    case 241:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(396);
      END_STATE();
    case 242:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(231);
      END_STATE();
    case 243:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(398);
      END_STATE();
    case 244:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(344);
      END_STATE();
    case 245:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(395);
      END_STATE();
    case 246:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(28);
      END_STATE();
    case 247:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(14);
      END_STATE();
    case 248:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(27);
      END_STATE();
    case 249:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(389);
      END_STATE();
    case 250:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(16);
      END_STATE();
    case 251:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(388);
      END_STATE();
    case 252:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(387);
      END_STATE();
    case 253:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(385);
      END_STATE();
    case 254:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(386);
      END_STATE();
    case 255:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(384);
      END_STATE();
    case 256:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(390);
      END_STATE();
    case 257:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(234);
      END_STATE();
    case 258:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(392);
      END_STATE();
    case 259:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(21);
      END_STATE();
    case 260:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(346);
      END_STATE();
    case 261:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(394);
      END_STATE();
    case 262:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(393);
      END_STATE();
    case 263:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(24);
      END_STATE();
    case 264:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(227);
      END_STATE();
    case 265:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(228);
      END_STATE();
    case 266:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(26);
      END_STATE();
    case 267:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(229);
      END_STATE();
    case 268:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(15);
      END_STATE();
    case 269:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(19);
      END_STATE();
    case 270:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(230);
      END_STATE();
    case 271:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(18);
      END_STATE();
    case 272:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(20);
      END_STATE();
    case 273:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(239);
      END_STATE();
    case 274:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 275:
      ACCEPT_TOKEN(anon_sym_PROGRAM);
      END_STATE();
    case 276:
      ACCEPT_TOKEN(anon_sym_END_PROGRAM);
      END_STATE();
    case 277:
      ACCEPT_TOKEN(anon_sym_END_PROGRAM);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 278:
      ACCEPT_TOKEN(anon_sym_CONFIGURATION);
      END_STATE();
    case 279:
      ACCEPT_TOKEN(anon_sym_RESOURCE);
      END_STATE();
    case 280:
      ACCEPT_TOKEN(anon_sym_ON);
      END_STATE();
    case 281:
      ACCEPT_TOKEN(anon_sym_END_RESOURCE);
      END_STATE();
    case 282:
      ACCEPT_TOKEN(anon_sym_END_CONFIGURATION);
      END_STATE();
    case 283:
      ACCEPT_TOKEN(anon_sym_FUNCTION_BLOCK);
      END_STATE();
    case 284:
      ACCEPT_TOKEN(anon_sym_END_FUNCTION_BLOCK);
      END_STATE();
    case 285:
      ACCEPT_TOKEN(anon_sym_END_FUNCTION_BLOCK);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 286:
      ACCEPT_TOKEN(anon_sym_TASK);
      END_STATE();
    case 287:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 288:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      if (lookahead == '*') ADVANCE(13);
      END_STATE();
    case 289:
      ACCEPT_TOKEN(anon_sym_INTERVAL);
      END_STATE();
    case 290:
      ACCEPT_TOKEN(anon_sym_COLON_EQ);
      END_STATE();
    case 291:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 292:
      ACCEPT_TOKEN(anon_sym_PRIORITY);
      END_STATE();
    case 293:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 294:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 295:
      ACCEPT_TOKEN(anon_sym_WITH);
      END_STATE();
    case 296:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 297:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead == '=') ADVANCE(290);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(397);
      END_STATE();
    case 298:
      ACCEPT_TOKEN(anon_sym_VAR);
      if (lookahead == '_') ADVANCE(49);
      END_STATE();
    case 299:
      ACCEPT_TOKEN(anon_sym_VAR);
      if (lookahead == '_') ADVANCE(415);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 300:
      ACCEPT_TOKEN(anon_sym_VAR);
      if (lookahead == '_') ADVANCE(430);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 301:
      ACCEPT_TOKEN(anon_sym_END_VAR);
      END_STATE();
    case 302:
      ACCEPT_TOKEN(anon_sym_END_VAR);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 303:
      ACCEPT_TOKEN(anon_sym_VAR_INPUT);
      END_STATE();
    case 304:
      ACCEPT_TOKEN(anon_sym_VAR_INPUT);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 305:
      ACCEPT_TOKEN(anon_sym_VAR_OUTPUT);
      END_STATE();
    case 306:
      ACCEPT_TOKEN(anon_sym_VAR_OUTPUT);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 307:
      ACCEPT_TOKEN(anon_sym_VAR_CONSTANT);
      END_STATE();
    case 308:
      ACCEPT_TOKEN(anon_sym_VAR_CONSTANT);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 309:
      ACCEPT_TOKEN(anon_sym_AT);
      END_STATE();
    case 310:
      ACCEPT_TOKEN(anon_sym_IF);
      END_STATE();
    case 311:
      ACCEPT_TOKEN(anon_sym_IF);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 312:
      ACCEPT_TOKEN(anon_sym_THEN);
      END_STATE();
    case 313:
      ACCEPT_TOKEN(anon_sym_END_IF);
      END_STATE();
    case 314:
      ACCEPT_TOKEN(anon_sym_END_IF);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 315:
      ACCEPT_TOKEN(anon_sym_ELSIF);
      END_STATE();
    case 316:
      ACCEPT_TOKEN(anon_sym_ELSIF);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 317:
      ACCEPT_TOKEN(anon_sym_ELSE);
      END_STATE();
    case 318:
      ACCEPT_TOKEN(anon_sym_ELSE);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 319:
      ACCEPT_TOKEN(anon_sym_AND);
      END_STATE();
    case 320:
      ACCEPT_TOKEN(anon_sym_AND);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 321:
      ACCEPT_TOKEN(anon_sym_OR);
      END_STATE();
    case 322:
      ACCEPT_TOKEN(anon_sym_OR);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 323:
      ACCEPT_TOKEN(anon_sym_XOR);
      END_STATE();
    case 324:
      ACCEPT_TOKEN(anon_sym_XOR);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 325:
      ACCEPT_TOKEN(anon_sym_NOT);
      END_STATE();
    case 326:
      ACCEPT_TOKEN(anon_sym_NOT);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 327:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 328:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 329:
      ACCEPT_TOKEN(anon_sym_STAR_STAR);
      END_STATE();
    case 330:
      ACCEPT_TOKEN(anon_sym_STAR);
      if (lookahead == '*') ADVANCE(329);
      END_STATE();
    case 331:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 332:
      ACCEPT_TOKEN(anon_sym_SLASH);
      if (lookahead == '/') ADVANCE(401);
      END_STATE();
    case 333:
      ACCEPT_TOKEN(anon_sym_MOD);
      END_STATE();
    case 334:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '=') ADVANCE(336);
      if (lookahead == '>') ADVANCE(339);
      END_STATE();
    case 335:
      ACCEPT_TOKEN(anon_sym_GT);
      if (lookahead == '=') ADVANCE(337);
      END_STATE();
    case 336:
      ACCEPT_TOKEN(anon_sym_LT_EQ);
      END_STATE();
    case 337:
      ACCEPT_TOKEN(anon_sym_GT_EQ);
      END_STATE();
    case 338:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 339:
      ACCEPT_TOKEN(anon_sym_LT_GT);
      END_STATE();
    case 340:
      ACCEPT_TOKEN(anon_sym_BOOL);
      END_STATE();
    case 341:
      ACCEPT_TOKEN(anon_sym_REAL);
      END_STATE();
    case 342:
      ACCEPT_TOKEN(anon_sym_INT);
      END_STATE();
    case 343:
      ACCEPT_TOKEN(anon_sym_INT);
      if (lookahead == 'E') ADVANCE(180);
      END_STATE();
    case 344:
      ACCEPT_TOKEN(sym_address);
      END_STATE();
    case 345:
      ACCEPT_TOKEN(sym_time_literal);
      END_STATE();
    case 346:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(346);
      END_STATE();
    case 347:
      ACCEPT_TOKEN(aux_sym_number_token2);
      if (lookahead == '#') ADVANCE(222);
      if (lookahead == '.') ADVANCE(369);
      if (lookahead == '_') ADVANCE(364);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(237);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(354);
      END_STATE();
    case 348:
      ACCEPT_TOKEN(aux_sym_number_token2);
      if (lookahead == '#') ADVANCE(223);
      if (lookahead == '.') ADVANCE(369);
      if (lookahead == '_') ADVANCE(364);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(237);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(354);
      END_STATE();
    case 349:
      ACCEPT_TOKEN(aux_sym_number_token2);
      if (lookahead == '#') ADVANCE(224);
      if (lookahead == '.') ADVANCE(369);
      if (lookahead == '_') ADVANCE(365);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(237);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(353);
      END_STATE();
    case 350:
      ACCEPT_TOKEN(aux_sym_number_token2);
      if (lookahead == '.') ADVANCE(369);
      if (lookahead == '6') ADVANCE(349);
      if (lookahead == '_') ADVANCE(364);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(237);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(354);
      END_STATE();
    case 351:
      ACCEPT_TOKEN(aux_sym_number_token2);
      if (lookahead == '.') ADVANCE(369);
      if (lookahead == '_') ADVANCE(364);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(237);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(354);
      END_STATE();
    case 352:
      ACCEPT_TOKEN(aux_sym_number_token2);
      if (lookahead == '.') ADVANCE(369);
      if (lookahead == '_') ADVANCE(368);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(237);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(352);
      END_STATE();
    case 353:
      ACCEPT_TOKEN(aux_sym_number_token2);
      if (lookahead == '.') ADVANCE(369);
      if (lookahead == '_') ADVANCE(363);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(237);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(352);
      END_STATE();
    case 354:
      ACCEPT_TOKEN(aux_sym_number_token2);
      if (lookahead == '.') ADVANCE(369);
      if (lookahead == '_') ADVANCE(365);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(237);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(353);
      END_STATE();
    case 355:
      ACCEPT_TOKEN(aux_sym_number_token2);
      if (lookahead == '.') ADVANCE(260);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(355);
      END_STATE();
    case 356:
      ACCEPT_TOKEN(anon_sym_TRUE);
      END_STATE();
    case 357:
      ACCEPT_TOKEN(anon_sym_FALSE);
      END_STATE();
    case 358:
      ACCEPT_TOKEN(sym_boolean);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 359:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '#') ADVANCE(222);
      if (lookahead == '.') ADVANCE(369);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(368);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(237);
      END_STATE();
    case 360:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '#') ADVANCE(223);
      if (lookahead == '.') ADVANCE(369);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(368);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(237);
      END_STATE();
    case 361:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '#') ADVANCE(224);
      if (lookahead == '.') ADVANCE(369);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(368);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(237);
      END_STATE();
    case 362:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '.') ADVANCE(369);
      if (lookahead == '6') ADVANCE(361);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(368);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(237);
      END_STATE();
    case 363:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '.') ADVANCE(369);
      if (lookahead == '_') ADVANCE(368);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(237);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(368);
      END_STATE();
    case 364:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '.') ADVANCE(369);
      if (lookahead == '_') ADVANCE(368);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(237);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(367);
      END_STATE();
    case 365:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '.') ADVANCE(369);
      if (lookahead == '_') ADVANCE(368);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(237);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(366);
      END_STATE();
    case 366:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '.') ADVANCE(369);
      if (lookahead == '_') ADVANCE(363);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(237);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(368);
      END_STATE();
    case 367:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '.') ADVANCE(369);
      if (lookahead == '_') ADVANCE(365);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(237);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(366);
      END_STATE();
    case 368:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '.') ADVANCE(369);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(368);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(237);
      END_STATE();
    case 369:
      ACCEPT_TOKEN(sym_floating_point);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(369);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(237);
      END_STATE();
    case 370:
      ACCEPT_TOKEN(sym_floating_point);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(370);
      END_STATE();
    case 371:
      ACCEPT_TOKEN(sym_binary);
      if (lookahead == '0' ||
          lookahead == '1' ||
          lookahead == '_') ADVANCE(371);
      END_STATE();
    case 372:
      ACCEPT_TOKEN(sym_octal);
      if (('0' <= lookahead && lookahead <= '7') ||
          lookahead == '_') ADVANCE(372);
      END_STATE();
    case 373:
      ACCEPT_TOKEN(sym_hexidecimal);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(373);
      END_STATE();
    case 374:
      ACCEPT_TOKEN(sym_time);
      END_STATE();
    case 375:
      ACCEPT_TOKEN(sym_time);
      if (lookahead == '-') ADVANCE(383);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(101);
      END_STATE();
    case 376:
      ACCEPT_TOKEN(sym_time);
      if (lookahead == '-') ADVANCE(383);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(106);
      END_STATE();
    case 377:
      ACCEPT_TOKEN(sym_time);
      if (lookahead == 'S') ADVANCE(374);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(127);
      END_STATE();
    case 378:
      ACCEPT_TOKEN(sym_time);
      if (lookahead == 's') ADVANCE(374);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(127);
      END_STATE();
    case 379:
      ACCEPT_TOKEN(sym_time);
      if (lookahead == 's') ADVANCE(345);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(127);
      END_STATE();
    case 380:
      ACCEPT_TOKEN(sym_time);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(109);
      END_STATE();
    case 381:
      ACCEPT_TOKEN(sym_time);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(135);
      END_STATE();
    case 382:
      ACCEPT_TOKEN(sym_time);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(115);
      END_STATE();
    case 383:
      ACCEPT_TOKEN(sym_time);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(106);
      END_STATE();
    case 384:
      ACCEPT_TOKEN(sym_date);
      END_STATE();
    case 385:
      ACCEPT_TOKEN(sym_date);
      if (lookahead == '_') ADVANCE(255);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(384);
      END_STATE();
    case 386:
      ACCEPT_TOKEN(sym_time_of_day);
      if (lookahead == '.') ADVANCE(256);
      END_STATE();
    case 387:
      ACCEPT_TOKEN(sym_time_of_day);
      if (lookahead == '.') ADVANCE(256);
      if (lookahead == '_') ADVANCE(254);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(386);
      END_STATE();
    case 388:
      ACCEPT_TOKEN(sym_time_of_day);
      if (lookahead == ':') ADVANCE(252);
      END_STATE();
    case 389:
      ACCEPT_TOKEN(sym_time_of_day);
      if (lookahead == ':') ADVANCE(252);
      if (lookahead == '_') ADVANCE(251);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(388);
      END_STATE();
    case 390:
      ACCEPT_TOKEN(sym_time_of_day);
      if (lookahead == '_') ADVANCE(256);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(390);
      END_STATE();
    case 391:
      ACCEPT_TOKEN(anon_sym_DT_POUND);
      END_STATE();
    case 392:
      ACCEPT_TOKEN(aux_sym_date_and_time_token1);
      END_STATE();
    case 393:
      ACCEPT_TOKEN(aux_sym_date_and_time_token2);
      END_STATE();
    case 394:
      ACCEPT_TOKEN(aux_sym_date_and_time_token2);
      if (lookahead == '_') ADVANCE(262);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(393);
      END_STATE();
    case 395:
      ACCEPT_TOKEN(aux_sym_date_and_time_token3);
      END_STATE();
    case 396:
      ACCEPT_TOKEN(aux_sym_date_and_time_token3);
      if (lookahead == ':') ADVANCE(243);
      END_STATE();
    case 397:
      ACCEPT_TOKEN(aux_sym_date_and_time_token3);
      if (lookahead == ':') ADVANCE(243);
      if (lookahead == '_') ADVANCE(241);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(396);
      END_STATE();
    case 398:
      ACCEPT_TOKEN(aux_sym_date_and_time_token3);
      if (lookahead == '_') ADVANCE(245);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(395);
      END_STATE();
    case 399:
      ACCEPT_TOKEN(sym_string);
      if (lookahead == '\'') ADVANCE(399);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(10);
      END_STATE();
    case 400:
      ACCEPT_TOKEN(sym_wstring);
      if (lookahead == '"') ADVANCE(400);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(2);
      END_STATE();
    case 401:
      ACCEPT_TOKEN(sym_inline_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(401);
      END_STATE();
    case 402:
      ACCEPT_TOKEN(sym_block_comment);
      END_STATE();
    case 403:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '#') ADVANCE(242);
      if (lookahead == 'T') ADVANCE(404);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 404:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '#') ADVANCE(391);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 405:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '#') ADVANCE(246);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 406:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '#') ADVANCE(376);
      if (lookahead == 'O') ADVANCE(419);
      if (lookahead == 'R') ADVANCE(474);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 407:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'A') ADVANCE(434);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 408:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'A') ADVANCE(437);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 409:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'A') ADVANCE(459);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 410:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'A') ADVANCE(447);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 411:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'A') ADVANCE(461);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 412:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'A') ADVANCE(460);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 413:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'B') ADVANCE(436);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 414:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'C') ADVANCE(433);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 415:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'C') ADVANCE(452);
      if (lookahead == 'I') ADVANCE(441);
      if (lookahead == 'O') ADVANCE(475);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 416:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'C') ADVANCE(471);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 417:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'D') ADVANCE(320);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 418:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'D') ADVANCE(480);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 419:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'D') ADVANCE(405);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 420:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'D') ADVANCE(483);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 421:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'D') ADVANCE(484);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 422:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'D') ADVANCE(482);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 423:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'E') ADVANCE(358);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 424:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'E') ADVANCE(318);
      if (lookahead == 'I') ADVANCE(426);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 425:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'F') ADVANCE(311);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 426:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'F') ADVANCE(316);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 427:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'F') ADVANCE(314);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 428:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'F') ADVANCE(477);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 429:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'G') ADVANCE(462);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 430:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'I') ADVANCE(441);
      if (lookahead == 'O') ADVANCE(475);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 431:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'I') ADVANCE(427);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 432:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'I') ADVANCE(453);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 433:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'K') ADVANCE(285);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 434:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'L') ADVANCE(464);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 435:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'L') ADVANCE(465);
      if (lookahead == 'N') ADVANCE(421);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 436:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'L') ADVANCE(451);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 437:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'M') ADVANCE(277);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 438:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'N') ADVANCE(417);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 439:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'N') ADVANCE(416);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 440:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'N') ADVANCE(466);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 441:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'N') ADVANCE(454);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 442:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'N') ADVANCE(418);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 443:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'N') ADVANCE(481);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 444:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'N') ADVANCE(420);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 445:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'N') ADVANCE(421);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 446:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'N') ADVANCE(422);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 447:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'N') ADVANCE(470);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 448:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'O') ADVANCE(467);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 449:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'O') ADVANCE(429);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 450:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'O') ADVANCE(458);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 451:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'O') ADVANCE(414);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 452:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'O') ADVANCE(440);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 453:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'O') ADVANCE(443);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 454:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'P') ADVANCE(476);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 455:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'P') ADVANCE(463);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 456:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'P') ADVANCE(478);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 457:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'R') ADVANCE(322);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 458:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'R') ADVANCE(324);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 459:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'R') ADVANCE(299);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 460:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'R') ADVANCE(302);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 461:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'R') ADVANCE(300);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 462:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'R') ADVANCE(408);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 463:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'R') ADVANCE(449);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 464:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'S') ADVANCE(423);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 465:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'S') ADVANCE(424);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 466:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'S') ADVANCE(472);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 467:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'T') ADVANCE(326);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 468:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'T') ADVANCE(304);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 469:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'T') ADVANCE(306);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 470:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'T') ADVANCE(308);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 471:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'T') ADVANCE(432);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 472:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'T') ADVANCE(410);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 473:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'T') ADVANCE(456);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 474:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'U') ADVANCE(423);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 475:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'U') ADVANCE(473);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 476:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'U') ADVANCE(468);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 477:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'U') ADVANCE(439);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 478:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'U') ADVANCE(469);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 479:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'V') ADVANCE(412);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 480:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '_') ADVANCE(455);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 481:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '_') ADVANCE(413);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 482:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '_') ADVANCE(479);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 483:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '_') ADVANCE(428);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 484:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '_') ADVANCE(431);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    case 485:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(485);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 1},
  [3] = {.lex_state = 1},
  [4] = {.lex_state = 1},
  [5] = {.lex_state = 1},
  [6] = {.lex_state = 1},
  [7] = {.lex_state = 1},
  [8] = {.lex_state = 1},
  [9] = {.lex_state = 1},
  [10] = {.lex_state = 1},
  [11] = {.lex_state = 1},
  [12] = {.lex_state = 1},
  [13] = {.lex_state = 1},
  [14] = {.lex_state = 1},
  [15] = {.lex_state = 1},
  [16] = {.lex_state = 1},
  [17] = {.lex_state = 1},
  [18] = {.lex_state = 1},
  [19] = {.lex_state = 1},
  [20] = {.lex_state = 1},
  [21] = {.lex_state = 1},
  [22] = {.lex_state = 1},
  [23] = {.lex_state = 1},
  [24] = {.lex_state = 1},
  [25] = {.lex_state = 11},
  [26] = {.lex_state = 11},
  [27] = {.lex_state = 11},
  [28] = {.lex_state = 11},
  [29] = {.lex_state = 11},
  [30] = {.lex_state = 11},
  [31] = {.lex_state = 11},
  [32] = {.lex_state = 11},
  [33] = {.lex_state = 11},
  [34] = {.lex_state = 11},
  [35] = {.lex_state = 17},
  [36] = {.lex_state = 11},
  [37] = {.lex_state = 11},
  [38] = {.lex_state = 11},
  [39] = {.lex_state = 11},
  [40] = {.lex_state = 17},
  [41] = {.lex_state = 11},
  [42] = {.lex_state = 11},
  [43] = {.lex_state = 11},
  [44] = {.lex_state = 11},
  [45] = {.lex_state = 11},
  [46] = {.lex_state = 11},
  [47] = {.lex_state = 11},
  [48] = {.lex_state = 11},
  [49] = {.lex_state = 11},
  [50] = {.lex_state = 11},
  [51] = {.lex_state = 11},
  [52] = {.lex_state = 68},
  [53] = {.lex_state = 68},
  [54] = {.lex_state = 62},
  [55] = {.lex_state = 62},
  [56] = {.lex_state = 62},
  [57] = {.lex_state = 62},
  [58] = {.lex_state = 62},
  [59] = {.lex_state = 62},
  [60] = {.lex_state = 17},
  [61] = {.lex_state = 62},
  [62] = {.lex_state = 62},
  [63] = {.lex_state = 62},
  [64] = {.lex_state = 62},
  [65] = {.lex_state = 62},
  [66] = {.lex_state = 68},
  [67] = {.lex_state = 9},
  [68] = {.lex_state = 9},
  [69] = {.lex_state = 69},
  [70] = {.lex_state = 70},
  [71] = {.lex_state = 69},
  [72] = {.lex_state = 66},
  [73] = {.lex_state = 69},
  [74] = {.lex_state = 0},
  [75] = {.lex_state = 70},
  [76] = {.lex_state = 66},
  [77] = {.lex_state = 66},
  [78] = {.lex_state = 70},
  [79] = {.lex_state = 0},
  [80] = {.lex_state = 17},
  [81] = {.lex_state = 0},
  [82] = {.lex_state = 0},
  [83] = {.lex_state = 0},
  [84] = {.lex_state = 17},
  [85] = {.lex_state = 17},
  [86] = {.lex_state = 17},
  [87] = {.lex_state = 17},
  [88] = {.lex_state = 17},
  [89] = {.lex_state = 17},
  [90] = {.lex_state = 17},
  [91] = {.lex_state = 17},
  [92] = {.lex_state = 0},
  [93] = {.lex_state = 0},
  [94] = {.lex_state = 0},
  [95] = {.lex_state = 0},
  [96] = {.lex_state = 0},
  [97] = {.lex_state = 68},
  [98] = {.lex_state = 68},
  [99] = {.lex_state = 68},
  [100] = {.lex_state = 68},
  [101] = {.lex_state = 68},
  [102] = {.lex_state = 0},
  [103] = {.lex_state = 0},
  [104] = {.lex_state = 0},
  [105] = {.lex_state = 68},
  [106] = {.lex_state = 62},
  [107] = {.lex_state = 0},
  [108] = {.lex_state = 62},
  [109] = {.lex_state = 62},
  [110] = {.lex_state = 62},
  [111] = {.lex_state = 62},
  [112] = {.lex_state = 62},
  [113] = {.lex_state = 62},
  [114] = {.lex_state = 62},
  [115] = {.lex_state = 71},
  [116] = {.lex_state = 0},
  [117] = {.lex_state = 71},
  [118] = {.lex_state = 0},
  [119] = {.lex_state = 71},
  [120] = {.lex_state = 0},
  [121] = {.lex_state = 71},
  [122] = {.lex_state = 71},
  [123] = {.lex_state = 71},
  [124] = {.lex_state = 71},
  [125] = {.lex_state = 0},
  [126] = {.lex_state = 71},
  [127] = {.lex_state = 11},
  [128] = {.lex_state = 0},
  [129] = {.lex_state = 71},
  [130] = {.lex_state = 71},
  [131] = {.lex_state = 71},
  [132] = {.lex_state = 0},
  [133] = {.lex_state = 71},
  [134] = {.lex_state = 71},
  [135] = {.lex_state = 71},
  [136] = {.lex_state = 0},
  [137] = {.lex_state = 71},
  [138] = {.lex_state = 11},
  [139] = {.lex_state = 0},
  [140] = {.lex_state = 0},
  [141] = {.lex_state = 69},
  [142] = {.lex_state = 70},
  [143] = {.lex_state = 70},
  [144] = {.lex_state = 70},
  [145] = {.lex_state = 0},
  [146] = {.lex_state = 0},
  [147] = {.lex_state = 0},
  [148] = {.lex_state = 70},
  [149] = {.lex_state = 17},
  [150] = {.lex_state = 70},
  [151] = {.lex_state = 66},
  [152] = {.lex_state = 0},
  [153] = {.lex_state = 70},
  [154] = {.lex_state = 0},
  [155] = {.lex_state = 66},
  [156] = {.lex_state = 66},
  [157] = {.lex_state = 70},
  [158] = {.lex_state = 66},
  [159] = {.lex_state = 70},
  [160] = {.lex_state = 69},
  [161] = {.lex_state = 69},
  [162] = {.lex_state = 69},
  [163] = {.lex_state = 66},
  [164] = {.lex_state = 69},
  [165] = {.lex_state = 69},
  [166] = {.lex_state = 69},
  [167] = {.lex_state = 69},
  [168] = {.lex_state = 66},
  [169] = {.lex_state = 66},
  [170] = {.lex_state = 0},
  [171] = {.lex_state = 66},
  [172] = {.lex_state = 1},
  [173] = {.lex_state = 1},
  [174] = {.lex_state = 71},
  [175] = {.lex_state = 1},
  [176] = {.lex_state = 1},
  [177] = {.lex_state = 1},
  [178] = {.lex_state = 71},
  [179] = {.lex_state = 11},
  [180] = {.lex_state = 1},
  [181] = {.lex_state = 0},
  [182] = {.lex_state = 1},
  [183] = {.lex_state = 71},
  [184] = {.lex_state = 1},
  [185] = {.lex_state = 1},
  [186] = {.lex_state = 0},
  [187] = {.lex_state = 11},
  [188] = {.lex_state = 1},
  [189] = {.lex_state = 0},
  [190] = {.lex_state = 0},
  [191] = {.lex_state = 0},
  [192] = {.lex_state = 238},
  [193] = {.lex_state = 0},
  [194] = {.lex_state = 238},
  [195] = {.lex_state = 0},
  [196] = {.lex_state = 0},
  [197] = {.lex_state = 0},
  [198] = {.lex_state = 0},
  [199] = {.lex_state = 0},
  [200] = {.lex_state = 17},
  [201] = {.lex_state = 0},
  [202] = {.lex_state = 0},
  [203] = {.lex_state = 0},
  [204] = {.lex_state = 0},
  [205] = {.lex_state = 0},
  [206] = {.lex_state = 0},
  [207] = {.lex_state = 0},
  [208] = {.lex_state = 0},
  [209] = {.lex_state = 0},
  [210] = {.lex_state = 0},
  [211] = {.lex_state = 0},
  [212] = {.lex_state = 0},
  [213] = {.lex_state = 0},
  [214] = {.lex_state = 0},
  [215] = {.lex_state = 0},
  [216] = {.lex_state = 11},
  [217] = {.lex_state = 238},
  [218] = {.lex_state = 1},
  [219] = {.lex_state = 0},
  [220] = {.lex_state = 11},
  [221] = {.lex_state = 1},
  [222] = {.lex_state = 0},
  [223] = {.lex_state = 11},
  [224] = {.lex_state = 0},
  [225] = {.lex_state = 0},
  [226] = {.lex_state = 9},
  [227] = {.lex_state = 238},
  [228] = {.lex_state = 0},
  [229] = {.lex_state = 0},
  [230] = {.lex_state = 0},
  [231] = {.lex_state = 0},
  [232] = {.lex_state = 238},
  [233] = {.lex_state = 0},
  [234] = {.lex_state = 238},
  [235] = {.lex_state = 238},
  [236] = {.lex_state = 0},
  [237] = {.lex_state = 0},
  [238] = {.lex_state = 1},
  [239] = {.lex_state = 0},
  [240] = {.lex_state = 0},
  [241] = {.lex_state = 0},
  [242] = {.lex_state = 0},
  [243] = {.lex_state = 0},
  [244] = {.lex_state = 0},
  [245] = {.lex_state = 0},
  [246] = {.lex_state = 0},
  [247] = {.lex_state = 238},
  [248] = {.lex_state = 238},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_PROGRAM] = ACTIONS(1),
    [anon_sym_END_PROGRAM] = ACTIONS(1),
    [anon_sym_CONFIGURATION] = ACTIONS(1),
    [anon_sym_RESOURCE] = ACTIONS(1),
    [anon_sym_ON] = ACTIONS(1),
    [anon_sym_END_RESOURCE] = ACTIONS(1),
    [anon_sym_END_CONFIGURATION] = ACTIONS(1),
    [anon_sym_FUNCTION_BLOCK] = ACTIONS(1),
    [anon_sym_END_FUNCTION_BLOCK] = ACTIONS(1),
    [anon_sym_TASK] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_INTERVAL] = ACTIONS(1),
    [anon_sym_COLON_EQ] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_PRIORITY] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [anon_sym_WITH] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_VAR] = ACTIONS(1),
    [anon_sym_END_VAR] = ACTIONS(1),
    [anon_sym_VAR_INPUT] = ACTIONS(1),
    [anon_sym_VAR_OUTPUT] = ACTIONS(1),
    [anon_sym_VAR_CONSTANT] = ACTIONS(1),
    [anon_sym_AT] = ACTIONS(1),
    [anon_sym_IF] = ACTIONS(1),
    [anon_sym_THEN] = ACTIONS(1),
    [anon_sym_END_IF] = ACTIONS(1),
    [anon_sym_ELSIF] = ACTIONS(1),
    [anon_sym_ELSE] = ACTIONS(1),
    [anon_sym_AND] = ACTIONS(1),
    [anon_sym_OR] = ACTIONS(1),
    [anon_sym_XOR] = ACTIONS(1),
    [anon_sym_NOT] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_STAR_STAR] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [anon_sym_MOD] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [anon_sym_LT_EQ] = ACTIONS(1),
    [anon_sym_GT_EQ] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_LT_GT] = ACTIONS(1),
    [anon_sym_BOOL] = ACTIONS(1),
    [anon_sym_REAL] = ACTIONS(1),
    [anon_sym_INT] = ACTIONS(1),
    [sym_address] = ACTIONS(1),
    [sym_time_literal] = ACTIONS(1),
    [aux_sym_number_token2] = ACTIONS(1),
    [anon_sym_TRUE] = ACTIONS(1),
    [anon_sym_FALSE] = ACTIONS(1),
    [sym_boolean] = ACTIONS(1),
    [sym_integer] = ACTIONS(1),
    [sym_floating_point] = ACTIONS(1),
    [sym_binary] = ACTIONS(1),
    [sym_octal] = ACTIONS(1),
    [sym_hexidecimal] = ACTIONS(1),
    [sym_time] = ACTIONS(1),
    [sym_date] = ACTIONS(1),
    [sym_time_of_day] = ACTIONS(1),
    [anon_sym_DT_POUND] = ACTIONS(1),
    [aux_sym_date_and_time_token1] = ACTIONS(1),
    [aux_sym_date_and_time_token3] = ACTIONS(1),
    [sym_string] = ACTIONS(1),
    [sym_wstring] = ACTIONS(1),
    [sym_inline_comment] = ACTIONS(1),
    [sym_block_comment] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(246),
    [sym_program] = STATE(79),
    [sym_configuration] = STATE(79),
    [sym_function_block] = STATE(79),
    [aux_sym_source_file_repeat1] = STATE(79),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_PROGRAM] = ACTIONS(5),
    [anon_sym_CONFIGURATION] = ACTIONS(7),
    [anon_sym_FUNCTION_BLOCK] = ACTIONS(9),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 10,
    ACTIONS(11), 1,
      anon_sym_LPAREN,
    ACTIONS(13), 1,
      anon_sym_RPAREN,
    ACTIONS(17), 1,
      anon_sym_NOT,
    ACTIONS(25), 1,
      anon_sym_DT_POUND,
    STATE(184), 1,
      sym_logical_operator,
    ACTIONS(19), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(15), 3,
      anon_sym_AND,
      anon_sym_OR,
      anon_sym_XOR,
    ACTIONS(21), 3,
      sym_boolean,
      sym_integer,
      sym_identifier,
    STATE(36), 7,
      sym__expression,
      sym_logical_expression,
      sym_parenthesis_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__literal,
      sym_date_and_time,
    ACTIONS(23), 9,
      sym_floating_point,
      sym_binary,
      sym_octal,
      sym_hexidecimal,
      sym_time,
      sym_date,
      sym_time_of_day,
      sym_string,
      sym_wstring,
  [50] = 10,
    ACTIONS(11), 1,
      anon_sym_LPAREN,
    ACTIONS(17), 1,
      anon_sym_NOT,
    ACTIONS(25), 1,
      anon_sym_DT_POUND,
    ACTIONS(27), 1,
      anon_sym_RPAREN,
    STATE(184), 1,
      sym_logical_operator,
    ACTIONS(19), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(15), 3,
      anon_sym_AND,
      anon_sym_OR,
      anon_sym_XOR,
    ACTIONS(29), 3,
      sym_boolean,
      sym_integer,
      sym_identifier,
    STATE(37), 7,
      sym__expression,
      sym_logical_expression,
      sym_parenthesis_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__literal,
      sym_date_and_time,
    ACTIONS(31), 9,
      sym_floating_point,
      sym_binary,
      sym_octal,
      sym_hexidecimal,
      sym_time,
      sym_date,
      sym_time_of_day,
      sym_string,
      sym_wstring,
  [100] = 10,
    ACTIONS(11), 1,
      anon_sym_LPAREN,
    ACTIONS(17), 1,
      anon_sym_NOT,
    ACTIONS(25), 1,
      anon_sym_DT_POUND,
    ACTIONS(33), 1,
      anon_sym_RPAREN,
    STATE(184), 1,
      sym_logical_operator,
    ACTIONS(19), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(15), 3,
      anon_sym_AND,
      anon_sym_OR,
      anon_sym_XOR,
    ACTIONS(35), 3,
      sym_boolean,
      sym_integer,
      sym_identifier,
    STATE(38), 7,
      sym__expression,
      sym_logical_expression,
      sym_parenthesis_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__literal,
      sym_date_and_time,
    ACTIONS(37), 9,
      sym_floating_point,
      sym_binary,
      sym_octal,
      sym_hexidecimal,
      sym_time,
      sym_date,
      sym_time_of_day,
      sym_string,
      sym_wstring,
  [150] = 10,
    ACTIONS(11), 1,
      anon_sym_LPAREN,
    ACTIONS(17), 1,
      anon_sym_NOT,
    ACTIONS(25), 1,
      anon_sym_DT_POUND,
    ACTIONS(39), 1,
      anon_sym_RPAREN,
    STATE(184), 1,
      sym_logical_operator,
    ACTIONS(19), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(15), 3,
      anon_sym_AND,
      anon_sym_OR,
      anon_sym_XOR,
    ACTIONS(41), 3,
      sym_boolean,
      sym_integer,
      sym_identifier,
    STATE(39), 7,
      sym__expression,
      sym_logical_expression,
      sym_parenthesis_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__literal,
      sym_date_and_time,
    ACTIONS(43), 9,
      sym_floating_point,
      sym_binary,
      sym_octal,
      sym_hexidecimal,
      sym_time,
      sym_date,
      sym_time_of_day,
      sym_string,
      sym_wstring,
  [200] = 9,
    ACTIONS(11), 1,
      anon_sym_LPAREN,
    ACTIONS(17), 1,
      anon_sym_NOT,
    ACTIONS(25), 1,
      anon_sym_DT_POUND,
    STATE(184), 1,
      sym_logical_operator,
    ACTIONS(19), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(15), 3,
      anon_sym_AND,
      anon_sym_OR,
      anon_sym_XOR,
    ACTIONS(45), 3,
      sym_boolean,
      sym_integer,
      sym_identifier,
    STATE(48), 7,
      sym__expression,
      sym_logical_expression,
      sym_parenthesis_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__literal,
      sym_date_and_time,
    ACTIONS(47), 9,
      sym_floating_point,
      sym_binary,
      sym_octal,
      sym_hexidecimal,
      sym_time,
      sym_date,
      sym_time_of_day,
      sym_string,
      sym_wstring,
  [247] = 9,
    ACTIONS(11), 1,
      anon_sym_LPAREN,
    ACTIONS(17), 1,
      anon_sym_NOT,
    ACTIONS(25), 1,
      anon_sym_DT_POUND,
    STATE(184), 1,
      sym_logical_operator,
    ACTIONS(19), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(15), 3,
      anon_sym_AND,
      anon_sym_OR,
      anon_sym_XOR,
    ACTIONS(49), 3,
      sym_boolean,
      sym_integer,
      sym_identifier,
    STATE(51), 7,
      sym__expression,
      sym_logical_expression,
      sym_parenthesis_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__literal,
      sym_date_and_time,
    ACTIONS(51), 9,
      sym_floating_point,
      sym_binary,
      sym_octal,
      sym_hexidecimal,
      sym_time,
      sym_date,
      sym_time_of_day,
      sym_string,
      sym_wstring,
  [294] = 9,
    ACTIONS(11), 1,
      anon_sym_LPAREN,
    ACTIONS(17), 1,
      anon_sym_NOT,
    ACTIONS(25), 1,
      anon_sym_DT_POUND,
    STATE(184), 1,
      sym_logical_operator,
    ACTIONS(19), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(15), 3,
      anon_sym_AND,
      anon_sym_OR,
      anon_sym_XOR,
    ACTIONS(53), 3,
      sym_boolean,
      sym_integer,
      sym_identifier,
    STATE(42), 7,
      sym__expression,
      sym_logical_expression,
      sym_parenthesis_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__literal,
      sym_date_and_time,
    ACTIONS(55), 9,
      sym_floating_point,
      sym_binary,
      sym_octal,
      sym_hexidecimal,
      sym_time,
      sym_date,
      sym_time_of_day,
      sym_string,
      sym_wstring,
  [341] = 9,
    ACTIONS(11), 1,
      anon_sym_LPAREN,
    ACTIONS(17), 1,
      anon_sym_NOT,
    ACTIONS(25), 1,
      anon_sym_DT_POUND,
    STATE(184), 1,
      sym_logical_operator,
    ACTIONS(19), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(15), 3,
      anon_sym_AND,
      anon_sym_OR,
      anon_sym_XOR,
    ACTIONS(57), 3,
      sym_boolean,
      sym_integer,
      sym_identifier,
    STATE(45), 7,
      sym__expression,
      sym_logical_expression,
      sym_parenthesis_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__literal,
      sym_date_and_time,
    ACTIONS(59), 9,
      sym_floating_point,
      sym_binary,
      sym_octal,
      sym_hexidecimal,
      sym_time,
      sym_date,
      sym_time_of_day,
      sym_string,
      sym_wstring,
  [388] = 9,
    ACTIONS(11), 1,
      anon_sym_LPAREN,
    ACTIONS(17), 1,
      anon_sym_NOT,
    ACTIONS(25), 1,
      anon_sym_DT_POUND,
    STATE(184), 1,
      sym_logical_operator,
    ACTIONS(19), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(15), 3,
      anon_sym_AND,
      anon_sym_OR,
      anon_sym_XOR,
    ACTIONS(61), 3,
      sym_boolean,
      sym_integer,
      sym_identifier,
    STATE(46), 7,
      sym__expression,
      sym_logical_expression,
      sym_parenthesis_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__literal,
      sym_date_and_time,
    ACTIONS(63), 9,
      sym_floating_point,
      sym_binary,
      sym_octal,
      sym_hexidecimal,
      sym_time,
      sym_date,
      sym_time_of_day,
      sym_string,
      sym_wstring,
  [435] = 9,
    ACTIONS(11), 1,
      anon_sym_LPAREN,
    ACTIONS(17), 1,
      anon_sym_NOT,
    ACTIONS(25), 1,
      anon_sym_DT_POUND,
    STATE(184), 1,
      sym_logical_operator,
    ACTIONS(19), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(15), 3,
      anon_sym_AND,
      anon_sym_OR,
      anon_sym_XOR,
    ACTIONS(65), 3,
      sym_boolean,
      sym_integer,
      sym_identifier,
    STATE(25), 7,
      sym__expression,
      sym_logical_expression,
      sym_parenthesis_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__literal,
      sym_date_and_time,
    ACTIONS(67), 9,
      sym_floating_point,
      sym_binary,
      sym_octal,
      sym_hexidecimal,
      sym_time,
      sym_date,
      sym_time_of_day,
      sym_string,
      sym_wstring,
  [482] = 9,
    ACTIONS(11), 1,
      anon_sym_LPAREN,
    ACTIONS(17), 1,
      anon_sym_NOT,
    ACTIONS(25), 1,
      anon_sym_DT_POUND,
    STATE(184), 1,
      sym_logical_operator,
    ACTIONS(19), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(15), 3,
      anon_sym_AND,
      anon_sym_OR,
      anon_sym_XOR,
    ACTIONS(65), 3,
      sym_boolean,
      sym_integer,
      sym_identifier,
    STATE(25), 7,
      sym__expression,
      sym_logical_expression,
      sym_parenthesis_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__literal,
      sym_date_and_time,
    ACTIONS(67), 9,
      sym_floating_point,
      sym_binary,
      sym_octal,
      sym_hexidecimal,
      sym_time,
      sym_date,
      sym_time_of_day,
      sym_string,
      sym_wstring,
  [529] = 9,
    ACTIONS(11), 1,
      anon_sym_LPAREN,
    ACTIONS(17), 1,
      anon_sym_NOT,
    ACTIONS(25), 1,
      anon_sym_DT_POUND,
    STATE(184), 1,
      sym_logical_operator,
    ACTIONS(19), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(15), 3,
      anon_sym_AND,
      anon_sym_OR,
      anon_sym_XOR,
    ACTIONS(69), 3,
      sym_boolean,
      sym_integer,
      sym_identifier,
    STATE(41), 7,
      sym__expression,
      sym_logical_expression,
      sym_parenthesis_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__literal,
      sym_date_and_time,
    ACTIONS(71), 9,
      sym_floating_point,
      sym_binary,
      sym_octal,
      sym_hexidecimal,
      sym_time,
      sym_date,
      sym_time_of_day,
      sym_string,
      sym_wstring,
  [576] = 9,
    ACTIONS(11), 1,
      anon_sym_LPAREN,
    ACTIONS(17), 1,
      anon_sym_NOT,
    ACTIONS(25), 1,
      anon_sym_DT_POUND,
    STATE(184), 1,
      sym_logical_operator,
    ACTIONS(19), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(15), 3,
      anon_sym_AND,
      anon_sym_OR,
      anon_sym_XOR,
    ACTIONS(73), 3,
      sym_boolean,
      sym_integer,
      sym_identifier,
    STATE(31), 7,
      sym__expression,
      sym_logical_expression,
      sym_parenthesis_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__literal,
      sym_date_and_time,
    ACTIONS(75), 9,
      sym_floating_point,
      sym_binary,
      sym_octal,
      sym_hexidecimal,
      sym_time,
      sym_date,
      sym_time_of_day,
      sym_string,
      sym_wstring,
  [623] = 9,
    ACTIONS(11), 1,
      anon_sym_LPAREN,
    ACTIONS(17), 1,
      anon_sym_NOT,
    ACTIONS(25), 1,
      anon_sym_DT_POUND,
    STATE(184), 1,
      sym_logical_operator,
    ACTIONS(19), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(15), 3,
      anon_sym_AND,
      anon_sym_OR,
      anon_sym_XOR,
    ACTIONS(77), 3,
      sym_boolean,
      sym_integer,
      sym_identifier,
    STATE(29), 7,
      sym__expression,
      sym_logical_expression,
      sym_parenthesis_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__literal,
      sym_date_and_time,
    ACTIONS(79), 9,
      sym_floating_point,
      sym_binary,
      sym_octal,
      sym_hexidecimal,
      sym_time,
      sym_date,
      sym_time_of_day,
      sym_string,
      sym_wstring,
  [670] = 9,
    ACTIONS(11), 1,
      anon_sym_LPAREN,
    ACTIONS(17), 1,
      anon_sym_NOT,
    ACTIONS(25), 1,
      anon_sym_DT_POUND,
    STATE(184), 1,
      sym_logical_operator,
    ACTIONS(19), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(15), 3,
      anon_sym_AND,
      anon_sym_OR,
      anon_sym_XOR,
    ACTIONS(81), 3,
      sym_boolean,
      sym_integer,
      sym_identifier,
    STATE(26), 7,
      sym__expression,
      sym_logical_expression,
      sym_parenthesis_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__literal,
      sym_date_and_time,
    ACTIONS(83), 9,
      sym_floating_point,
      sym_binary,
      sym_octal,
      sym_hexidecimal,
      sym_time,
      sym_date,
      sym_time_of_day,
      sym_string,
      sym_wstring,
  [717] = 9,
    ACTIONS(11), 1,
      anon_sym_LPAREN,
    ACTIONS(17), 1,
      anon_sym_NOT,
    ACTIONS(25), 1,
      anon_sym_DT_POUND,
    STATE(184), 1,
      sym_logical_operator,
    ACTIONS(19), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(15), 3,
      anon_sym_AND,
      anon_sym_OR,
      anon_sym_XOR,
    ACTIONS(85), 3,
      sym_boolean,
      sym_integer,
      sym_identifier,
    STATE(50), 7,
      sym__expression,
      sym_logical_expression,
      sym_parenthesis_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__literal,
      sym_date_and_time,
    ACTIONS(87), 9,
      sym_floating_point,
      sym_binary,
      sym_octal,
      sym_hexidecimal,
      sym_time,
      sym_date,
      sym_time_of_day,
      sym_string,
      sym_wstring,
  [764] = 9,
    ACTIONS(11), 1,
      anon_sym_LPAREN,
    ACTIONS(17), 1,
      anon_sym_NOT,
    ACTIONS(25), 1,
      anon_sym_DT_POUND,
    STATE(184), 1,
      sym_logical_operator,
    ACTIONS(19), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(15), 3,
      anon_sym_AND,
      anon_sym_OR,
      anon_sym_XOR,
    ACTIONS(89), 3,
      sym_boolean,
      sym_integer,
      sym_identifier,
    STATE(27), 7,
      sym__expression,
      sym_logical_expression,
      sym_parenthesis_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__literal,
      sym_date_and_time,
    ACTIONS(91), 9,
      sym_floating_point,
      sym_binary,
      sym_octal,
      sym_hexidecimal,
      sym_time,
      sym_date,
      sym_time_of_day,
      sym_string,
      sym_wstring,
  [811] = 9,
    ACTIONS(11), 1,
      anon_sym_LPAREN,
    ACTIONS(17), 1,
      anon_sym_NOT,
    ACTIONS(25), 1,
      anon_sym_DT_POUND,
    STATE(184), 1,
      sym_logical_operator,
    ACTIONS(19), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(15), 3,
      anon_sym_AND,
      anon_sym_OR,
      anon_sym_XOR,
    ACTIONS(93), 3,
      sym_boolean,
      sym_integer,
      sym_identifier,
    STATE(49), 7,
      sym__expression,
      sym_logical_expression,
      sym_parenthesis_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__literal,
      sym_date_and_time,
    ACTIONS(95), 9,
      sym_floating_point,
      sym_binary,
      sym_octal,
      sym_hexidecimal,
      sym_time,
      sym_date,
      sym_time_of_day,
      sym_string,
      sym_wstring,
  [858] = 9,
    ACTIONS(11), 1,
      anon_sym_LPAREN,
    ACTIONS(17), 1,
      anon_sym_NOT,
    ACTIONS(25), 1,
      anon_sym_DT_POUND,
    STATE(184), 1,
      sym_logical_operator,
    ACTIONS(19), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(15), 3,
      anon_sym_AND,
      anon_sym_OR,
      anon_sym_XOR,
    ACTIONS(97), 3,
      sym_boolean,
      sym_integer,
      sym_identifier,
    STATE(44), 7,
      sym__expression,
      sym_logical_expression,
      sym_parenthesis_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__literal,
      sym_date_and_time,
    ACTIONS(99), 9,
      sym_floating_point,
      sym_binary,
      sym_octal,
      sym_hexidecimal,
      sym_time,
      sym_date,
      sym_time_of_day,
      sym_string,
      sym_wstring,
  [905] = 9,
    ACTIONS(11), 1,
      anon_sym_LPAREN,
    ACTIONS(17), 1,
      anon_sym_NOT,
    ACTIONS(25), 1,
      anon_sym_DT_POUND,
    STATE(184), 1,
      sym_logical_operator,
    ACTIONS(19), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(15), 3,
      anon_sym_AND,
      anon_sym_OR,
      anon_sym_XOR,
    ACTIONS(101), 3,
      sym_boolean,
      sym_integer,
      sym_identifier,
    STATE(47), 7,
      sym__expression,
      sym_logical_expression,
      sym_parenthesis_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__literal,
      sym_date_and_time,
    ACTIONS(103), 9,
      sym_floating_point,
      sym_binary,
      sym_octal,
      sym_hexidecimal,
      sym_time,
      sym_date,
      sym_time_of_day,
      sym_string,
      sym_wstring,
  [952] = 9,
    ACTIONS(11), 1,
      anon_sym_LPAREN,
    ACTIONS(17), 1,
      anon_sym_NOT,
    ACTIONS(25), 1,
      anon_sym_DT_POUND,
    STATE(184), 1,
      sym_logical_operator,
    ACTIONS(19), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(15), 3,
      anon_sym_AND,
      anon_sym_OR,
      anon_sym_XOR,
    ACTIONS(105), 3,
      sym_boolean,
      sym_integer,
      sym_identifier,
    STATE(34), 7,
      sym__expression,
      sym_logical_expression,
      sym_parenthesis_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__literal,
      sym_date_and_time,
    ACTIONS(107), 9,
      sym_floating_point,
      sym_binary,
      sym_octal,
      sym_hexidecimal,
      sym_time,
      sym_date,
      sym_time_of_day,
      sym_string,
      sym_wstring,
  [999] = 9,
    ACTIONS(11), 1,
      anon_sym_LPAREN,
    ACTIONS(17), 1,
      anon_sym_NOT,
    ACTIONS(25), 1,
      anon_sym_DT_POUND,
    STATE(184), 1,
      sym_logical_operator,
    ACTIONS(19), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(15), 3,
      anon_sym_AND,
      anon_sym_OR,
      anon_sym_XOR,
    ACTIONS(109), 3,
      sym_boolean,
      sym_integer,
      sym_identifier,
    STATE(32), 7,
      sym__expression,
      sym_logical_expression,
      sym_parenthesis_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__literal,
      sym_date_and_time,
    ACTIONS(111), 9,
      sym_floating_point,
      sym_binary,
      sym_octal,
      sym_hexidecimal,
      sym_time,
      sym_date,
      sym_time_of_day,
      sym_string,
      sym_wstring,
  [1046] = 9,
    ACTIONS(11), 1,
      anon_sym_LPAREN,
    ACTIONS(17), 1,
      anon_sym_NOT,
    ACTIONS(25), 1,
      anon_sym_DT_POUND,
    STATE(184), 1,
      sym_logical_operator,
    ACTIONS(19), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(15), 3,
      anon_sym_AND,
      anon_sym_OR,
      anon_sym_XOR,
    ACTIONS(113), 3,
      sym_boolean,
      sym_integer,
      sym_identifier,
    STATE(43), 7,
      sym__expression,
      sym_logical_expression,
      sym_parenthesis_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__literal,
      sym_date_and_time,
    ACTIONS(115), 9,
      sym_floating_point,
      sym_binary,
      sym_octal,
      sym_hexidecimal,
      sym_time,
      sym_date,
      sym_time_of_day,
      sym_string,
      sym_wstring,
  [1093] = 2,
    ACTIONS(119), 3,
      anon_sym_STAR,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(117), 16,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_THEN,
      anon_sym_AND,
      anon_sym_OR,
      anon_sym_XOR,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR_STAR,
      anon_sym_SLASH,
      anon_sym_MOD,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ,
      anon_sym_LT_GT,
  [1117] = 2,
    ACTIONS(123), 3,
      anon_sym_STAR,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(121), 16,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_THEN,
      anon_sym_AND,
      anon_sym_OR,
      anon_sym_XOR,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR_STAR,
      anon_sym_SLASH,
      anon_sym_MOD,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ,
      anon_sym_LT_GT,
  [1141] = 3,
    ACTIONS(125), 1,
      anon_sym_STAR_STAR,
    ACTIONS(123), 3,
      anon_sym_STAR,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(121), 15,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_THEN,
      anon_sym_AND,
      anon_sym_OR,
      anon_sym_XOR,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_SLASH,
      anon_sym_MOD,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ,
      anon_sym_LT_GT,
  [1167] = 2,
    ACTIONS(129), 3,
      anon_sym_STAR,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(127), 16,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_THEN,
      anon_sym_AND,
      anon_sym_OR,
      anon_sym_XOR,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR_STAR,
      anon_sym_SLASH,
      anon_sym_MOD,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ,
      anon_sym_LT_GT,
  [1191] = 6,
    ACTIONS(125), 1,
      anon_sym_STAR_STAR,
    ACTIONS(133), 1,
      anon_sym_STAR,
    ACTIONS(123), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(131), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(135), 2,
      anon_sym_SLASH,
      anon_sym_MOD,
    ACTIONS(121), 11,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_THEN,
      anon_sym_AND,
      anon_sym_OR,
      anon_sym_XOR,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ,
      anon_sym_LT_GT,
  [1223] = 2,
    ACTIONS(139), 3,
      anon_sym_STAR,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(137), 16,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_THEN,
      anon_sym_AND,
      anon_sym_OR,
      anon_sym_XOR,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR_STAR,
      anon_sym_SLASH,
      anon_sym_MOD,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ,
      anon_sym_LT_GT,
  [1247] = 7,
    ACTIONS(125), 1,
      anon_sym_STAR_STAR,
    ACTIONS(133), 1,
      anon_sym_STAR,
    ACTIONS(131), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(135), 2,
      anon_sym_SLASH,
      anon_sym_MOD,
    ACTIONS(141), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(143), 2,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(121), 9,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_THEN,
      anon_sym_AND,
      anon_sym_OR,
      anon_sym_XOR,
      anon_sym_EQ,
      anon_sym_LT_GT,
  [1281] = 5,
    ACTIONS(125), 1,
      anon_sym_STAR_STAR,
    ACTIONS(133), 1,
      anon_sym_STAR,
    ACTIONS(123), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(135), 2,
      anon_sym_SLASH,
      anon_sym_MOD,
    ACTIONS(121), 13,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_THEN,
      anon_sym_AND,
      anon_sym_OR,
      anon_sym_XOR,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ,
      anon_sym_LT_GT,
  [1311] = 2,
    ACTIONS(147), 3,
      anon_sym_STAR,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(145), 16,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_THEN,
      anon_sym_AND,
      anon_sym_OR,
      anon_sym_XOR,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR_STAR,
      anon_sym_SLASH,
      anon_sym_MOD,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ,
      anon_sym_LT_GT,
  [1335] = 8,
    ACTIONS(125), 1,
      anon_sym_STAR_STAR,
    ACTIONS(133), 1,
      anon_sym_STAR,
    ACTIONS(131), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(135), 2,
      anon_sym_SLASH,
      anon_sym_MOD,
    ACTIONS(141), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(143), 2,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(149), 2,
      anon_sym_EQ,
      anon_sym_LT_GT,
    ACTIONS(121), 7,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_THEN,
      anon_sym_AND,
      anon_sym_OR,
      anon_sym_XOR,
  [1371] = 10,
    ACTIONS(151), 1,
      anon_sym_END_PROGRAM,
    ACTIONS(153), 1,
      anon_sym_VAR,
    ACTIONS(155), 1,
      anon_sym_VAR_INPUT,
    ACTIONS(157), 1,
      anon_sym_VAR_OUTPUT,
    ACTIONS(159), 1,
      anon_sym_VAR_CONSTANT,
    ACTIONS(161), 1,
      anon_sym_IF,
    ACTIONS(163), 1,
      sym_identifier,
    STATE(60), 2,
      sym_variable_block,
      aux_sym_program_repeat1,
    STATE(84), 4,
      sym_var_block,
      sym_var_input_block,
      sym_var_output_block,
      sym_var_constant_block,
    STATE(77), 5,
      sym__statement,
      sym_assignment,
      sym_function_call,
      sym_if_statement,
      aux_sym_program_repeat2,
  [1410] = 11,
    ACTIONS(125), 1,
      anon_sym_STAR_STAR,
    ACTIONS(133), 1,
      anon_sym_STAR,
    ACTIONS(165), 1,
      anon_sym_COMMA,
    ACTIONS(167), 1,
      anon_sym_RPAREN,
    STATE(147), 1,
      aux_sym_function_call_repeat1,
    ACTIONS(131), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(135), 2,
      anon_sym_SLASH,
      anon_sym_MOD,
    ACTIONS(141), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(143), 2,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(149), 2,
      anon_sym_EQ,
      anon_sym_LT_GT,
    ACTIONS(169), 3,
      anon_sym_AND,
      anon_sym_OR,
      anon_sym_XOR,
  [1451] = 11,
    ACTIONS(125), 1,
      anon_sym_STAR_STAR,
    ACTIONS(133), 1,
      anon_sym_STAR,
    ACTIONS(165), 1,
      anon_sym_COMMA,
    ACTIONS(171), 1,
      anon_sym_RPAREN,
    STATE(140), 1,
      aux_sym_function_call_repeat1,
    ACTIONS(131), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(135), 2,
      anon_sym_SLASH,
      anon_sym_MOD,
    ACTIONS(141), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(143), 2,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(149), 2,
      anon_sym_EQ,
      anon_sym_LT_GT,
    ACTIONS(169), 3,
      anon_sym_AND,
      anon_sym_OR,
      anon_sym_XOR,
  [1492] = 11,
    ACTIONS(125), 1,
      anon_sym_STAR_STAR,
    ACTIONS(133), 1,
      anon_sym_STAR,
    ACTIONS(165), 1,
      anon_sym_COMMA,
    ACTIONS(173), 1,
      anon_sym_RPAREN,
    STATE(170), 1,
      aux_sym_function_call_repeat1,
    ACTIONS(131), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(135), 2,
      anon_sym_SLASH,
      anon_sym_MOD,
    ACTIONS(141), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(143), 2,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(149), 2,
      anon_sym_EQ,
      anon_sym_LT_GT,
    ACTIONS(169), 3,
      anon_sym_AND,
      anon_sym_OR,
      anon_sym_XOR,
  [1533] = 11,
    ACTIONS(125), 1,
      anon_sym_STAR_STAR,
    ACTIONS(133), 1,
      anon_sym_STAR,
    ACTIONS(165), 1,
      anon_sym_COMMA,
    ACTIONS(175), 1,
      anon_sym_RPAREN,
    STATE(145), 1,
      aux_sym_function_call_repeat1,
    ACTIONS(131), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(135), 2,
      anon_sym_SLASH,
      anon_sym_MOD,
    ACTIONS(141), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(143), 2,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(149), 2,
      anon_sym_EQ,
      anon_sym_LT_GT,
    ACTIONS(169), 3,
      anon_sym_AND,
      anon_sym_OR,
      anon_sym_XOR,
  [1574] = 10,
    ACTIONS(153), 1,
      anon_sym_VAR,
    ACTIONS(155), 1,
      anon_sym_VAR_INPUT,
    ACTIONS(157), 1,
      anon_sym_VAR_OUTPUT,
    ACTIONS(159), 1,
      anon_sym_VAR_CONSTANT,
    ACTIONS(161), 1,
      anon_sym_IF,
    ACTIONS(163), 1,
      sym_identifier,
    ACTIONS(177), 1,
      anon_sym_END_PROGRAM,
    STATE(35), 2,
      sym_variable_block,
      aux_sym_program_repeat1,
    STATE(84), 4,
      sym_var_block,
      sym_var_input_block,
      sym_var_output_block,
      sym_var_constant_block,
    STATE(72), 5,
      sym__statement,
      sym_assignment,
      sym_function_call,
      sym_if_statement,
      aux_sym_program_repeat2,
  [1613] = 9,
    ACTIONS(125), 1,
      anon_sym_STAR_STAR,
    ACTIONS(133), 1,
      anon_sym_STAR,
    ACTIONS(131), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(135), 2,
      anon_sym_SLASH,
      anon_sym_MOD,
    ACTIONS(141), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(143), 2,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(149), 2,
      anon_sym_EQ,
      anon_sym_LT_GT,
    ACTIONS(179), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
    ACTIONS(169), 3,
      anon_sym_AND,
      anon_sym_OR,
      anon_sym_XOR,
  [1649] = 9,
    ACTIONS(125), 1,
      anon_sym_STAR_STAR,
    ACTIONS(133), 1,
      anon_sym_STAR,
    ACTIONS(181), 1,
      anon_sym_SEMI,
    ACTIONS(131), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(135), 2,
      anon_sym_SLASH,
      anon_sym_MOD,
    ACTIONS(141), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(143), 2,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(149), 2,
      anon_sym_EQ,
      anon_sym_LT_GT,
    ACTIONS(169), 3,
      anon_sym_AND,
      anon_sym_OR,
      anon_sym_XOR,
  [1684] = 9,
    ACTIONS(125), 1,
      anon_sym_STAR_STAR,
    ACTIONS(133), 1,
      anon_sym_STAR,
    ACTIONS(183), 1,
      anon_sym_RPAREN,
    ACTIONS(131), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(135), 2,
      anon_sym_SLASH,
      anon_sym_MOD,
    ACTIONS(141), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(143), 2,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(149), 2,
      anon_sym_EQ,
      anon_sym_LT_GT,
    ACTIONS(169), 3,
      anon_sym_AND,
      anon_sym_OR,
      anon_sym_XOR,
  [1719] = 9,
    ACTIONS(125), 1,
      anon_sym_STAR_STAR,
    ACTIONS(133), 1,
      anon_sym_STAR,
    ACTIONS(185), 1,
      anon_sym_THEN,
    ACTIONS(131), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(135), 2,
      anon_sym_SLASH,
      anon_sym_MOD,
    ACTIONS(141), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(143), 2,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(149), 2,
      anon_sym_EQ,
      anon_sym_LT_GT,
    ACTIONS(169), 3,
      anon_sym_AND,
      anon_sym_OR,
      anon_sym_XOR,
  [1754] = 9,
    ACTIONS(125), 1,
      anon_sym_STAR_STAR,
    ACTIONS(133), 1,
      anon_sym_STAR,
    ACTIONS(187), 1,
      anon_sym_THEN,
    ACTIONS(131), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(135), 2,
      anon_sym_SLASH,
      anon_sym_MOD,
    ACTIONS(141), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(143), 2,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(149), 2,
      anon_sym_EQ,
      anon_sym_LT_GT,
    ACTIONS(169), 3,
      anon_sym_AND,
      anon_sym_OR,
      anon_sym_XOR,
  [1789] = 9,
    ACTIONS(125), 1,
      anon_sym_STAR_STAR,
    ACTIONS(133), 1,
      anon_sym_STAR,
    ACTIONS(189), 1,
      anon_sym_THEN,
    ACTIONS(131), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(135), 2,
      anon_sym_SLASH,
      anon_sym_MOD,
    ACTIONS(141), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(143), 2,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(149), 2,
      anon_sym_EQ,
      anon_sym_LT_GT,
    ACTIONS(169), 3,
      anon_sym_AND,
      anon_sym_OR,
      anon_sym_XOR,
  [1824] = 9,
    ACTIONS(125), 1,
      anon_sym_STAR_STAR,
    ACTIONS(133), 1,
      anon_sym_STAR,
    ACTIONS(191), 1,
      anon_sym_THEN,
    ACTIONS(131), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(135), 2,
      anon_sym_SLASH,
      anon_sym_MOD,
    ACTIONS(141), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(143), 2,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(149), 2,
      anon_sym_EQ,
      anon_sym_LT_GT,
    ACTIONS(169), 3,
      anon_sym_AND,
      anon_sym_OR,
      anon_sym_XOR,
  [1859] = 9,
    ACTIONS(125), 1,
      anon_sym_STAR_STAR,
    ACTIONS(133), 1,
      anon_sym_STAR,
    ACTIONS(193), 1,
      anon_sym_SEMI,
    ACTIONS(131), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(135), 2,
      anon_sym_SLASH,
      anon_sym_MOD,
    ACTIONS(141), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(143), 2,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(149), 2,
      anon_sym_EQ,
      anon_sym_LT_GT,
    ACTIONS(169), 3,
      anon_sym_AND,
      anon_sym_OR,
      anon_sym_XOR,
  [1894] = 9,
    ACTIONS(125), 1,
      anon_sym_STAR_STAR,
    ACTIONS(133), 1,
      anon_sym_STAR,
    ACTIONS(195), 1,
      anon_sym_SEMI,
    ACTIONS(131), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(135), 2,
      anon_sym_SLASH,
      anon_sym_MOD,
    ACTIONS(141), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(143), 2,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(149), 2,
      anon_sym_EQ,
      anon_sym_LT_GT,
    ACTIONS(169), 3,
      anon_sym_AND,
      anon_sym_OR,
      anon_sym_XOR,
  [1929] = 9,
    ACTIONS(125), 1,
      anon_sym_STAR_STAR,
    ACTIONS(133), 1,
      anon_sym_STAR,
    ACTIONS(197), 1,
      anon_sym_SEMI,
    ACTIONS(131), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(135), 2,
      anon_sym_SLASH,
      anon_sym_MOD,
    ACTIONS(141), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(143), 2,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(149), 2,
      anon_sym_EQ,
      anon_sym_LT_GT,
    ACTIONS(169), 3,
      anon_sym_AND,
      anon_sym_OR,
      anon_sym_XOR,
  [1964] = 9,
    ACTIONS(125), 1,
      anon_sym_STAR_STAR,
    ACTIONS(133), 1,
      anon_sym_STAR,
    ACTIONS(199), 1,
      anon_sym_THEN,
    ACTIONS(131), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(135), 2,
      anon_sym_SLASH,
      anon_sym_MOD,
    ACTIONS(141), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(143), 2,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(149), 2,
      anon_sym_EQ,
      anon_sym_LT_GT,
    ACTIONS(169), 3,
      anon_sym_AND,
      anon_sym_OR,
      anon_sym_XOR,
  [1999] = 8,
    ACTIONS(201), 1,
      anon_sym_END_FUNCTION_BLOCK,
    ACTIONS(203), 1,
      anon_sym_VAR,
    ACTIONS(205), 1,
      anon_sym_VAR_INPUT,
    ACTIONS(207), 1,
      anon_sym_VAR_OUTPUT,
    ACTIONS(209), 1,
      anon_sym_IF,
    ACTIONS(211), 1,
      sym_identifier,
    STATE(53), 4,
      sym_var_block,
      sym_var_input_block,
      sym_var_output_block,
      aux_sym_function_block_repeat1,
    STATE(69), 5,
      sym__statement,
      sym_assignment,
      sym_function_call,
      sym_if_statement,
      aux_sym_program_repeat2,
  [2031] = 8,
    ACTIONS(203), 1,
      anon_sym_VAR,
    ACTIONS(205), 1,
      anon_sym_VAR_INPUT,
    ACTIONS(207), 1,
      anon_sym_VAR_OUTPUT,
    ACTIONS(209), 1,
      anon_sym_IF,
    ACTIONS(211), 1,
      sym_identifier,
    ACTIONS(213), 1,
      anon_sym_END_FUNCTION_BLOCK,
    STATE(66), 4,
      sym_var_block,
      sym_var_input_block,
      sym_var_output_block,
      aux_sym_function_block_repeat1,
    STATE(73), 5,
      sym__statement,
      sym_assignment,
      sym_function_call,
      sym_if_statement,
      aux_sym_program_repeat2,
  [2063] = 8,
    ACTIONS(215), 1,
      anon_sym_IF,
    ACTIONS(217), 1,
      anon_sym_END_IF,
    ACTIONS(219), 1,
      anon_sym_ELSIF,
    ACTIONS(221), 1,
      anon_sym_ELSE,
    ACTIONS(223), 1,
      sym_identifier,
    STATE(190), 1,
      sym_else_clause,
    STATE(96), 2,
      sym_elsif_clause,
      aux_sym_if_statement_repeat1,
    STATE(56), 5,
      sym__statement,
      sym_assignment,
      sym_function_call,
      sym_if_statement,
      aux_sym_program_repeat2,
  [2093] = 8,
    ACTIONS(215), 1,
      anon_sym_IF,
    ACTIONS(219), 1,
      anon_sym_ELSIF,
    ACTIONS(221), 1,
      anon_sym_ELSE,
    ACTIONS(223), 1,
      sym_identifier,
    ACTIONS(225), 1,
      anon_sym_END_IF,
    STATE(237), 1,
      sym_else_clause,
    STATE(95), 2,
      sym_elsif_clause,
      aux_sym_if_statement_repeat1,
    STATE(57), 5,
      sym__statement,
      sym_assignment,
      sym_function_call,
      sym_if_statement,
      aux_sym_program_repeat2,
  [2123] = 8,
    ACTIONS(215), 1,
      anon_sym_IF,
    ACTIONS(219), 1,
      anon_sym_ELSIF,
    ACTIONS(221), 1,
      anon_sym_ELSE,
    ACTIONS(223), 1,
      sym_identifier,
    ACTIONS(227), 1,
      anon_sym_END_IF,
    STATE(193), 1,
      sym_else_clause,
    STATE(103), 2,
      sym_elsif_clause,
      aux_sym_if_statement_repeat1,
    STATE(63), 5,
      sym__statement,
      sym_assignment,
      sym_function_call,
      sym_if_statement,
      aux_sym_program_repeat2,
  [2153] = 8,
    ACTIONS(215), 1,
      anon_sym_IF,
    ACTIONS(219), 1,
      anon_sym_ELSIF,
    ACTIONS(221), 1,
      anon_sym_ELSE,
    ACTIONS(223), 1,
      sym_identifier,
    ACTIONS(229), 1,
      anon_sym_END_IF,
    STATE(240), 1,
      sym_else_clause,
    STATE(102), 2,
      sym_elsif_clause,
      aux_sym_if_statement_repeat1,
    STATE(63), 5,
      sym__statement,
      sym_assignment,
      sym_function_call,
      sym_if_statement,
      aux_sym_program_repeat2,
  [2183] = 8,
    ACTIONS(215), 1,
      anon_sym_IF,
    ACTIONS(219), 1,
      anon_sym_ELSIF,
    ACTIONS(221), 1,
      anon_sym_ELSE,
    ACTIONS(223), 1,
      sym_identifier,
    ACTIONS(231), 1,
      anon_sym_END_IF,
    STATE(228), 1,
      sym_else_clause,
    STATE(104), 2,
      sym_elsif_clause,
      aux_sym_if_statement_repeat1,
    STATE(59), 5,
      sym__statement,
      sym_assignment,
      sym_function_call,
      sym_if_statement,
      aux_sym_program_repeat2,
  [2213] = 8,
    ACTIONS(215), 1,
      anon_sym_IF,
    ACTIONS(219), 1,
      anon_sym_ELSIF,
    ACTIONS(221), 1,
      anon_sym_ELSE,
    ACTIONS(223), 1,
      sym_identifier,
    ACTIONS(233), 1,
      anon_sym_END_IF,
    STATE(231), 1,
      sym_else_clause,
    STATE(93), 2,
      sym_elsif_clause,
      aux_sym_if_statement_repeat1,
    STATE(63), 5,
      sym__statement,
      sym_assignment,
      sym_function_call,
      sym_if_statement,
      aux_sym_program_repeat2,
  [2243] = 7,
    ACTIONS(237), 1,
      anon_sym_VAR,
    ACTIONS(240), 1,
      anon_sym_VAR_INPUT,
    ACTIONS(243), 1,
      anon_sym_VAR_OUTPUT,
    ACTIONS(246), 1,
      anon_sym_VAR_CONSTANT,
    STATE(60), 2,
      sym_variable_block,
      aux_sym_program_repeat1,
    ACTIONS(235), 3,
      anon_sym_END_PROGRAM,
      anon_sym_IF,
      sym_identifier,
    STATE(84), 4,
      sym_var_block,
      sym_var_input_block,
      sym_var_output_block,
      sym_var_constant_block,
  [2271] = 8,
    ACTIONS(215), 1,
      anon_sym_IF,
    ACTIONS(219), 1,
      anon_sym_ELSIF,
    ACTIONS(221), 1,
      anon_sym_ELSE,
    ACTIONS(223), 1,
      sym_identifier,
    ACTIONS(249), 1,
      anon_sym_END_IF,
    STATE(222), 1,
      sym_else_clause,
    STATE(92), 2,
      sym_elsif_clause,
      aux_sym_if_statement_repeat1,
    STATE(63), 5,
      sym__statement,
      sym_assignment,
      sym_function_call,
      sym_if_statement,
      aux_sym_program_repeat2,
  [2301] = 8,
    ACTIONS(215), 1,
      anon_sym_IF,
    ACTIONS(219), 1,
      anon_sym_ELSIF,
    ACTIONS(221), 1,
      anon_sym_ELSE,
    ACTIONS(223), 1,
      sym_identifier,
    ACTIONS(251), 1,
      anon_sym_END_IF,
    STATE(219), 1,
      sym_else_clause,
    STATE(94), 2,
      sym_elsif_clause,
      aux_sym_if_statement_repeat1,
    STATE(61), 5,
      sym__statement,
      sym_assignment,
      sym_function_call,
      sym_if_statement,
      aux_sym_program_repeat2,
  [2331] = 4,
    ACTIONS(253), 1,
      anon_sym_IF,
    ACTIONS(258), 1,
      sym_identifier,
    ACTIONS(256), 3,
      anon_sym_END_IF,
      anon_sym_ELSIF,
      anon_sym_ELSE,
    STATE(63), 5,
      sym__statement,
      sym_assignment,
      sym_function_call,
      sym_if_statement,
      aux_sym_program_repeat2,
  [2350] = 4,
    ACTIONS(215), 1,
      anon_sym_IF,
    ACTIONS(223), 1,
      sym_identifier,
    ACTIONS(261), 3,
      anon_sym_END_IF,
      anon_sym_ELSIF,
      anon_sym_ELSE,
    STATE(65), 5,
      sym__statement,
      sym_assignment,
      sym_function_call,
      sym_if_statement,
      aux_sym_program_repeat2,
  [2369] = 4,
    ACTIONS(215), 1,
      anon_sym_IF,
    ACTIONS(223), 1,
      sym_identifier,
    ACTIONS(263), 3,
      anon_sym_END_IF,
      anon_sym_ELSIF,
      anon_sym_ELSE,
    STATE(63), 5,
      sym__statement,
      sym_assignment,
      sym_function_call,
      sym_if_statement,
      aux_sym_program_repeat2,
  [2388] = 5,
    ACTIONS(267), 1,
      anon_sym_VAR,
    ACTIONS(270), 1,
      anon_sym_VAR_INPUT,
    ACTIONS(273), 1,
      anon_sym_VAR_OUTPUT,
    ACTIONS(265), 3,
      anon_sym_END_FUNCTION_BLOCK,
      anon_sym_IF,
      sym_identifier,
    STATE(66), 4,
      sym_var_block,
      sym_var_input_block,
      sym_var_output_block,
      aux_sym_function_block_repeat1,
  [2409] = 6,
    ACTIONS(278), 1,
      aux_sym_number_token1,
    ACTIONS(280), 1,
      aux_sym_number_token2,
    STATE(225), 1,
      sym_constant_expression,
    ACTIONS(276), 2,
      sym_address,
      sym_time_literal,
    ACTIONS(282), 2,
      anon_sym_TRUE,
      anon_sym_FALSE,
    STATE(204), 2,
      sym_number,
      sym_bool_literal,
  [2431] = 6,
    ACTIONS(278), 1,
      aux_sym_number_token1,
    ACTIONS(280), 1,
      aux_sym_number_token2,
    STATE(244), 1,
      sym_constant_expression,
    ACTIONS(276), 2,
      sym_address,
      sym_time_literal,
    ACTIONS(282), 2,
      anon_sym_TRUE,
      anon_sym_FALSE,
    STATE(204), 2,
      sym_number,
      sym_bool_literal,
  [2453] = 4,
    ACTIONS(209), 1,
      anon_sym_IF,
    ACTIONS(211), 1,
      sym_identifier,
    ACTIONS(213), 1,
      anon_sym_END_FUNCTION_BLOCK,
    STATE(71), 5,
      sym__statement,
      sym_assignment,
      sym_function_call,
      sym_if_statement,
      aux_sym_program_repeat2,
  [2470] = 4,
    ACTIONS(284), 1,
      anon_sym_IF,
    ACTIONS(286), 1,
      anon_sym_END_IF,
    ACTIONS(288), 1,
      sym_identifier,
    STATE(75), 5,
      sym__statement,
      sym_assignment,
      sym_function_call,
      sym_if_statement,
      aux_sym_program_repeat2,
  [2487] = 4,
    ACTIONS(256), 1,
      anon_sym_END_FUNCTION_BLOCK,
    ACTIONS(290), 1,
      anon_sym_IF,
    ACTIONS(293), 1,
      sym_identifier,
    STATE(71), 5,
      sym__statement,
      sym_assignment,
      sym_function_call,
      sym_if_statement,
      aux_sym_program_repeat2,
  [2504] = 4,
    ACTIONS(151), 1,
      anon_sym_END_PROGRAM,
    ACTIONS(161), 1,
      anon_sym_IF,
    ACTIONS(163), 1,
      sym_identifier,
    STATE(76), 5,
      sym__statement,
      sym_assignment,
      sym_function_call,
      sym_if_statement,
      aux_sym_program_repeat2,
  [2521] = 4,
    ACTIONS(209), 1,
      anon_sym_IF,
    ACTIONS(211), 1,
      sym_identifier,
    ACTIONS(296), 1,
      anon_sym_END_FUNCTION_BLOCK,
    STATE(71), 5,
      sym__statement,
      sym_assignment,
      sym_function_call,
      sym_if_statement,
      aux_sym_program_repeat2,
  [2538] = 5,
    ACTIONS(298), 1,
      ts_builtin_sym_end,
    ACTIONS(300), 1,
      anon_sym_PROGRAM,
    ACTIONS(303), 1,
      anon_sym_CONFIGURATION,
    ACTIONS(306), 1,
      anon_sym_FUNCTION_BLOCK,
    STATE(74), 4,
      sym_program,
      sym_configuration,
      sym_function_block,
      aux_sym_source_file_repeat1,
  [2557] = 4,
    ACTIONS(256), 1,
      anon_sym_END_IF,
    ACTIONS(309), 1,
      anon_sym_IF,
    ACTIONS(312), 1,
      sym_identifier,
    STATE(75), 5,
      sym__statement,
      sym_assignment,
      sym_function_call,
      sym_if_statement,
      aux_sym_program_repeat2,
  [2574] = 4,
    ACTIONS(256), 1,
      anon_sym_END_PROGRAM,
    ACTIONS(315), 1,
      anon_sym_IF,
    ACTIONS(318), 1,
      sym_identifier,
    STATE(76), 5,
      sym__statement,
      sym_assignment,
      sym_function_call,
      sym_if_statement,
      aux_sym_program_repeat2,
  [2591] = 4,
    ACTIONS(161), 1,
      anon_sym_IF,
    ACTIONS(163), 1,
      sym_identifier,
    ACTIONS(321), 1,
      anon_sym_END_PROGRAM,
    STATE(76), 5,
      sym__statement,
      sym_assignment,
      sym_function_call,
      sym_if_statement,
      aux_sym_program_repeat2,
  [2608] = 4,
    ACTIONS(284), 1,
      anon_sym_IF,
    ACTIONS(288), 1,
      sym_identifier,
    ACTIONS(323), 1,
      anon_sym_END_IF,
    STATE(70), 5,
      sym__statement,
      sym_assignment,
      sym_function_call,
      sym_if_statement,
      aux_sym_program_repeat2,
  [2625] = 5,
    ACTIONS(5), 1,
      anon_sym_PROGRAM,
    ACTIONS(7), 1,
      anon_sym_CONFIGURATION,
    ACTIONS(9), 1,
      anon_sym_FUNCTION_BLOCK,
    ACTIONS(325), 1,
      ts_builtin_sym_end,
    STATE(74), 4,
      sym_program,
      sym_configuration,
      sym_function_block,
      aux_sym_source_file_repeat1,
  [2644] = 1,
    ACTIONS(327), 7,
      anon_sym_END_PROGRAM,
      anon_sym_VAR,
      anon_sym_VAR_INPUT,
      anon_sym_VAR_OUTPUT,
      anon_sym_VAR_CONSTANT,
      anon_sym_IF,
      sym_identifier,
  [2654] = 4,
    ACTIONS(329), 1,
      anon_sym_PROGRAM,
    ACTIONS(331), 1,
      anon_sym_END_RESOURCE,
    ACTIONS(333), 1,
      anon_sym_TASK,
    STATE(82), 4,
      sym__resource_element,
      sym_task,
      sym_program_instance,
      aux_sym_configuration_repeat1,
  [2670] = 4,
    ACTIONS(329), 1,
      anon_sym_PROGRAM,
    ACTIONS(333), 1,
      anon_sym_TASK,
    ACTIONS(335), 1,
      anon_sym_END_RESOURCE,
    STATE(83), 4,
      sym__resource_element,
      sym_task,
      sym_program_instance,
      aux_sym_configuration_repeat1,
  [2686] = 4,
    ACTIONS(337), 1,
      anon_sym_PROGRAM,
    ACTIONS(340), 1,
      anon_sym_END_RESOURCE,
    ACTIONS(342), 1,
      anon_sym_TASK,
    STATE(83), 4,
      sym__resource_element,
      sym_task,
      sym_program_instance,
      aux_sym_configuration_repeat1,
  [2702] = 1,
    ACTIONS(345), 7,
      anon_sym_END_PROGRAM,
      anon_sym_VAR,
      anon_sym_VAR_INPUT,
      anon_sym_VAR_OUTPUT,
      anon_sym_VAR_CONSTANT,
      anon_sym_IF,
      sym_identifier,
  [2712] = 1,
    ACTIONS(347), 7,
      anon_sym_END_PROGRAM,
      anon_sym_VAR,
      anon_sym_VAR_INPUT,
      anon_sym_VAR_OUTPUT,
      anon_sym_VAR_CONSTANT,
      anon_sym_IF,
      sym_identifier,
  [2722] = 1,
    ACTIONS(349), 7,
      anon_sym_END_PROGRAM,
      anon_sym_VAR,
      anon_sym_VAR_INPUT,
      anon_sym_VAR_OUTPUT,
      anon_sym_VAR_CONSTANT,
      anon_sym_IF,
      sym_identifier,
  [2732] = 1,
    ACTIONS(351), 7,
      anon_sym_END_PROGRAM,
      anon_sym_VAR,
      anon_sym_VAR_INPUT,
      anon_sym_VAR_OUTPUT,
      anon_sym_VAR_CONSTANT,
      anon_sym_IF,
      sym_identifier,
  [2742] = 1,
    ACTIONS(353), 7,
      anon_sym_END_PROGRAM,
      anon_sym_VAR,
      anon_sym_VAR_INPUT,
      anon_sym_VAR_OUTPUT,
      anon_sym_VAR_CONSTANT,
      anon_sym_IF,
      sym_identifier,
  [2752] = 1,
    ACTIONS(355), 7,
      anon_sym_END_PROGRAM,
      anon_sym_VAR,
      anon_sym_VAR_INPUT,
      anon_sym_VAR_OUTPUT,
      anon_sym_VAR_CONSTANT,
      anon_sym_IF,
      sym_identifier,
  [2762] = 1,
    ACTIONS(357), 7,
      anon_sym_END_PROGRAM,
      anon_sym_VAR,
      anon_sym_VAR_INPUT,
      anon_sym_VAR_OUTPUT,
      anon_sym_VAR_CONSTANT,
      anon_sym_IF,
      sym_identifier,
  [2772] = 1,
    ACTIONS(359), 7,
      anon_sym_END_PROGRAM,
      anon_sym_VAR,
      anon_sym_VAR_INPUT,
      anon_sym_VAR_OUTPUT,
      anon_sym_VAR_CONSTANT,
      anon_sym_IF,
      sym_identifier,
  [2782] = 5,
    ACTIONS(361), 1,
      anon_sym_END_IF,
    ACTIONS(363), 1,
      anon_sym_ELSIF,
    ACTIONS(365), 1,
      anon_sym_ELSE,
    STATE(224), 1,
      sym_else_clause,
    STATE(107), 2,
      sym_elsif_clause,
      aux_sym_if_statement_repeat1,
  [2799] = 5,
    ACTIONS(363), 1,
      anon_sym_ELSIF,
    ACTIONS(365), 1,
      anon_sym_ELSE,
    ACTIONS(367), 1,
      anon_sym_END_IF,
    STATE(233), 1,
      sym_else_clause,
    STATE(107), 2,
      sym_elsif_clause,
      aux_sym_if_statement_repeat1,
  [2816] = 5,
    ACTIONS(363), 1,
      anon_sym_ELSIF,
    ACTIONS(365), 1,
      anon_sym_ELSE,
    ACTIONS(369), 1,
      anon_sym_END_IF,
    STATE(222), 1,
      sym_else_clause,
    STATE(107), 2,
      sym_elsif_clause,
      aux_sym_if_statement_repeat1,
  [2833] = 5,
    ACTIONS(363), 1,
      anon_sym_ELSIF,
    ACTIONS(365), 1,
      anon_sym_ELSE,
    ACTIONS(371), 1,
      anon_sym_END_IF,
    STATE(240), 1,
      sym_else_clause,
    STATE(107), 2,
      sym_elsif_clause,
      aux_sym_if_statement_repeat1,
  [2850] = 5,
    ACTIONS(363), 1,
      anon_sym_ELSIF,
    ACTIONS(365), 1,
      anon_sym_ELSE,
    ACTIONS(373), 1,
      anon_sym_END_IF,
    STATE(193), 1,
      sym_else_clause,
    STATE(107), 2,
      sym_elsif_clause,
      aux_sym_if_statement_repeat1,
  [2867] = 1,
    ACTIONS(347), 6,
      anon_sym_END_FUNCTION_BLOCK,
      anon_sym_VAR,
      anon_sym_VAR_INPUT,
      anon_sym_VAR_OUTPUT,
      anon_sym_IF,
      sym_identifier,
  [2876] = 1,
    ACTIONS(327), 6,
      anon_sym_END_FUNCTION_BLOCK,
      anon_sym_VAR,
      anon_sym_VAR_INPUT,
      anon_sym_VAR_OUTPUT,
      anon_sym_IF,
      sym_identifier,
  [2885] = 1,
    ACTIONS(357), 6,
      anon_sym_END_FUNCTION_BLOCK,
      anon_sym_VAR,
      anon_sym_VAR_INPUT,
      anon_sym_VAR_OUTPUT,
      anon_sym_IF,
      sym_identifier,
  [2894] = 1,
    ACTIONS(349), 6,
      anon_sym_END_FUNCTION_BLOCK,
      anon_sym_VAR,
      anon_sym_VAR_INPUT,
      anon_sym_VAR_OUTPUT,
      anon_sym_IF,
      sym_identifier,
  [2903] = 1,
    ACTIONS(359), 6,
      anon_sym_END_FUNCTION_BLOCK,
      anon_sym_VAR,
      anon_sym_VAR_INPUT,
      anon_sym_VAR_OUTPUT,
      anon_sym_IF,
      sym_identifier,
  [2912] = 5,
    ACTIONS(363), 1,
      anon_sym_ELSIF,
    ACTIONS(365), 1,
      anon_sym_ELSE,
    ACTIONS(375), 1,
      anon_sym_END_IF,
    STATE(242), 1,
      sym_else_clause,
    STATE(107), 2,
      sym_elsif_clause,
      aux_sym_if_statement_repeat1,
  [2929] = 5,
    ACTIONS(363), 1,
      anon_sym_ELSIF,
    ACTIONS(365), 1,
      anon_sym_ELSE,
    ACTIONS(377), 1,
      anon_sym_END_IF,
    STATE(241), 1,
      sym_else_clause,
    STATE(107), 2,
      sym_elsif_clause,
      aux_sym_if_statement_repeat1,
  [2946] = 5,
    ACTIONS(363), 1,
      anon_sym_ELSIF,
    ACTIONS(365), 1,
      anon_sym_ELSE,
    ACTIONS(379), 1,
      anon_sym_END_IF,
    STATE(231), 1,
      sym_else_clause,
    STATE(107), 2,
      sym_elsif_clause,
      aux_sym_if_statement_repeat1,
  [2963] = 1,
    ACTIONS(351), 6,
      anon_sym_END_FUNCTION_BLOCK,
      anon_sym_VAR,
      anon_sym_VAR_INPUT,
      anon_sym_VAR_OUTPUT,
      anon_sym_IF,
      sym_identifier,
  [2972] = 1,
    ACTIONS(381), 5,
      anon_sym_IF,
      anon_sym_END_IF,
      anon_sym_ELSIF,
      anon_sym_ELSE,
      sym_identifier,
  [2980] = 3,
    ACTIONS(385), 1,
      anon_sym_ELSIF,
    ACTIONS(383), 2,
      anon_sym_END_IF,
      anon_sym_ELSE,
    STATE(107), 2,
      sym_elsif_clause,
      aux_sym_if_statement_repeat1,
  [2992] = 1,
    ACTIONS(388), 5,
      anon_sym_IF,
      anon_sym_END_IF,
      anon_sym_ELSIF,
      anon_sym_ELSE,
      sym_identifier,
  [3000] = 1,
    ACTIONS(390), 5,
      anon_sym_IF,
      anon_sym_END_IF,
      anon_sym_ELSIF,
      anon_sym_ELSE,
      sym_identifier,
  [3008] = 1,
    ACTIONS(392), 5,
      anon_sym_IF,
      anon_sym_END_IF,
      anon_sym_ELSIF,
      anon_sym_ELSE,
      sym_identifier,
  [3016] = 1,
    ACTIONS(394), 5,
      anon_sym_IF,
      anon_sym_END_IF,
      anon_sym_ELSIF,
      anon_sym_ELSE,
      sym_identifier,
  [3024] = 1,
    ACTIONS(396), 5,
      anon_sym_IF,
      anon_sym_END_IF,
      anon_sym_ELSIF,
      anon_sym_ELSE,
      sym_identifier,
  [3032] = 1,
    ACTIONS(398), 5,
      anon_sym_IF,
      anon_sym_END_IF,
      anon_sym_ELSIF,
      anon_sym_ELSE,
      sym_identifier,
  [3040] = 1,
    ACTIONS(400), 5,
      anon_sym_IF,
      anon_sym_END_IF,
      anon_sym_ELSIF,
      anon_sym_ELSE,
      sym_identifier,
  [3048] = 3,
    ACTIONS(402), 1,
      anon_sym_END_VAR,
    ACTIONS(404), 1,
      sym_identifier,
    STATE(129), 2,
      sym_var_declaration,
      aux_sym_var_block_repeat1,
  [3059] = 1,
    ACTIONS(406), 4,
      ts_builtin_sym_end,
      anon_sym_PROGRAM,
      anon_sym_CONFIGURATION,
      anon_sym_FUNCTION_BLOCK,
  [3066] = 3,
    ACTIONS(404), 1,
      sym_identifier,
    ACTIONS(408), 1,
      anon_sym_END_VAR,
    STATE(126), 2,
      sym_var_declaration,
      aux_sym_var_block_repeat1,
  [3077] = 1,
    ACTIONS(410), 4,
      ts_builtin_sym_end,
      anon_sym_PROGRAM,
      anon_sym_CONFIGURATION,
      anon_sym_FUNCTION_BLOCK,
  [3084] = 3,
    ACTIONS(404), 1,
      sym_identifier,
    ACTIONS(412), 1,
      anon_sym_END_VAR,
    STATE(131), 2,
      sym_var_declaration,
      aux_sym_var_block_repeat1,
  [3095] = 1,
    ACTIONS(414), 4,
      ts_builtin_sym_end,
      anon_sym_PROGRAM,
      anon_sym_CONFIGURATION,
      anon_sym_FUNCTION_BLOCK,
  [3102] = 3,
    ACTIONS(404), 1,
      sym_identifier,
    ACTIONS(416), 1,
      anon_sym_END_VAR,
    STATE(130), 2,
      sym_var_declaration,
      aux_sym_var_block_repeat1,
  [3113] = 3,
    ACTIONS(404), 1,
      sym_identifier,
    ACTIONS(418), 1,
      anon_sym_END_VAR,
    STATE(133), 2,
      sym_var_declaration,
      aux_sym_var_block_repeat1,
  [3124] = 3,
    ACTIONS(404), 1,
      sym_identifier,
    ACTIONS(420), 1,
      anon_sym_END_VAR,
    STATE(134), 2,
      sym_var_declaration,
      aux_sym_var_block_repeat1,
  [3135] = 3,
    ACTIONS(404), 1,
      sym_identifier,
    ACTIONS(422), 1,
      anon_sym_END_VAR,
    STATE(137), 2,
      sym_var_declaration,
      aux_sym_var_block_repeat1,
  [3146] = 1,
    ACTIONS(424), 4,
      ts_builtin_sym_end,
      anon_sym_PROGRAM,
      anon_sym_CONFIGURATION,
      anon_sym_FUNCTION_BLOCK,
  [3153] = 3,
    ACTIONS(404), 1,
      sym_identifier,
    ACTIONS(426), 1,
      anon_sym_END_VAR,
    STATE(135), 2,
      sym_var_declaration,
      aux_sym_var_block_repeat1,
  [3164] = 2,
    STATE(175), 1,
      sym_data_type,
    ACTIONS(428), 3,
      anon_sym_BOOL,
      anon_sym_REAL,
      anon_sym_INT,
  [3173] = 1,
    ACTIONS(430), 4,
      ts_builtin_sym_end,
      anon_sym_PROGRAM,
      anon_sym_CONFIGURATION,
      anon_sym_FUNCTION_BLOCK,
  [3180] = 3,
    ACTIONS(404), 1,
      sym_identifier,
    ACTIONS(432), 1,
      anon_sym_END_VAR,
    STATE(135), 2,
      sym_var_declaration,
      aux_sym_var_block_repeat1,
  [3191] = 3,
    ACTIONS(404), 1,
      sym_identifier,
    ACTIONS(434), 1,
      anon_sym_END_VAR,
    STATE(135), 2,
      sym_var_declaration,
      aux_sym_var_block_repeat1,
  [3202] = 3,
    ACTIONS(404), 1,
      sym_identifier,
    ACTIONS(436), 1,
      anon_sym_END_VAR,
    STATE(135), 2,
      sym_var_declaration,
      aux_sym_var_block_repeat1,
  [3213] = 1,
    ACTIONS(438), 4,
      ts_builtin_sym_end,
      anon_sym_PROGRAM,
      anon_sym_CONFIGURATION,
      anon_sym_FUNCTION_BLOCK,
  [3220] = 3,
    ACTIONS(404), 1,
      sym_identifier,
    ACTIONS(440), 1,
      anon_sym_END_VAR,
    STATE(135), 2,
      sym_var_declaration,
      aux_sym_var_block_repeat1,
  [3231] = 3,
    ACTIONS(404), 1,
      sym_identifier,
    ACTIONS(442), 1,
      anon_sym_END_VAR,
    STATE(135), 2,
      sym_var_declaration,
      aux_sym_var_block_repeat1,
  [3242] = 3,
    ACTIONS(444), 1,
      anon_sym_END_VAR,
    ACTIONS(446), 1,
      sym_identifier,
    STATE(135), 2,
      sym_var_declaration,
      aux_sym_var_block_repeat1,
  [3253] = 1,
    ACTIONS(449), 4,
      ts_builtin_sym_end,
      anon_sym_PROGRAM,
      anon_sym_CONFIGURATION,
      anon_sym_FUNCTION_BLOCK,
  [3260] = 3,
    ACTIONS(404), 1,
      sym_identifier,
    ACTIONS(451), 1,
      anon_sym_END_VAR,
    STATE(135), 2,
      sym_var_declaration,
      aux_sym_var_block_repeat1,
  [3271] = 2,
    STATE(176), 1,
      sym_data_type,
    ACTIONS(428), 3,
      anon_sym_BOOL,
      anon_sym_REAL,
      anon_sym_INT,
  [3280] = 1,
    ACTIONS(453), 4,
      ts_builtin_sym_end,
      anon_sym_PROGRAM,
      anon_sym_CONFIGURATION,
      anon_sym_FUNCTION_BLOCK,
  [3287] = 3,
    ACTIONS(165), 1,
      anon_sym_COMMA,
    ACTIONS(455), 1,
      anon_sym_RPAREN,
    STATE(154), 1,
      aux_sym_function_call_repeat1,
  [3297] = 1,
    ACTIONS(388), 3,
      anon_sym_END_FUNCTION_BLOCK,
      anon_sym_IF,
      sym_identifier,
  [3303] = 1,
    ACTIONS(392), 3,
      anon_sym_IF,
      anon_sym_END_IF,
      sym_identifier,
  [3309] = 1,
    ACTIONS(390), 3,
      anon_sym_IF,
      anon_sym_END_IF,
      sym_identifier,
  [3315] = 1,
    ACTIONS(381), 3,
      anon_sym_IF,
      anon_sym_END_IF,
      sym_identifier,
  [3321] = 3,
    ACTIONS(165), 1,
      anon_sym_COMMA,
    ACTIONS(457), 1,
      anon_sym_RPAREN,
    STATE(154), 1,
      aux_sym_function_call_repeat1,
  [3331] = 1,
    ACTIONS(459), 3,
      anon_sym_PROGRAM,
      anon_sym_END_RESOURCE,
      anon_sym_TASK,
  [3337] = 3,
    ACTIONS(165), 1,
      anon_sym_COMMA,
    ACTIONS(461), 1,
      anon_sym_RPAREN,
    STATE(154), 1,
      aux_sym_function_call_repeat1,
  [3347] = 1,
    ACTIONS(388), 3,
      anon_sym_IF,
      anon_sym_END_IF,
      sym_identifier,
  [3353] = 3,
    ACTIONS(278), 1,
      aux_sym_number_token1,
    ACTIONS(280), 1,
      aux_sym_number_token2,
    STATE(201), 1,
      sym_number,
  [3363] = 1,
    ACTIONS(398), 3,
      anon_sym_IF,
      anon_sym_END_IF,
      sym_identifier,
  [3369] = 1,
    ACTIONS(394), 3,
      anon_sym_END_PROGRAM,
      anon_sym_IF,
      sym_identifier,
  [3375] = 1,
    ACTIONS(463), 3,
      anon_sym_PROGRAM,
      anon_sym_END_RESOURCE,
      anon_sym_TASK,
  [3381] = 1,
    ACTIONS(400), 3,
      anon_sym_IF,
      anon_sym_END_IF,
      sym_identifier,
  [3387] = 3,
    ACTIONS(179), 1,
      anon_sym_RPAREN,
    ACTIONS(465), 1,
      anon_sym_COMMA,
    STATE(154), 1,
      aux_sym_function_call_repeat1,
  [3397] = 1,
    ACTIONS(381), 3,
      anon_sym_END_PROGRAM,
      anon_sym_IF,
      sym_identifier,
  [3403] = 1,
    ACTIONS(392), 3,
      anon_sym_END_PROGRAM,
      anon_sym_IF,
      sym_identifier,
  [3409] = 1,
    ACTIONS(396), 3,
      anon_sym_IF,
      anon_sym_END_IF,
      sym_identifier,
  [3415] = 1,
    ACTIONS(388), 3,
      anon_sym_END_PROGRAM,
      anon_sym_IF,
      sym_identifier,
  [3421] = 1,
    ACTIONS(394), 3,
      anon_sym_IF,
      anon_sym_END_IF,
      sym_identifier,
  [3427] = 1,
    ACTIONS(394), 3,
      anon_sym_END_FUNCTION_BLOCK,
      anon_sym_IF,
      sym_identifier,
  [3433] = 1,
    ACTIONS(396), 3,
      anon_sym_END_FUNCTION_BLOCK,
      anon_sym_IF,
      sym_identifier,
  [3439] = 1,
    ACTIONS(400), 3,
      anon_sym_END_FUNCTION_BLOCK,
      anon_sym_IF,
      sym_identifier,
  [3445] = 1,
    ACTIONS(398), 3,
      anon_sym_END_PROGRAM,
      anon_sym_IF,
      sym_identifier,
  [3451] = 1,
    ACTIONS(381), 3,
      anon_sym_END_FUNCTION_BLOCK,
      anon_sym_IF,
      sym_identifier,
  [3457] = 1,
    ACTIONS(390), 3,
      anon_sym_END_FUNCTION_BLOCK,
      anon_sym_IF,
      sym_identifier,
  [3463] = 1,
    ACTIONS(392), 3,
      anon_sym_END_FUNCTION_BLOCK,
      anon_sym_IF,
      sym_identifier,
  [3469] = 1,
    ACTIONS(398), 3,
      anon_sym_END_FUNCTION_BLOCK,
      anon_sym_IF,
      sym_identifier,
  [3475] = 1,
    ACTIONS(390), 3,
      anon_sym_END_PROGRAM,
      anon_sym_IF,
      sym_identifier,
  [3481] = 1,
    ACTIONS(400), 3,
      anon_sym_END_PROGRAM,
      anon_sym_IF,
      sym_identifier,
  [3487] = 3,
    ACTIONS(165), 1,
      anon_sym_COMMA,
    ACTIONS(468), 1,
      anon_sym_RPAREN,
    STATE(154), 1,
      aux_sym_function_call_repeat1,
  [3497] = 1,
    ACTIONS(396), 3,
      anon_sym_END_PROGRAM,
      anon_sym_IF,
      sym_identifier,
  [3503] = 2,
    ACTIONS(470), 1,
      anon_sym_LPAREN,
    ACTIONS(472), 1,
      anon_sym_COLON_EQ,
  [3510] = 2,
    ACTIONS(474), 1,
      anon_sym_LPAREN,
    ACTIONS(476), 1,
      anon_sym_COLON_EQ,
  [3517] = 1,
    ACTIONS(478), 2,
      anon_sym_END_VAR,
      sym_identifier,
  [3522] = 2,
    ACTIONS(480), 1,
      anon_sym_COLON_EQ,
    ACTIONS(482), 1,
      anon_sym_SEMI,
  [3529] = 2,
    ACTIONS(484), 1,
      anon_sym_COLON_EQ,
    ACTIONS(486), 1,
      anon_sym_SEMI,
  [3536] = 1,
    ACTIONS(488), 2,
      anon_sym_COLON_EQ,
      anon_sym_SEMI,
  [3541] = 1,
    ACTIONS(490), 2,
      anon_sym_END_VAR,
      sym_identifier,
  [3546] = 2,
    ACTIONS(492), 1,
      anon_sym_COLON,
    ACTIONS(494), 1,
      anon_sym_AT,
  [3553] = 2,
    ACTIONS(496), 1,
      anon_sym_LPAREN,
    ACTIONS(498), 1,
      anon_sym_COLON_EQ,
  [3560] = 1,
    ACTIONS(500), 2,
      anon_sym_RPAREN,
      anon_sym_SEMI,
  [3565] = 2,
    ACTIONS(502), 1,
      anon_sym_LPAREN,
    ACTIONS(504), 1,
      anon_sym_COLON_EQ,
  [3572] = 1,
    ACTIONS(506), 2,
      anon_sym_END_VAR,
      sym_identifier,
  [3577] = 2,
    ACTIONS(11), 1,
      anon_sym_LPAREN,
    STATE(30), 1,
      sym_parenthesis_expression,
  [3584] = 1,
    ACTIONS(508), 1,
      anon_sym_COLON_EQ,
  [3588] = 1,
    ACTIONS(510), 1,
      anon_sym_SEMI,
  [3592] = 1,
    ACTIONS(512), 1,
      anon_sym_COLON,
  [3596] = 1,
    ACTIONS(514), 1,
      aux_sym_date_and_time_token3,
  [3600] = 1,
    ACTIONS(516), 1,
      anon_sym_SEMI,
  [3604] = 1,
    ACTIONS(373), 1,
      anon_sym_END_IF,
  [3608] = 1,
    ACTIONS(518), 1,
      anon_sym_SEMI,
  [3612] = 1,
    ACTIONS(520), 1,
      sym_identifier,
  [3616] = 1,
    ACTIONS(377), 1,
      anon_sym_END_IF,
  [3620] = 1,
    ACTIONS(522), 1,
      sym_identifier,
  [3624] = 1,
    ACTIONS(524), 1,
      anon_sym_SEMI,
  [3628] = 1,
    ACTIONS(526), 1,
      anon_sym_SEMI,
  [3632] = 1,
    ACTIONS(528), 1,
      anon_sym_SEMI,
  [3636] = 1,
    ACTIONS(530), 1,
      anon_sym_SEMI,
  [3640] = 1,
    ACTIONS(532), 1,
      anon_sym_SEMI,
  [3644] = 1,
    ACTIONS(534), 1,
      aux_sym_date_and_time_token2,
  [3648] = 1,
    ACTIONS(536), 1,
      anon_sym_RPAREN,
  [3652] = 1,
    ACTIONS(538), 1,
      sym_address,
  [3656] = 1,
    ACTIONS(540), 1,
      anon_sym_SEMI,
  [3660] = 1,
    ACTIONS(542), 1,
      anon_sym_SEMI,
  [3664] = 1,
    ACTIONS(544), 1,
      anon_sym_SEMI,
  [3668] = 1,
    ACTIONS(546), 1,
      anon_sym_SEMI,
  [3672] = 1,
    ACTIONS(548), 1,
      anon_sym_SEMI,
  [3676] = 1,
    ACTIONS(550), 1,
      anon_sym_PRIORITY,
  [3680] = 1,
    ACTIONS(552), 1,
      anon_sym_COMMA,
  [3684] = 1,
    ACTIONS(554), 1,
      anon_sym_ON,
  [3688] = 1,
    ACTIONS(556), 1,
      anon_sym_SEMI,
  [3692] = 1,
    ACTIONS(558), 1,
      anon_sym_SEMI,
  [3696] = 1,
    ACTIONS(560), 1,
      anon_sym_SEMI,
  [3700] = 1,
    ACTIONS(562), 1,
      anon_sym_SEMI,
  [3704] = 1,
    ACTIONS(564), 1,
      anon_sym_SEMI,
  [3708] = 1,
    ACTIONS(566), 1,
      sym_time_literal,
  [3712] = 1,
    ACTIONS(568), 1,
      sym_identifier,
  [3716] = 1,
    ACTIONS(570), 1,
      anon_sym_COLON_EQ,
  [3720] = 1,
    ACTIONS(369), 1,
      anon_sym_END_IF,
  [3724] = 1,
    ACTIONS(572), 1,
      aux_sym_date_and_time_token1,
  [3728] = 1,
    ACTIONS(574), 1,
      anon_sym_LPAREN,
  [3732] = 1,
    ACTIONS(361), 1,
      anon_sym_END_IF,
  [3736] = 1,
    ACTIONS(576), 1,
      anon_sym_COLON,
  [3740] = 1,
    ACTIONS(578), 1,
      anon_sym_END_IF,
  [3744] = 1,
    ACTIONS(580), 1,
      anon_sym_SEMI,
  [3748] = 1,
    ACTIONS(582), 1,
      anon_sym_INTERVAL,
  [3752] = 1,
    ACTIONS(584), 1,
      sym_identifier,
  [3756] = 1,
    ACTIONS(379), 1,
      anon_sym_END_IF,
  [3760] = 1,
    ACTIONS(586), 1,
      anon_sym_SEMI,
  [3764] = 1,
    ACTIONS(588), 1,
      anon_sym_END_CONFIGURATION,
  [3768] = 1,
    ACTIONS(367), 1,
      anon_sym_END_IF,
  [3772] = 1,
    ACTIONS(590), 1,
      sym_identifier,
  [3776] = 1,
    ACTIONS(592), 1,
      anon_sym_END_IF,
  [3780] = 1,
    ACTIONS(594), 1,
      sym_identifier,
  [3784] = 1,
    ACTIONS(596), 1,
      sym_identifier,
  [3788] = 1,
    ACTIONS(598), 1,
      anon_sym_END_CONFIGURATION,
  [3792] = 1,
    ACTIONS(371), 1,
      anon_sym_END_IF,
  [3796] = 1,
    ACTIONS(600), 1,
      anon_sym_LPAREN,
  [3800] = 1,
    ACTIONS(602), 1,
      anon_sym_WITH,
  [3804] = 1,
    ACTIONS(375), 1,
      anon_sym_END_IF,
  [3808] = 1,
    ACTIONS(604), 1,
      anon_sym_END_IF,
  [3812] = 1,
    ACTIONS(606), 1,
      anon_sym_END_IF,
  [3816] = 1,
    ACTIONS(608), 1,
      anon_sym_SEMI,
  [3820] = 1,
    ACTIONS(482), 1,
      anon_sym_SEMI,
  [3824] = 1,
    ACTIONS(610), 1,
      anon_sym_RESOURCE,
  [3828] = 1,
    ACTIONS(612), 1,
      ts_builtin_sym_end,
  [3832] = 1,
    ACTIONS(614), 1,
      sym_identifier,
  [3836] = 1,
    ACTIONS(616), 1,
      sym_identifier,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 50,
  [SMALL_STATE(4)] = 100,
  [SMALL_STATE(5)] = 150,
  [SMALL_STATE(6)] = 200,
  [SMALL_STATE(7)] = 247,
  [SMALL_STATE(8)] = 294,
  [SMALL_STATE(9)] = 341,
  [SMALL_STATE(10)] = 388,
  [SMALL_STATE(11)] = 435,
  [SMALL_STATE(12)] = 482,
  [SMALL_STATE(13)] = 529,
  [SMALL_STATE(14)] = 576,
  [SMALL_STATE(15)] = 623,
  [SMALL_STATE(16)] = 670,
  [SMALL_STATE(17)] = 717,
  [SMALL_STATE(18)] = 764,
  [SMALL_STATE(19)] = 811,
  [SMALL_STATE(20)] = 858,
  [SMALL_STATE(21)] = 905,
  [SMALL_STATE(22)] = 952,
  [SMALL_STATE(23)] = 999,
  [SMALL_STATE(24)] = 1046,
  [SMALL_STATE(25)] = 1093,
  [SMALL_STATE(26)] = 1117,
  [SMALL_STATE(27)] = 1141,
  [SMALL_STATE(28)] = 1167,
  [SMALL_STATE(29)] = 1191,
  [SMALL_STATE(30)] = 1223,
  [SMALL_STATE(31)] = 1247,
  [SMALL_STATE(32)] = 1281,
  [SMALL_STATE(33)] = 1311,
  [SMALL_STATE(34)] = 1335,
  [SMALL_STATE(35)] = 1371,
  [SMALL_STATE(36)] = 1410,
  [SMALL_STATE(37)] = 1451,
  [SMALL_STATE(38)] = 1492,
  [SMALL_STATE(39)] = 1533,
  [SMALL_STATE(40)] = 1574,
  [SMALL_STATE(41)] = 1613,
  [SMALL_STATE(42)] = 1649,
  [SMALL_STATE(43)] = 1684,
  [SMALL_STATE(44)] = 1719,
  [SMALL_STATE(45)] = 1754,
  [SMALL_STATE(46)] = 1789,
  [SMALL_STATE(47)] = 1824,
  [SMALL_STATE(48)] = 1859,
  [SMALL_STATE(49)] = 1894,
  [SMALL_STATE(50)] = 1929,
  [SMALL_STATE(51)] = 1964,
  [SMALL_STATE(52)] = 1999,
  [SMALL_STATE(53)] = 2031,
  [SMALL_STATE(54)] = 2063,
  [SMALL_STATE(55)] = 2093,
  [SMALL_STATE(56)] = 2123,
  [SMALL_STATE(57)] = 2153,
  [SMALL_STATE(58)] = 2183,
  [SMALL_STATE(59)] = 2213,
  [SMALL_STATE(60)] = 2243,
  [SMALL_STATE(61)] = 2271,
  [SMALL_STATE(62)] = 2301,
  [SMALL_STATE(63)] = 2331,
  [SMALL_STATE(64)] = 2350,
  [SMALL_STATE(65)] = 2369,
  [SMALL_STATE(66)] = 2388,
  [SMALL_STATE(67)] = 2409,
  [SMALL_STATE(68)] = 2431,
  [SMALL_STATE(69)] = 2453,
  [SMALL_STATE(70)] = 2470,
  [SMALL_STATE(71)] = 2487,
  [SMALL_STATE(72)] = 2504,
  [SMALL_STATE(73)] = 2521,
  [SMALL_STATE(74)] = 2538,
  [SMALL_STATE(75)] = 2557,
  [SMALL_STATE(76)] = 2574,
  [SMALL_STATE(77)] = 2591,
  [SMALL_STATE(78)] = 2608,
  [SMALL_STATE(79)] = 2625,
  [SMALL_STATE(80)] = 2644,
  [SMALL_STATE(81)] = 2654,
  [SMALL_STATE(82)] = 2670,
  [SMALL_STATE(83)] = 2686,
  [SMALL_STATE(84)] = 2702,
  [SMALL_STATE(85)] = 2712,
  [SMALL_STATE(86)] = 2722,
  [SMALL_STATE(87)] = 2732,
  [SMALL_STATE(88)] = 2742,
  [SMALL_STATE(89)] = 2752,
  [SMALL_STATE(90)] = 2762,
  [SMALL_STATE(91)] = 2772,
  [SMALL_STATE(92)] = 2782,
  [SMALL_STATE(93)] = 2799,
  [SMALL_STATE(94)] = 2816,
  [SMALL_STATE(95)] = 2833,
  [SMALL_STATE(96)] = 2850,
  [SMALL_STATE(97)] = 2867,
  [SMALL_STATE(98)] = 2876,
  [SMALL_STATE(99)] = 2885,
  [SMALL_STATE(100)] = 2894,
  [SMALL_STATE(101)] = 2903,
  [SMALL_STATE(102)] = 2912,
  [SMALL_STATE(103)] = 2929,
  [SMALL_STATE(104)] = 2946,
  [SMALL_STATE(105)] = 2963,
  [SMALL_STATE(106)] = 2972,
  [SMALL_STATE(107)] = 2980,
  [SMALL_STATE(108)] = 2992,
  [SMALL_STATE(109)] = 3000,
  [SMALL_STATE(110)] = 3008,
  [SMALL_STATE(111)] = 3016,
  [SMALL_STATE(112)] = 3024,
  [SMALL_STATE(113)] = 3032,
  [SMALL_STATE(114)] = 3040,
  [SMALL_STATE(115)] = 3048,
  [SMALL_STATE(116)] = 3059,
  [SMALL_STATE(117)] = 3066,
  [SMALL_STATE(118)] = 3077,
  [SMALL_STATE(119)] = 3084,
  [SMALL_STATE(120)] = 3095,
  [SMALL_STATE(121)] = 3102,
  [SMALL_STATE(122)] = 3113,
  [SMALL_STATE(123)] = 3124,
  [SMALL_STATE(124)] = 3135,
  [SMALL_STATE(125)] = 3146,
  [SMALL_STATE(126)] = 3153,
  [SMALL_STATE(127)] = 3164,
  [SMALL_STATE(128)] = 3173,
  [SMALL_STATE(129)] = 3180,
  [SMALL_STATE(130)] = 3191,
  [SMALL_STATE(131)] = 3202,
  [SMALL_STATE(132)] = 3213,
  [SMALL_STATE(133)] = 3220,
  [SMALL_STATE(134)] = 3231,
  [SMALL_STATE(135)] = 3242,
  [SMALL_STATE(136)] = 3253,
  [SMALL_STATE(137)] = 3260,
  [SMALL_STATE(138)] = 3271,
  [SMALL_STATE(139)] = 3280,
  [SMALL_STATE(140)] = 3287,
  [SMALL_STATE(141)] = 3297,
  [SMALL_STATE(142)] = 3303,
  [SMALL_STATE(143)] = 3309,
  [SMALL_STATE(144)] = 3315,
  [SMALL_STATE(145)] = 3321,
  [SMALL_STATE(146)] = 3331,
  [SMALL_STATE(147)] = 3337,
  [SMALL_STATE(148)] = 3347,
  [SMALL_STATE(149)] = 3353,
  [SMALL_STATE(150)] = 3363,
  [SMALL_STATE(151)] = 3369,
  [SMALL_STATE(152)] = 3375,
  [SMALL_STATE(153)] = 3381,
  [SMALL_STATE(154)] = 3387,
  [SMALL_STATE(155)] = 3397,
  [SMALL_STATE(156)] = 3403,
  [SMALL_STATE(157)] = 3409,
  [SMALL_STATE(158)] = 3415,
  [SMALL_STATE(159)] = 3421,
  [SMALL_STATE(160)] = 3427,
  [SMALL_STATE(161)] = 3433,
  [SMALL_STATE(162)] = 3439,
  [SMALL_STATE(163)] = 3445,
  [SMALL_STATE(164)] = 3451,
  [SMALL_STATE(165)] = 3457,
  [SMALL_STATE(166)] = 3463,
  [SMALL_STATE(167)] = 3469,
  [SMALL_STATE(168)] = 3475,
  [SMALL_STATE(169)] = 3481,
  [SMALL_STATE(170)] = 3487,
  [SMALL_STATE(171)] = 3497,
  [SMALL_STATE(172)] = 3503,
  [SMALL_STATE(173)] = 3510,
  [SMALL_STATE(174)] = 3517,
  [SMALL_STATE(175)] = 3522,
  [SMALL_STATE(176)] = 3529,
  [SMALL_STATE(177)] = 3536,
  [SMALL_STATE(178)] = 3541,
  [SMALL_STATE(179)] = 3546,
  [SMALL_STATE(180)] = 3553,
  [SMALL_STATE(181)] = 3560,
  [SMALL_STATE(182)] = 3565,
  [SMALL_STATE(183)] = 3572,
  [SMALL_STATE(184)] = 3577,
  [SMALL_STATE(185)] = 3584,
  [SMALL_STATE(186)] = 3588,
  [SMALL_STATE(187)] = 3592,
  [SMALL_STATE(188)] = 3596,
  [SMALL_STATE(189)] = 3600,
  [SMALL_STATE(190)] = 3604,
  [SMALL_STATE(191)] = 3608,
  [SMALL_STATE(192)] = 3612,
  [SMALL_STATE(193)] = 3616,
  [SMALL_STATE(194)] = 3620,
  [SMALL_STATE(195)] = 3624,
  [SMALL_STATE(196)] = 3628,
  [SMALL_STATE(197)] = 3632,
  [SMALL_STATE(198)] = 3636,
  [SMALL_STATE(199)] = 3640,
  [SMALL_STATE(200)] = 3644,
  [SMALL_STATE(201)] = 3648,
  [SMALL_STATE(202)] = 3652,
  [SMALL_STATE(203)] = 3656,
  [SMALL_STATE(204)] = 3660,
  [SMALL_STATE(205)] = 3664,
  [SMALL_STATE(206)] = 3668,
  [SMALL_STATE(207)] = 3672,
  [SMALL_STATE(208)] = 3676,
  [SMALL_STATE(209)] = 3680,
  [SMALL_STATE(210)] = 3684,
  [SMALL_STATE(211)] = 3688,
  [SMALL_STATE(212)] = 3692,
  [SMALL_STATE(213)] = 3696,
  [SMALL_STATE(214)] = 3700,
  [SMALL_STATE(215)] = 3704,
  [SMALL_STATE(216)] = 3708,
  [SMALL_STATE(217)] = 3712,
  [SMALL_STATE(218)] = 3716,
  [SMALL_STATE(219)] = 3720,
  [SMALL_STATE(220)] = 3724,
  [SMALL_STATE(221)] = 3728,
  [SMALL_STATE(222)] = 3732,
  [SMALL_STATE(223)] = 3736,
  [SMALL_STATE(224)] = 3740,
  [SMALL_STATE(225)] = 3744,
  [SMALL_STATE(226)] = 3748,
  [SMALL_STATE(227)] = 3752,
  [SMALL_STATE(228)] = 3756,
  [SMALL_STATE(229)] = 3760,
  [SMALL_STATE(230)] = 3764,
  [SMALL_STATE(231)] = 3768,
  [SMALL_STATE(232)] = 3772,
  [SMALL_STATE(233)] = 3776,
  [SMALL_STATE(234)] = 3780,
  [SMALL_STATE(235)] = 3784,
  [SMALL_STATE(236)] = 3788,
  [SMALL_STATE(237)] = 3792,
  [SMALL_STATE(238)] = 3796,
  [SMALL_STATE(239)] = 3800,
  [SMALL_STATE(240)] = 3804,
  [SMALL_STATE(241)] = 3808,
  [SMALL_STATE(242)] = 3812,
  [SMALL_STATE(243)] = 3816,
  [SMALL_STATE(244)] = 3820,
  [SMALL_STATE(245)] = 3824,
  [SMALL_STATE(246)] = 3828,
  [SMALL_STATE(247)] = 3832,
  [SMALL_STATE(248)] = 3836,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(234),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(248),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(247),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(221),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(36),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(220),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(160),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(37),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(151),
  [35] = {.entry = {.count = 1, .reusable = false}}, SHIFT(38),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(159),
  [41] = {.entry = {.count = 1, .reusable = false}}, SHIFT(39),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [45] = {.entry = {.count = 1, .reusable = false}}, SHIFT(48),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [49] = {.entry = {.count = 1, .reusable = false}}, SHIFT(51),
  [51] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [53] = {.entry = {.count = 1, .reusable = false}}, SHIFT(42),
  [55] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [57] = {.entry = {.count = 1, .reusable = false}}, SHIFT(45),
  [59] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [61] = {.entry = {.count = 1, .reusable = false}}, SHIFT(46),
  [63] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [65] = {.entry = {.count = 1, .reusable = false}}, SHIFT(25),
  [67] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [69] = {.entry = {.count = 1, .reusable = false}}, SHIFT(41),
  [71] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [73] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [75] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [77] = {.entry = {.count = 1, .reusable = false}}, SHIFT(29),
  [79] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [81] = {.entry = {.count = 1, .reusable = false}}, SHIFT(26),
  [83] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [85] = {.entry = {.count = 1, .reusable = false}}, SHIFT(50),
  [87] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [89] = {.entry = {.count = 1, .reusable = false}}, SHIFT(27),
  [91] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [93] = {.entry = {.count = 1, .reusable = false}}, SHIFT(49),
  [95] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [97] = {.entry = {.count = 1, .reusable = false}}, SHIFT(44),
  [99] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [101] = {.entry = {.count = 1, .reusable = false}}, SHIFT(47),
  [103] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [105] = {.entry = {.count = 1, .reusable = false}}, SHIFT(34),
  [107] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [109] = {.entry = {.count = 1, .reusable = false}}, SHIFT(32),
  [111] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [113] = {.entry = {.count = 1, .reusable = false}}, SHIFT(43),
  [115] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [117] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unary_expression, 2),
  [119] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unary_expression, 2),
  [121] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_binary_expression, 3),
  [123] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_binary_expression, 3),
  [125] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [127] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_date_and_time, 4),
  [129] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_date_and_time, 4),
  [131] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [133] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [135] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [137] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_logical_expression, 2),
  [139] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_logical_expression, 2),
  [141] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [143] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [145] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parenthesis_expression, 3),
  [147] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_parenthesis_expression, 3),
  [149] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [151] = {.entry = {.count = 1, .reusable = false}}, SHIFT(116),
  [153] = {.entry = {.count = 1, .reusable = false}}, SHIFT(119),
  [155] = {.entry = {.count = 1, .reusable = false}}, SHIFT(122),
  [157] = {.entry = {.count = 1, .reusable = false}}, SHIFT(123),
  [159] = {.entry = {.count = 1, .reusable = false}}, SHIFT(124),
  [161] = {.entry = {.count = 1, .reusable = false}}, SHIFT(21),
  [163] = {.entry = {.count = 1, .reusable = false}}, SHIFT(173),
  [165] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [167] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [169] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [171] = {.entry = {.count = 1, .reusable = true}}, SHIFT(161),
  [173] = {.entry = {.count = 1, .reusable = true}}, SHIFT(171),
  [175] = {.entry = {.count = 1, .reusable = true}}, SHIFT(157),
  [177] = {.entry = {.count = 1, .reusable = false}}, SHIFT(118),
  [179] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_function_call_repeat1, 2),
  [181] = {.entry = {.count = 1, .reusable = true}}, SHIFT(162),
  [183] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [185] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [187] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [189] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [191] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [193] = {.entry = {.count = 1, .reusable = true}}, SHIFT(169),
  [195] = {.entry = {.count = 1, .reusable = true}}, SHIFT(114),
  [197] = {.entry = {.count = 1, .reusable = true}}, SHIFT(153),
  [199] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [201] = {.entry = {.count = 1, .reusable = false}}, SHIFT(128),
  [203] = {.entry = {.count = 1, .reusable = false}}, SHIFT(117),
  [205] = {.entry = {.count = 1, .reusable = false}}, SHIFT(115),
  [207] = {.entry = {.count = 1, .reusable = false}}, SHIFT(121),
  [209] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [211] = {.entry = {.count = 1, .reusable = false}}, SHIFT(182),
  [213] = {.entry = {.count = 1, .reusable = false}}, SHIFT(139),
  [215] = {.entry = {.count = 1, .reusable = false}}, SHIFT(20),
  [217] = {.entry = {.count = 1, .reusable = false}}, SHIFT(189),
  [219] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [221] = {.entry = {.count = 1, .reusable = false}}, SHIFT(78),
  [223] = {.entry = {.count = 1, .reusable = false}}, SHIFT(180),
  [225] = {.entry = {.count = 1, .reusable = false}}, SHIFT(211),
  [227] = {.entry = {.count = 1, .reusable = false}}, SHIFT(191),
  [229] = {.entry = {.count = 1, .reusable = false}}, SHIFT(213),
  [231] = {.entry = {.count = 1, .reusable = false}}, SHIFT(203),
  [233] = {.entry = {.count = 1, .reusable = false}}, SHIFT(205),
  [235] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2),
  [237] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(119),
  [240] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(122),
  [243] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(123),
  [246] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(124),
  [249] = {.entry = {.count = 1, .reusable = false}}, SHIFT(197),
  [251] = {.entry = {.count = 1, .reusable = false}}, SHIFT(195),
  [253] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat2, 2), SHIFT_REPEAT(20),
  [256] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_program_repeat2, 2),
  [258] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat2, 2), SHIFT_REPEAT(180),
  [261] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_elsif_clause, 3),
  [263] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_elsif_clause, 4),
  [265] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_function_block_repeat1, 2),
  [267] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_function_block_repeat1, 2), SHIFT_REPEAT(117),
  [270] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_function_block_repeat1, 2), SHIFT_REPEAT(115),
  [273] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_function_block_repeat1, 2), SHIFT_REPEAT(121),
  [276] = {.entry = {.count = 1, .reusable = true}}, SHIFT(204),
  [278] = {.entry = {.count = 1, .reusable = true}}, SHIFT(181),
  [280] = {.entry = {.count = 1, .reusable = false}}, SHIFT(181),
  [282] = {.entry = {.count = 1, .reusable = true}}, SHIFT(186),
  [284] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [286] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_else_clause, 2),
  [288] = {.entry = {.count = 1, .reusable = false}}, SHIFT(172),
  [290] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat2, 2), SHIFT_REPEAT(9),
  [293] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat2, 2), SHIFT_REPEAT(182),
  [296] = {.entry = {.count = 1, .reusable = false}}, SHIFT(120),
  [298] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [300] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(234),
  [303] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(248),
  [306] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(247),
  [309] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat2, 2), SHIFT_REPEAT(10),
  [312] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat2, 2), SHIFT_REPEAT(172),
  [315] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat2, 2), SHIFT_REPEAT(21),
  [318] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat2, 2), SHIFT_REPEAT(173),
  [321] = {.entry = {.count = 1, .reusable = false}}, SHIFT(132),
  [323] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_else_clause, 1),
  [325] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [327] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_var_output_block, 3),
  [329] = {.entry = {.count = 1, .reusable = true}}, SHIFT(194),
  [331] = {.entry = {.count = 1, .reusable = true}}, SHIFT(230),
  [333] = {.entry = {.count = 1, .reusable = true}}, SHIFT(232),
  [335] = {.entry = {.count = 1, .reusable = true}}, SHIFT(236),
  [337] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_configuration_repeat1, 2), SHIFT_REPEAT(194),
  [340] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_configuration_repeat1, 2),
  [342] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_configuration_repeat1, 2), SHIFT_REPEAT(232),
  [345] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_variable_block, 1),
  [347] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_var_block, 2),
  [349] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_var_input_block, 2),
  [351] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_var_output_block, 2),
  [353] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_var_constant_block, 2),
  [355] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_var_constant_block, 3),
  [357] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_var_input_block, 3),
  [359] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_var_block, 3),
  [361] = {.entry = {.count = 1, .reusable = true}}, SHIFT(198),
  [363] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [365] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [367] = {.entry = {.count = 1, .reusable = true}}, SHIFT(206),
  [369] = {.entry = {.count = 1, .reusable = true}}, SHIFT(197),
  [371] = {.entry = {.count = 1, .reusable = true}}, SHIFT(213),
  [373] = {.entry = {.count = 1, .reusable = true}}, SHIFT(191),
  [375] = {.entry = {.count = 1, .reusable = true}}, SHIFT(214),
  [377] = {.entry = {.count = 1, .reusable = true}}, SHIFT(243),
  [379] = {.entry = {.count = 1, .reusable = true}}, SHIFT(205),
  [381] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_function_call, 5),
  [383] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_if_statement_repeat1, 2),
  [385] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_if_statement_repeat1, 2), SHIFT_REPEAT(7),
  [388] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_if_statement, 5),
  [390] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_if_statement, 6),
  [392] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_if_statement, 7),
  [394] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_function_call, 3),
  [396] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_function_call, 4),
  [398] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_if_statement, 8),
  [400] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_assignment, 4),
  [402] = {.entry = {.count = 1, .reusable = false}}, SHIFT(100),
  [404] = {.entry = {.count = 1, .reusable = false}}, SHIFT(179),
  [406] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_program, 4),
  [408] = {.entry = {.count = 1, .reusable = false}}, SHIFT(97),
  [410] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_program, 3),
  [412] = {.entry = {.count = 1, .reusable = false}}, SHIFT(85),
  [414] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_block, 5),
  [416] = {.entry = {.count = 1, .reusable = false}}, SHIFT(105),
  [418] = {.entry = {.count = 1, .reusable = false}}, SHIFT(86),
  [420] = {.entry = {.count = 1, .reusable = false}}, SHIFT(87),
  [422] = {.entry = {.count = 1, .reusable = false}}, SHIFT(88),
  [424] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_configuration, 8),
  [426] = {.entry = {.count = 1, .reusable = false}}, SHIFT(101),
  [428] = {.entry = {.count = 1, .reusable = true}}, SHIFT(177),
  [430] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_block, 3),
  [432] = {.entry = {.count = 1, .reusable = false}}, SHIFT(99),
  [434] = {.entry = {.count = 1, .reusable = false}}, SHIFT(98),
  [436] = {.entry = {.count = 1, .reusable = false}}, SHIFT(91),
  [438] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_program, 5),
  [440] = {.entry = {.count = 1, .reusable = false}}, SHIFT(90),
  [442] = {.entry = {.count = 1, .reusable = false}}, SHIFT(80),
  [444] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_var_block_repeat1, 2),
  [446] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_var_block_repeat1, 2), SHIFT_REPEAT(179),
  [449] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_configuration, 9),
  [451] = {.entry = {.count = 1, .reusable = false}}, SHIFT(89),
  [453] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_block, 4),
  [455] = {.entry = {.count = 1, .reusable = true}}, SHIFT(164),
  [457] = {.entry = {.count = 1, .reusable = true}}, SHIFT(144),
  [459] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_program_instance, 7),
  [461] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [463] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_task, 12),
  [465] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_function_call_repeat1, 2), SHIFT_REPEAT(13),
  [468] = {.entry = {.count = 1, .reusable = true}}, SHIFT(155),
  [470] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [472] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [474] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [476] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [478] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_var_declaration, 4),
  [480] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [482] = {.entry = {.count = 1, .reusable = true}}, SHIFT(178),
  [484] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [486] = {.entry = {.count = 1, .reusable = true}}, SHIFT(174),
  [488] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_data_type, 1),
  [490] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_var_declaration, 6),
  [492] = {.entry = {.count = 1, .reusable = true}}, SHIFT(138),
  [494] = {.entry = {.count = 1, .reusable = true}}, SHIFT(202),
  [496] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [498] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [500] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number, 1),
  [502] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [504] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [506] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_var_declaration, 8),
  [508] = {.entry = {.count = 1, .reusable = true}}, SHIFT(149),
  [510] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bool_literal, 1),
  [512] = {.entry = {.count = 1, .reusable = true}}, SHIFT(127),
  [514] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [516] = {.entry = {.count = 1, .reusable = true}}, SHIFT(158),
  [518] = {.entry = {.count = 1, .reusable = true}}, SHIFT(168),
  [520] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [522] = {.entry = {.count = 1, .reusable = true}}, SHIFT(239),
  [524] = {.entry = {.count = 1, .reusable = true}}, SHIFT(141),
  [526] = {.entry = {.count = 1, .reusable = true}}, SHIFT(152),
  [528] = {.entry = {.count = 1, .reusable = true}}, SHIFT(165),
  [530] = {.entry = {.count = 1, .reusable = true}}, SHIFT(166),
  [532] = {.entry = {.count = 1, .reusable = true}}, SHIFT(167),
  [534] = {.entry = {.count = 1, .reusable = true}}, SHIFT(188),
  [536] = {.entry = {.count = 1, .reusable = true}}, SHIFT(196),
  [538] = {.entry = {.count = 1, .reusable = true}}, SHIFT(187),
  [540] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [542] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_expression, 1),
  [544] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [546] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [548] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [550] = {.entry = {.count = 1, .reusable = true}}, SHIFT(185),
  [552] = {.entry = {.count = 1, .reusable = true}}, SHIFT(208),
  [554] = {.entry = {.count = 1, .reusable = true}}, SHIFT(192),
  [556] = {.entry = {.count = 1, .reusable = true}}, SHIFT(148),
  [558] = {.entry = {.count = 1, .reusable = true}}, SHIFT(146),
  [560] = {.entry = {.count = 1, .reusable = true}}, SHIFT(143),
  [562] = {.entry = {.count = 1, .reusable = true}}, SHIFT(142),
  [564] = {.entry = {.count = 1, .reusable = true}}, SHIFT(150),
  [566] = {.entry = {.count = 1, .reusable = true}}, SHIFT(209),
  [568] = {.entry = {.count = 1, .reusable = true}}, SHIFT(212),
  [570] = {.entry = {.count = 1, .reusable = true}}, SHIFT(216),
  [572] = {.entry = {.count = 1, .reusable = true}}, SHIFT(200),
  [574] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_logical_operator, 1),
  [576] = {.entry = {.count = 1, .reusable = true}}, SHIFT(217),
  [578] = {.entry = {.count = 1, .reusable = true}}, SHIFT(199),
  [580] = {.entry = {.count = 1, .reusable = true}}, SHIFT(183),
  [582] = {.entry = {.count = 1, .reusable = true}}, SHIFT(218),
  [584] = {.entry = {.count = 1, .reusable = true}}, SHIFT(223),
  [586] = {.entry = {.count = 1, .reusable = true}}, SHIFT(163),
  [588] = {.entry = {.count = 1, .reusable = true}}, SHIFT(125),
  [590] = {.entry = {.count = 1, .reusable = true}}, SHIFT(238),
  [592] = {.entry = {.count = 1, .reusable = true}}, SHIFT(207),
  [594] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [596] = {.entry = {.count = 1, .reusable = true}}, SHIFT(210),
  [598] = {.entry = {.count = 1, .reusable = true}}, SHIFT(136),
  [600] = {.entry = {.count = 1, .reusable = true}}, SHIFT(226),
  [602] = {.entry = {.count = 1, .reusable = true}}, SHIFT(227),
  [604] = {.entry = {.count = 1, .reusable = true}}, SHIFT(229),
  [606] = {.entry = {.count = 1, .reusable = true}}, SHIFT(215),
  [608] = {.entry = {.count = 1, .reusable = true}}, SHIFT(156),
  [610] = {.entry = {.count = 1, .reusable = true}}, SHIFT(235),
  [612] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [614] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [616] = {.entry = {.count = 1, .reusable = true}}, SHIFT(245),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_StructuredText(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
