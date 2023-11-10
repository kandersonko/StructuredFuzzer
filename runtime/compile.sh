#!/bin/bash

STFILE=$1
HARNESS=$2

current_dir=$(pwd)


STFILE_PATH=$(realpath $STFILE)
HARNESS_PATH=$(realpath $HARNESS)

# output file is the same as the harness file, but without the .c extension
OUTFILE=$(basename $HARNESS .c)

# the path to the output file is the same as the path to the harness
OUTFILE_PATH=$(dirname `realpath $HARNESS`)/$OUTFILE

# input file
INPUT_PATH=$(dirname `realpath $HARNESS`)/set_plc_input.c

# use pushd to change directory to the directory of the script
build_dir=~/projects/plc_runtime_fuzzer/runtime/

export AFL_LLVM_DICT2FILE=~/auto_dictionary

pushd $build_dir

./build.sh ${STFILE_PATH} fresh ${OUTFILE_PATH} ${HARNESS_PATH} ${INPUT_PATH}

# move the dictionary to the current directory
popd 

echo `pwd`

mv ~/auto_dictionary inputs.dict
