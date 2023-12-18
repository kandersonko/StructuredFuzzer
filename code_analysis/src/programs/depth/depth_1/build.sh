#!/bin/bash
#
# source ~/.bashrc

ST_FILE=$1

CURRENT_DIR=`pwd`

cd ~/projects/plc_runtime_fuzzer/runtime/

# export AFL_LLVM_DICT2FILE=~/auto_dictionary

./build.sh $CURRENT_DIR/${ST_FILE}

# mv ~/auto_dictionary auto_dictionary.dict

cp softplc $CURRENT_DIR/softplc
