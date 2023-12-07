#!/bin/bash

# clone matiec compiler
git clone https://github.com/nucleron/matiec

# compile matiec compiler
cd matiec/

autoreconf -i

./configure; make

# Matiec compiler path
matiec_base_path=$HOME/projects/plc_runtime_fuzzer
export MATIEC_INCLUDE_PATH=${matiec_base_path}/matiec/lib
export MATIEC_C_INCLUDE_PATH=${matiec_base_path}/matiec/lib/C
export PATH=${matiec_base_path}/matiec:$PATH
