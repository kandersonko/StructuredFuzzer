#include "iec_types.h"
#include "iec_std_lib.h"
#include <stdio.h>
#include <stdlib.h>

void config_init__(void);

extern INT *__IW0_0, *__IW0_1; // External references to smokeLevel and temperature
extern BOOL *__QX0_0, *__QX0_1, *__QX0_2, *__QX0_3, *__QX0_4; // External references to smokeDetected, heatDetected, fireAlarmOn, sprinklerSystemActivated, emergencyServicesNotified

void fuzzer_harness(void) {
    printf("[+] Smoke Level (IW0.0) = %d\n", *__IW0_0);
    printf("[+] Temperature (IW0.1) = %d\n", *__IW0_1);
    printf("[+] Smoke Detected (QX0.0) = %s\n", *__QX0_0 ? "TRUE" : "FALSE");
    printf("[+] Heat Detected (QX0.1) = %s\n", *__QX0_1 ? "TRUE" : "FALSE");
    printf("[+] Fire Alarm On (QX0.2) = %s\n", *__QX0_2 ? "TRUE" : "FALSE");
    printf("[+] Sprinkler System Activated (QX0.3) = %s\n", *__QX0_3 ? "TRUE" : "FALSE");
    printf("[+] Emergency Services Notified (QX0.4) = %s\n", *__QX0_4 ? "TRUE" : "FALSE");

    // Simulate the operation of the safety-critical system
    if(*__IW0_0 > 50 || *__IW0_1 > 100) {
        // Both smoke and heat detected
        if(!(*__QX0_2) || !(*__QX0_3) || !(*__QX0_4)) {
            printf("Test failed: Alarm, sprinkler, and notification should be activated\n");
            abort();
        }
    } else {
        // Either smoke or heat is not detected
        if(*__QX0_2 || *__QX0_3 || *__QX0_4) {
            printf("Test failed: Alarm, sprinkler, and notification should be deactivated\n");
            abort();
        }
    }
}
