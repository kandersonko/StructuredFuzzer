#!/bin/bash

# clone matiec compiler
git clone https://github.com/nucleron/matiec

# compile matiec compiler
cd matiec/

autoreconf -i

./configure
make

# Matiec compiler path
script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
matiec_base_path="$script_dir"

# Move the paths to the .bashrc
echo "export MATIEC_INCLUDE_PATH=${matiec_base_path}/matiec/lib" >>~/.bashrc
echo "export MATIEC_C_INCLUDE_PATH=${matiec_base_path}/matiec/lib/C" >>~/.bashrc
echo "export PATH=${matiec_base_path}/matiec:\$PATH" >>~/.bashrc

# Move the paths to the .zshrc
echo "export MATIEC_INCLUDE_PATH=${matiec_base_path}/matiec/lib" >>~/.zshrc
echo "export MATIEC_C_INCLUDE_PATH=${matiec_base_path}/matiec/lib/C" >>~/.zshrc
echo "export PATH=${matiec_base_path}/matiec:\$PATH" >>~/.zshrc
