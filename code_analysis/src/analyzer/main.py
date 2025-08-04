#!/usr/bin/env python3

import os
from tree_sitter import Language, Parser
import argparse
from pathlib import Path

from analyzer.constraints import ConstraintVisitor
from analyzer.generate import generate_plc_input_function
import time
from datetime import datetime
import logging

logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(levelname)s - %(message)s')
logger = logging.getLogger(__name__)

def main():
    arg_parser = argparse.ArgumentParser()
    arg_parser.add_argument("-f", "--file", required=True, help="structured text program file")
    arg_parser.add_argument("-c", "--corpus", required=True, help="corpus directory for the fuzzer")
    arg_parser.add_argument("-o", "--output_dir", required=True, help="output directory for the generated PLC input code")
    arg_parser.add_argument("-b", "--benchmark", action="store_true", help="benchmark the program")

    args = arg_parser.parse_args()

    # Load the compiled grammar
    language_path = Path(__file__).parent.parent / "tree-sitter-structured-text" / "parser.so"
    STRUCTURED_TEXT_LANGUAGE = Language(str(language_path), 'structured_text')

    # Create a Tree-sitter parser
    parser = Parser()
    parser.set_language(STRUCTURED_TEXT_LANGUAGE)

    start_time = time.time()

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

    logger.info(f"Extracted {len(constraint_visitor.variables)} variables from the structured text program.")
    corpus_dir = Path(args.corpus)
    corpus_dir.mkdir(parents=True, exist_ok=True)
    output_dir = Path(args.output_dir)
    output_dir.mkdir(parents=True, exist_ok=True)
    filename = corpus_dir / "variables.txt"

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

    # print("plc_inputs: ", plc_inputs)
    logger.info(f"Extracted {len(plc_inputs)} PLC inputs from the structured text program.")
    plc_input_code = generate_plc_input_function(plc_inputs)
    logger.info("Generated PLC input code.")
    # write the plc input code to a file
    # filename = parent_dir / "set_plc_input.c"
    filename = output_dir / "set_plc_input.c"
    if not args.benchmark:
        Path(filename).write_text(plc_input_code)

    else:
        # measure the time taken to generate the plc input code
        end_time = time.time()
        duration = end_time - start_time
        logger.info(f"Time taken to generate PLC input code: {duration:.2f} seconds")
        # save the duration to a file with date and time and the program name appended
        filename = output_dir / f"duration_{Path(args.file).name}_{datetime.now().strftime('%Y-%m-%d_%H-%M-%S')}.txt"
        Path(filename).write_text(str(duration))

if __name__ == '__main__':
    main()
