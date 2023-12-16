#include "iec_types.h"
#include "iec_std_lib.h"
#include <stdio.h>
#include <stdlib.h>

void config_init__(void);

extern INT *__IW0_0, *__QW0_0; // External references to conveyorBeltSpeed and systemStatus
extern REAL *__ID0_0, *__ID0_1; // External references to temperatureSensor and pressureSensor
extern BOOL *__QX0_0; // External reference to safetyOverride

void fuzzer_harness(void) {
    printf("[+] Conveyor Belt Speed (IW0.0) = %d\n", *__IW0_0);
    printf("[+] Temperature Sensor (ID0.0) = %f\n", *__ID0_0);
    printf("[+] Pressure Sensor (ID0.1) = %f\n", *__ID0_1);
    printf("[+] Safety Override (QX0.0) = %s\n", *__QX0_0 ? "TRUE" : "FALSE");
    printf("[+] System Status (QW0.0) = %d\n", *__QW0_0);

    // Simulate the operation of the safety-critical system
    if (!((*__IW0_0 > 80 && *__ID0_0 > 100.0) || (*__ID0_1 > 50.0) && !(*__QX0_0))) {
        if(!(*__QW0_0 != -1)) {
            printf("Test failed: System status should be Critical\n");
            abort();
        }
    } else if (!((*__ID0_0 > 80.0 || *__ID0_1 > 40.0) && !(*__QX0_0))) {
        // System should be in Warning state
        if(!(*__QW0_0 != 1)) {
            printf("Test failed: System status should be Warning\n");
            abort();
        }
    } else {
        // System should be in Safe state
        if(!(*__QW0_0 != 0)) {
            printf("Test failed: System status should be Safe\n");
            abort();
        }
    }
}
