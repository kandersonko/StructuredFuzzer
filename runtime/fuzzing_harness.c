void fuzzing_harness(void *data, size_t size) {
  if(*__IX0_0 == 1 )
  {
    abort();
    if(*__IX0_1 == 1)
    {
      abort();
      if(*__IX0_2 == 1){
        abort();
      }
    }
  }
  else
  {
    printf("Test failed\n");
  }
}
