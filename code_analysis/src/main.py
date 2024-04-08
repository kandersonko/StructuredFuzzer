#!/usr/bin/env python3

import os
from tree_sitter import Language, Parser
import argparse
from pathlib import Path

from constraints import ConstraintVisitor
from generate import generate_plc_input_function
import time
from datetime import datetime

arg_parser = argparse.ArgumentParser()
arg_parser.add_argument("--file", "-f", required=True, help="structured text program file")
# add the benchmark boolean argument with default value False
arg_parser.add_argument("--benchmark", "-b", action="store_true", help="benchmark the program")

args = arg_parser.parse_args()

# Load the compiled grammar
language_path = Path().home() / "projects/plc_runtime_fuzzer/code_analysis/tree-sitter-structured-text/parser.so"
STRUCTURED_TEXT_LANGUAGE = Language(language_path, 'structured_text')

# Create a Tree-sitter parser
parser = Parser()
parser.set_language(STRUCTURED_TEXT_LANGUAGE)

start_time = time.time()

if __name__ == '__main__':
    # read the structured text program file
    code = Path(args.file).read_bytes()

    tree = parser.parse(code)
    # Print the root node of the AST
    print(tree.root_node.sexp())

    constraint_visitor = ConstraintVisitor()

    constraint_visitor(tree.root_node)
    # constraints = contraint_visitor.constraints
    # print("constraints: ", constraints)

    # model = contraint_visitor.solve()
    # print("model: ", model)

    print()

    print("variables: ", constraint_visitor.variables)
    parent_dir = Path(args.file).parent
    Path(parent_dir / "indir").mkdir(parents=True, exist_ok=True)
    filename = parent_dir / f"indir/variables.txt"
    # delete the file if it exists
    # if Path(filename).exists():
    #     os.remove(filename)

    plc_inputs = []
    
    # store the variables in a file
    for variable_name, variable_value in constraint_visitor.variables.items():
        variable_type = variable_value[0]
        variable_address = variable_value[1]
        # store only the input variables with an address
        if variable_address and "%I" in variable_address:
            content = f"{variable_address},{variable_type},9\n"
            # save the variable in a file, append the variable if the file exists
            print("content: ", content)
            plc_inputs.append({"name": variable_address, "type": variable_type, "value": 9})
            with open(filename, "a") as f:
                f.write(content)

    print("plc_inputs: ", plc_inputs)
    plc_input_code = generate_plc_input_function(plc_inputs)
    print("plc_input_code: ", plc_input_code)
    # write the plc input code to a file
    filename = parent_dir / "set_plc_input.c"
    if not args.benchmark:
        Path(filename).write_text(plc_input_code)

    else:
        # measure the time taken to generate the plc input code
        end_time = time.time()
        duration = end_time - start_time
        print("duration: ", duration)
        # save the duration to a file with date and time and the program name appended
        filename = parent_dir / f"duration_{Path(args.file).name}_{datetime.now().strftime('%Y-%m-%d_%H-%M-%S')}.txt"
        Path(filename).write_text(str(duration))
