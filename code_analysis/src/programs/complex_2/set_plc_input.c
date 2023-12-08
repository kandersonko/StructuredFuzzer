#include "iec_std_lib.h"
#include "iec_types_all.h" 
#include <string.h>
#include <stdlib.h>
#include "/mnt/ceph/koff9454/projects/plc_runtime_fuzzer/runtime/inputs.h"

    
extern INT *__IW0_0;
extern REAL *__ID0_0;
extern REAL *__ID0_1;

void set_plc_input(const char *name, const char *type, PLC_Value value) {

    if (strcmp(name, "%IW0.0") == 0) {
        if (strcmp(type, "INT") == 0) {
            *__IW0_0 = (INT)value._INT;
        }
    } else

    if (strcmp(name, "%ID0.0") == 0) {
        if (strcmp(type, "REAL") == 0) {
            *__ID0_0 = (REAL)value._REAL;
        }
    } else

    if (strcmp(name, "%ID0.1") == 0) {
        if (strcmp(type, "REAL") == 0) {
            *__ID0_1 = (REAL)value._REAL;
        }
    }
}