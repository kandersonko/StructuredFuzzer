#include "iec_types.h"
#include "iec_std_lib.h"
#include <stdio.h>
#include <stdlib.h>

void config_init__(void);

extern INT *__IW0_0, *__IW0_1, *__QW0_0; // External references to currentTime, trafficCondition, and trafficLightState

void fuzzer_harness(void) {
    printf("[+] Current Time (IW0.0) = %d\n", *__IW0_0);
    printf("[+] Traffic Condition (IW0.1) = %d\n", *__IW0_1);
    printf("[+] Traffic Light State (QW0.0) = %d\n", *__QW0_0);

    // Simulate the operation of the safety-critical system
    switch(*__IW0_0) {
        case 0 ... 5: // Late night
            if(*__QW0_0 != 2) {
                printf("Test failed: Traffic light should be Yellow during late night\n");
                abort();
            }
            break;
        case 6 ... 9: // Morning rush hour
            if((*__IW0_1 == 3 && *__QW0_0 != 1) || (*__IW0_1 != 3 && *__QW0_0 != 0)) {
                printf("Test failed: Incorrect traffic light state during morning rush hour\n");
                abort();
            }
            break;
        case 10 ... 15: // Day time
            if(*__QW0_0 != 1) {
                printf("Test failed: Traffic light should be Green during day time\n");
                abort();
            }
            break;
        case 16 ... 19: // Evening rush hour
            if((*__IW0_1 == 3 && *__QW0_0 != 0) || (*__IW0_1 != 3 && *__QW0_0 != 1)) {
                printf("Test failed: Incorrect traffic light state during evening rush hour\n");
                abort();
            }
            break;
        case 20 ... 23: // Night
            if(*__QW0_0 != 2) {
                printf("Test failed: Traffic light should be Yellow during night\n");
                abort();
            }
            break;
        default:
            printf("Test failed: Invalid current time\n");
            abort();
    }
}
