#include "iec_types.h"
#include "iec_std_lib.h"
#include <stdio.h>
#include <stdlib.h>

void config_init__(void);

extern REAL *__ID0_0, *__ID0_1, *__QD0_1; // External references to oxygenLevel, carbonDioxideLevel, airFlowRate
extern BOOL *__QX0_0, *__QX0_1; // External references to alarmActivated, ventilationOn

void fuzzer_harness(void) {
    printf("[+] Oxygen Level (ID0.0) = %f\n", *__ID0_0);
    printf("[+] Carbon Dioxide Level (ID0.1) = %f\n", *__ID0_1);
    printf("[+] Airflow Rate (QD0.1) = %f\n", *__QD0_1);
    printf("[+] Alarm Activated (QX0.0) = %s\n", *__QX0_0 ? "TRUE" : "FALSE");
    printf("[+] Ventilation On (QX0.1) = %s\n", *__QX0_1 ? "TRUE" : "FALSE");

    // Simulate the operation of the safety-critical system
    if(!(*__ID0_0 <= 21.0 && *__ID0_1 >= 0.5)) {
        // Ventilation should not be off
        if(!*__QX0_1) {
            printf("Test failed: Ventilation should be on\n");
            abort();
        }
    }
}
