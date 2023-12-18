#include "iec_types.h"
#include "iec_std_lib.h"
#include <stdio.h>
#include <stdlib.h>

void config_init__(void);

extern REAL *__ID0_0, *__ID0_1; // External references to currentTemperature and desiredTemperature
extern BOOL *__QX0_0, *__QX0_1, *__QX0_2; // External references to coolingSystemActivated, heatingSystemActivated, alertRaised

REAL MY_ABS_REAL(REAL x) {
    if(x < 0.0) {
        return -x;
    } else {
        return x;
    }
}
void fuzzer_harness(void) {
    printf("[+] Current Temperature (ID0.0) = %f\n", *__ID0_0);
    printf("[+] Desired Temperature (ID0.1) = %f\n", *__ID0_1);
    printf("[+] Cooling System Activated (QX0.0) = %s\n", *__QX0_0 ? "TRUE" : "FALSE");
    printf("[+] Heating System Activated (QX0.1) = %s\n", *__QX0_1 ? "TRUE" : "FALSE");
    printf("[+] Alert Raised (QX0.2) = %s\n", *__QX0_2 ? "TRUE" : "FALSE");

    REAL temperatureDifference = *__ID0_0 - *__ID0_1;

    // Simulate the operation of the safety-critical system
    if(temperatureDifference > 10.0) {
        // Cooling system should be activated
        if(!(*__QX0_0)) {
            printf("Test failed: Cooling system should be activated\n");
            abort();
        }
    } else if(temperatureDifference < -10.0) {
        // Heating system should be activated
        if(!(*__QX0_1)) {
            printf("Test failed: Heating system should be activated\n");
            abort();
        }
    } else {
        // Both systems should be deactivated
        if(*__QX0_0 || *__QX0_1) {
            printf("Test failed: Both cooling and heating systems should be deactivated\n");
            abort();
        }
    }

    // Check alert status based on temperature deviation
    if(MY_ABS_REAL(temperatureDifference) > 20.0 && !(*__QX0_2)) {
        printf("Test failed: Alert should be raised\n");
        abort();
    } else if(MY_ABS_REAL(temperatureDifference) <= 20.0 && *__QX0_2) {
        printf("Test failed: Alert should be lowered\n");
        abort();
    }
}
