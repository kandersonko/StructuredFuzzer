#include "iec_types.h"
#include "iec_std_lib.h"
#include <stdio.h>
#include <stdlib.h>

void config_init__(void);

extern INT *__IW0_0; // External reference to sensorReading
extern BOOL *__QX0_0, *__QX0_1, *__QX0_2, *__QX0_3, *__QX0_4; // External references to trainDetected, gateClosed, redLightOn, greenLightOn, warningAlarmOn

void fuzzer_harness(void) {
    printf("[+] Sensor Reading (IW0.0) = %d\n", *__IW0_0);
    printf("[+] Train Detected (QX0.0) = %s\n", *__QX0_0 ? "TRUE" : "FALSE");
    printf("[+] Gate Closed (QX0.1) = %s\n", *__QX0_1 ? "TRUE" : "FALSE");
    printf("[+] Red Light On (QX0.2) = %s\n", *__QX0_2 ? "TRUE" : "FALSE");
    printf("[+] Green Light On (QX0.3) = %s\n", *__QX0_3 ? "TRUE" : "FALSE");
    printf("[+] Warning Alarm On (QX0.4) = %s\n", *__QX0_4 ? "TRUE" : "FALSE");

    // Simulate the operation of the safety-critical system
    if(*__IW0_0 == 10 && *__QX0_0) {
        // Train is detected
        if(!(*__QX0_1) || !(*__QX0_2) || !*__QX0_3 || !(*__QX0_4)) {
            printf("Test failed: Incorrect control status when a train is detected\n");
            abort();
        }
    } else {
        // No train detected
        if(*__QX0_1 || *__QX0_2 || !(*__QX0_3) || *__QX0_4) {
            printf("Test failed: Incorrect control status when no train is detected\n");
            abort();
        }
    }
}
