#!/bin/bash

STFILE=$1
HARNESS=$2

current_dir=$(pwd)

STFILE_PATH=$(realpath $STFILE)
HARNESS_PATH=$(realpath $HARNESS)

# output file is the same as the harness file, but without the .c extension
OUTFILE=$(basename $HARNESS .c)

# the path to the output file is the same as the path to the harness
OUTFILE_DIR=$(dirname $HARNESS_PATH)
OUTFILE_PATH=$OUTFILE_DIR/$OUTFILE

# input file
INPUT_PATH=$OUTFILE_DIR/set_plc_input.c

# The directory where the build.sh script is located
script_dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
build_dir="$script_dir"

# export AFL_LLVM_DICT2FILE=~/auto_dictionary
# Set AFL_LLVM_DICT2FILE to the output directory of the compiled program
export AFL_LLVM_DICT2FILE="$OUTFILE_DIR/inputs.dict"

# Change directory to the directory of the build script
pushd $build_dir

# Run the build script
python3 ../code_analysis/src/main.py -f ${STFILE_PATH}
./build.sh ${STFILE_PATH} fresh ${OUTFILE_PATH} ${HARNESS_PATH} ${INPUT_PATH}

# Return to the original directory
popd

echo "Current directory: $(pwd)"

# Move the dictionary and the executable to the current directory
# mv $build_dir/$AFL_LLVM_DICT2FILE inputs.dict
# mv $OUTFILE_PATH .

echo "Files moved to $(pwd)"

