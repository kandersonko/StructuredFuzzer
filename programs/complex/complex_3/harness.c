#include "iec_types.h"
#include "iec_std_lib.h"
#include <stdio.h>
#include <stdlib.h>

void config_init__(void);

extern REAL *__ID0_0, *__ID0_1; // External references to chemicalALevel and chemicalBLevel
extern BOOL *__QX0_0, *__QX0_1, *__QX0_2, *__QX0_3; // External references to valve1Open, valve2Open, mixerOn, isMixingSafe

void fuzzer_harness(void) {
    printf("[+] Chemical A Level (ID0.0) = %f\n", *__ID0_0);
    printf("[+] Chemical B Level (ID0.1) = %f\n", *__ID0_1);
    printf("[+] Valve 1 Open (QX0.0) = %s\n", *__QX0_0 ? "TRUE" : "FALSE");
    printf("[+] Valve 2 Open (QX0.1) = %s\n", *__QX0_1 ? "TRUE" : "FALSE");
    printf("[+] Mixer On (QX0.2) = %s\n", *__QX0_2 ? "TRUE" : "FALSE");
    printf("[+] Is Mixing Safe (QX0.3) = %s\n", *__QX0_3 ? "TRUE" : "FALSE");

    // Simulate the operation of the safety-critical system
    // both chemicals should be a specific range
    if(!((10.0 < *__ID0_0 && *__ID0_0 < 50.0) && (10.0 < *__ID0_1 && *__ID0_1 > 50.0))) {
        // Mixing should be considered safe
        if((*__QX0_3)) {
            printf("Test failed: Mixing conditions should not be safe\n");
            abort();
        }
        // Valves and mixer should be active
        if((*__QX0_0) || (*__QX0_1) || (*__QX0_2)) {
            printf("Test failed: Valves and mixer should not be active\n");
            abort();
        }
    } else {
        // Mixing should not be considered safe
        if(!*__QX0_3) {
            printf("Test failed: Mixing conditions should be safe\n");
            abort();
        }
        // Valves and mixer should be inactive
        if(!*__QX0_0 || !*__QX0_1 || !*__QX0_2) {
            printf("Test failed: Valves and mixer should be active\n");
            abort();
        }
    }
}
