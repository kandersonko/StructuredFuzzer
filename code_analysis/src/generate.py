import os

def generate_plc_input_function(plc_inputs):
    """
    This function takes a list of PLC inputs where each input is a dictionary
    with 'name' and 'type' keys. It generates the corresponding C file content
    as a string, including extern variable definitions and the set_plc_input function.
    """
    
    # Define the mapping for PLC types to C types and union member access
    type_mapping = {
        'BOOL': ('BOOL', '_BOOL'),
        'INT': ('INT', '_INT'),
        'REAL': ('REAL', '_REAL'),
    }
    
    # Initialize a list to hold extern variable definitions and input checks
    extern_defs = []
    input_checks = []
    
    for plc_input in plc_inputs:
        input_name = plc_input['name']
        input_type = plc_input['type']

        # Validate input type
        if input_type not in type_mapping:
            raise ValueError(f"Unsupported PLC type: {input_type}")

        cast_type, union_member = type_mapping[input_type]
        pointer_name = input_name.replace('%', '__').replace('.', '_')
        
        # Add the extern definition for the variable
        extern_defs.append(f"extern {cast_type} *{pointer_name};")
        
        # Create the individual check for this input
        input_check = f"""
    if (strcmp(name, "{input_name}") == 0) {{
        if (strcmp(type, "{input_type}") == 0) {{
            *{pointer_name} = ({cast_type})value.{union_member};
        }}
        // Add more type checks if needed
    }} else"""
        input_checks.append(input_check)
    
    # Remove the 'else' from the last check
    if input_checks:
        input_checks[-1] = input_checks[-1].rsplit(' else', 1)[0]
    
    # Join all the extern definitions and input checks into strings
    extern_defs_str = '\n'.join(extern_defs)
    input_checks_str = '\n'.join(input_checks)

    # get inputs.h path, should home path followed by plc_runtime_fuzzer/runtime/inputs.h
    input_h_path = os.path.join(os.environ['HOME'], '/nethome/koffi/projects/plc_runtime_fuzzer/runtime/inputs.h')

    input_headers = f"""
#include "iec_std_lib.h"
#include "iec_types_all.h" 
#include <string.h>
#include <stdlib.h>
#include "{input_h_path}"
"""
    
    # Define the C function template with extern definitions and function body
    c_file_content_template = """
{input_headers}
    
{extern_defs}

void set_plc_input(const char *name, const char *type, PLC_Value value) {{
{input_checks}
}}
"""
    
    # Format the C file content with the correct placeholders
    c_file_content = c_file_content_template.format(
        extern_defs=extern_defs_str,
        input_checks=input_checks_str,
        input_headers=input_headers,
    )
    
    return c_file_content.strip()


