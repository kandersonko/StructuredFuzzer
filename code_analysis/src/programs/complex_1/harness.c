#include "iec_types.h"
#include "iec_std_lib.h"
#include <stdio.h>
#include <stdlib.h>

void config_init__(void);

extern INT *__IW0_0, *__QW0_0; // External references to sensorValue and safeThreshold
extern BOOL *__QX0_1; // External reference to emergencyStop

void fuzzer_harness(void) {
    printf("[+] Sensor Value (IW0.0) = %d\n", *__IW0_0);
    printf("[+] Safe Threshold (QW0.0) = %d\n", *__QW0_0);
    printf("[+] Emergency Stop (QX0.1) = %s\n", *__QX0_1 ? "TRUE" : "FALSE");

    // Simulate the operation of the safety-critical system
    if(*__IW0_0 < *__QW0_0) {
        // Emergency stop should NOT be activated (logical bug in the program)
        if(*__QX0_1) {
            printf("Test failed: Emergency stop incorrectly activated when sensor value is BELOW the threshold\n");
            abort();
        }
    }
    else {
        // Emergency stop SHOULD be activated
        if((*__QX0_1)) {
            printf("Test failed: Emergency stop not activated when sensor value is ABOVE or EQUAL to the threshold\n");
            abort();
        }
    }
}
