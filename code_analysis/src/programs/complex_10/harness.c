#include "iec_types.h"
#include "iec_std_lib.h"
#include <stdio.h>
#include <stdlib.h>

void config_init__(void);

extern INT *__IW0_0; // External reference to reactorMode
extern REAL *__QD0_0, *__QD0_1; // External references to coolantFlowRate and controlRodPosition
extern BOOL *__QX0_0; // External reference to alarmActivated

void fuzzer_harness(void) {
    printf("[+] Reactor Mode (IW0.0) = %d\n", *__IW0_0);
    printf("[+] Coolant Flow Rate (QD0.0) = %f\n", *__QD0_0);
    printf("[+] Control Rod Position (QD0.1) = %f\n", *__QD0_1);
    printf("[+] Alarm Activated (QX0.0) = %s\n", *__QX0_0 ? "TRUE" : "FALSE");

    // Simulate the operation of the safety-critical system
    switch(*__IW0_0) {
        case 1: // Startup mode
            if(*__QD0_0 != 30.0 || *__QD0_1 != 20.0) {
                printf("Test failed: Incorrect settings for startup mode\n");
                abort();
            }
            break;
        case 2: // Normal operation mode
            if(*__QD0_0 != 50.0 || *__QD0_1 != 50.0) {
                printf("Test failed: Incorrect settings for normal operation mode\n");
                abort();
            }
            break;
        case 3: // Shutdown mode
            if(*__QD0_0 != 20.0 || *__QD0_1 != 100.0) { // Acknowledging the logical bug for the purpose of the test
                printf("Test failed: Incorrect settings for shutdown mode\n");
                abort();
            }
            break;
        case 4: // Emergency mode
            if(*__QD0_0 != 30.0 || *__QD0_1 != 100.0) { // Acknowledging the logical bug for the purpose of the test
                printf("Test failed: Incorrect settings for emergency mode\n");
                abort();
            }
            if(!(*__QX0_0)) {
                printf("Test failed: Alarm should be activated in emergency mode\n");
                abort();
            }
            break;
        default:
            // Unrecognized mode
            printf("Unrecognized mode\n");
    }

    // Check alarm status for non-emergency modes
    if(*__IW0_0 != 4 && *__QX0_0) {
        printf("Test failed: Alarm should be deactivated for non-emergency modes\n");
        abort();
    }
}
