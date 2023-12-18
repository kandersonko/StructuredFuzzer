#include "iec_types.h"
#include "iec_std_lib.h"
#include <stdio.h>
#include <stdlib.h>

void config_init__(void);

extern BOOL *__IX0_0, *__QX0_0;

void fuzzer_harness(void) {
  printf("[+] input IX0.0 = %s\n", *__IX0_0? "TRUE" : "FALSE");

  printf("[+] output QX0.0 = %s\n", *__QX0_0? "TRUE" : "FALSE");

  if(*__QX0_0 == 1 )
  {
    abort();
  }
  else
  {
    printf("Test failed for the inputs\n");
  }
}
