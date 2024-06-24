#!/usr/bin/env sh


# export AFL_I_DONT_CARE_ABOUT_MISSING_CRASHES=1
export AFL_IGNORE_SEED_PROBLEMS=1

timeout 10s ~/tools/afl-fuzz.sh -i our-indir -o our-outdir -x inputs.dict -- ./our-softplc @@
