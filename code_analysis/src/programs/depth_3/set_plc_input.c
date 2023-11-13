#include "iec_std_lib.h"
#include "iec_types_all.h" 
#include <string.h>
#include <stdlib.h>
#include "/nethome/koffi/projects/plc_runtime_fuzzer/runtime/inputs.h"

    
extern BOOL *__IX0_0;
extern BOOL *__IX0_1;
extern BOOL *__IX0_2;

void set_plc_input(const char *name, const char *type, PLC_Value value) {

    if (strcmp(name, "%IX0.0") == 0) {
        if (strcmp(type, "BOOL") == 0) {
            *__IX0_0 = (BOOL)value._BOOL;
        }
        // Add more type checks if needed
    } else

    if (strcmp(name, "%IX0.1") == 0) {
        if (strcmp(type, "BOOL") == 0) {
            *__IX0_1 = (BOOL)value._BOOL;
        }
        // Add more type checks if needed
    } else

    if (strcmp(name, "%IX0.2") == 0) {
        if (strcmp(type, "BOOL") == 0) {
            *__IX0_2 = (BOOL)value._BOOL;
        }
        // Add more type checks if needed
    }
}