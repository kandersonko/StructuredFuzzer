#include "iec_types.h"
#include "iec_std_lib.h"
#include <stdio.h>
#include <stdlib.h>

void config_init__(void);

extern BOOL *__IW0_0, *__QW0_0;

void fuzzer_harness(void) {
  printf("[+] input IW0.0 = %d\n", *__IW0_0);

  printf("[+] output QW0.0 = %d\n", *__QW0_0);

  if(*__IW0_0 == 10 )
  {
    abort();
  }
  else if(*__IW0_0 == 20)
  {
    abort();
  }
  else
  {
    printf("Test failed for the inputs\n");
  }
}
