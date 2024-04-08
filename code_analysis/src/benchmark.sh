#!/usr/bin/env sh


COMPILER=~/projects/plc_runtime_fuzzer/runtime/compile.sh

folder=$1
program=$2

cd $folder

python ~/projects/plc_runtime_fuzzer/code_analysis/src/main.py -b -f $program
