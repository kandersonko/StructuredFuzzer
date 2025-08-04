#!/usr/bin/env sh


COMPILER=/usr/local/bin/stfuzz/plc_runtime_fuzzer/runtime/compile.sh

folder=$1
program=$2

cd $folder

python ./main.py -b -f $program
