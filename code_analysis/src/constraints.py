
import tree_sitter
from visitor import ASTVisitor
import z3



def convert_to_z3_value(ast_value):
    """
    Converts the value from the AST to the value used by Z3
    """
    z3_value = None
    if ast_value == "TRUE":
        z3_value = z3.BoolVal(True)
    elif ast_value == "FALSE":
        z3_value = z3.BoolVal(False)
    else:
        raise Exception("Unknown value: %s" % ast_value)

    return z3_value


def convert_to_z3_operator(ast_operator):
    """
    Converts the operator from the AST to the operator used by Z3
    """
    if ast_operator == "AND":
        z3_operator = z3.And
    elif ast_operator == "OR":
        z3_operator = z3.Or
    elif ast_operator == "NOT":
        z3_operator = z3.Not
    elif ast_operator == "XOR":
        z3_operator = z3.Xor
    else:
        raise Exception("Unknown operator: %s" % ast_operator)

    return z3_operator


def convert_to_z3_variable(ast_variable_name, ast_variable_type):
    """
    Converts the variable from the AST to the variable used by Z3
    """
    z3_variable = None
    # convert type in bytes to string
    if ast_variable_type == "BOOL":
        z3_variable = "Bool('%s')" % ast_variable_name
        z3_variable = z3.Bool(ast_variable_name)
    else:
        raise Exception("Unknown type: %s" % ast_variable_type)

    return z3_variable

def convert_to_z3_function(ast_function_name, ast_input_variables):
    function_operator = convert_to_z3_operator(ast_function_name)
    z3_expression = function_operator(*[convert_to_z3_variable(input_variable[0], input_variable[1]) for input_variable in ast_input_variables])
    return z3_expression

def convert_ast_expression_to_z3_expression(ast_expression_node, variables):
    """
    Converts the expression from the AST to the expression used by Z3
    """
    z3_expression = None
    if ast_expression_node.type == "binary_expression":
        left_operand = convert_ast_expression_to_z3_expression(ast_expression_node.children[0], variables)
        right_operand = convert_ast_expression_to_z3_expression(ast_expression_node.children[2], variables)
        operator = convert_to_z3_operator(ast_expression_node.children[1].text.decode("utf-8"))
        z3_expression = operator(left_operand, right_operand)
    elif ast_expression_node.type == "unary_expression":
        operand = convert_ast_expression_to_z3_expression(ast_expression_node.children[1], variables)
        operator = convert_to_z3_operator(ast_expression_node.children[0].text.decode("utf-8"))
        z3_expression = operator(operand)
    elif ast_expression_node.type == "parenthesis_expression":
        z3_expression = convert_ast_expression_to_z3_expression(ast_expression_node.children[1], variables)
    elif ast_expression_node.type == "variable":
        variable_name = ast_expression_node.child_by_field_name("name").text.decode("utf-8")
        variable = variables.get(variable_name)
        variable_type = variable[0]
        z3_expression = convert_to_z3_variable(variable_name, variable_type)

    elif ast_expression_node.type == "call_expression":
        print("call_expression values: ", ast_expression_node.text.decode("utf-8"))
        function_name = ast_expression_node.child_by_field_name("function_name").text.decode("utf-8")
        print("function_name: ", function_name)
         # the call_expression sexp has the form `(call_expression function_name: (identifier) input: (variable name: (identifier)) input: (variable name: (identifier)))`, get all the input variables
        input_variables = []
        for input_variable in ast_expression_node.children[1:]:
            input_variable_node = input_variable.child_by_field_name("name")
            if input_variable_node:
                input_variable_name = input_variable_node.text.decode("utf-8")
                variable = variables.get(input_variable_name)
                variable_type = variable[0]
                input_variables.append((input_variable_name, variable_type))
        print("input_variables: ", input_variables)
        
        # construct the z3 expression, e.g., And(Not(a), b)
        z3_expression = convert_to_z3_function(function_name, input_variables)
        print("z3_expression: ", z3_expression)

    elif ast_expression_node.type == "boolean":
        print("boolean ast_expression_node: ", ast_expression_node.text.decode("utf-8"))
        # set the variable to the boolean value
        variable_value = ast_expression_node.text.decode("utf-8")
        z3_expression = convert_to_z3_value(variable_value)
        

    elif ast_expression_node.type == "integer":
        # set the variable to the integer value
        variable_value = ast_expression_node.text.decode("utf-8")
        z3_expression = z3.Int(variable_value)
    else:
        raise Exception("Unknown expression type: %s" % ast_expression_node.type)

    return z3_expression


class ConstraintVisitor(ASTVisitor):
    """
    This visitor is used to extract the constraints from the AST (s-expr).
    """
    def __init__(self):
        super().__init__()
        self.constraints = []
        self.variables = {}

    def visit_if_statement(self, node):
        # the z3 expression is the condition of the if statement
        pass


    def visit_variable_definition_body(self, node):
        """
        Extracts the variable name and the variable type
        """
        variable_name = node.child_by_field_name("name").text.decode("utf-8")
        variable_type = node.child_by_field_name("type").text.decode("utf-8")
        variable_address_node = node.child_by_field_name("address")
        variable_address = None 
        if variable_address_node:
            variable_address = variable_address_node.text.decode("utf-8")
        self.variables[variable_name] = (variable_type, variable_address)
        print("variable_name: ", variable_name)
        print("variable_type: ", variable_type)
        print("variable_address: ", variable_address)
        print()

    def visit_assignment(self, node):
        """
        Extracts the variable name and the variable value
        """
        print("visit_assignment: ", node.sexp())
        print()
        variable_name = node.children[0].child_by_field_name("name").text.decode("utf-8")
        expression = node.children[2]
        print("variable name: ", variable_name)
        # print("expression: ", expression.text, expression.sexp())
        z3_expression = convert_ast_expression_to_z3_expression(expression, self.variables)
        self.constraints.append((variable_name, z3_expression))
        # print("z3_expression: ", z3_expression)

    def solve(self):
        """
        Solves the constraints
        """
        model = None
        if len(self.constraints) == 0:
            raise Exception("No constraints to solve")
        else:
            for constraint in self.constraints:
                solver = z3.Solver()
                solver.add(constraint[1])
            if solver.check() == z3.sat:
                model = solver.model()
            else:
                print("unsatisfiable")

        return model
