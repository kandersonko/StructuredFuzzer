#!/bin/bash

ST_FILE=$1

CURRENT_DIR=`pwd`

cd ~/projects/plc_runtime_fuzzer/runtime/

./build.sh $CURRENT_DIR/${ST_FILE}

cp softplc $CURRENT_DIR/softplc
