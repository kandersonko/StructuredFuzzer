#include "iec_types.h"
#include "iec_std_lib.h"
#include <stdio.h>
#include <stdlib.h>

void config_init__(void);

extern INT *__IW0_0; // External reference to itemType
extern REAL *__QD0_0; // External reference to conveyorSpeed
extern BOOL *__QX0_0; // External reference to emergencyStopActivated

void fuzzer_harness(void) {
    printf("[+] Item Type (IW0.0) = %d\n", *__IW0_0);
    printf("[+] Conveyor Speed (QD0.0) = %f\n", *__QD0_0);
    printf("[+] Emergency Stop Activated (QX0.0) = %s\n", *__QX0_0 ? "TRUE" : "FALSE");

    // Simulate the operation of the safety-critical system
    switch(*__IW0_0) {
        case 1: // Fragile items
            if(*__QD0_0 != 0.5) {
                printf("Test failed: Incorrect speed for fragile items\n");
                abort();
            }
            break;
        case 2: // Standard items
            if(*__QD0_0 != 1.5) {
                printf("Test failed: Incorrect speed for standard items\n");
                abort();
            }
            break;
        case 3: // Heavy items
            if(*__QD0_0 != 2.0) { // Acknowledging the logical bug for the purpose of the test
                printf("Test failed: Incorrect speed for heavy items\n");
                abort();
            }
            break;
        default:
            // Unrecognized item type
            printf("Unrecognized item types\n");
            /* if(!(*__QX0_0)) { */
            /*     printf("Test failed: Emergency stop should be activated for unrecognized item types\n"); */
            /*     abort(); */
            /* } */
    }
}
