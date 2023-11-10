#include "iec_std_lib.h"
#include "iec_types_all.h" 
#include <string.h>
#include <stdlib.h>
#include "/nethome/koffi/projects/plc_runtime_fuzzer/runtime/inputs.h"

    
extern INT *__IW0_0;

void set_plc_input(const char *name, const char *type, PLC_Value value) {

    if (strcmp(name, "%IW0.0") == 0) {
        if (strcmp(type, "INT") == 0) {
            *__IW0_0 = (INT)value._INT;
        }
        // Add more type checks if needed
    }
}