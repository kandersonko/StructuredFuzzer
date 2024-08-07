#!/usr/bin/env sh

# Setup the MATIEC compiler
echo "=============================="
echo "Setting up MATIEC compiler..."
./setup_matiec.sh
echo "=============================="

# Install the Rust compiler
echo "=============================="
echo "Installing Rust compiler..."
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
echo "=============================="

# Installing the fuzzer
echo "=============================="
echo "Installing the fuzzer 'stfuzz'..."
# move the runtime compiler to the user bin directory
sudo mkdir -p /usr/local/bin/stfuzz/
sudo cp runtime/build.sh /usr/local/bin/stfuzz/
sudo cp runtime/compile.sh /usr/local/bin/stfuzz/stcompile
cd fuzzer
cargo build --release
# move the fuzzer to the user bin directory
chmod +x target/release/fuzzer
sudo cp target/release/fuzzer /usr/local/bin/stfuzz/stfuzz
cd ..

# Install the afl++ fuzzer
echo "=============================="
echo "Installing the AFL++ fuzzer..."
git clone https://github.com/AFLplusplus/AFLplusplus

sudo apt-get update
sudo apt-get install -y build-essential python3-dev automake cmake git flex bison libglib2.0-dev libpixman-1-dev python3-setuptools cargo libgtk-3-dev
# try to install llvm 14 and install the distro default if that fails
sudo apt-get install -y lld-14 llvm-14 llvm-14-dev clang-14 || sudo apt-get install -y lld llvm llvm-dev clang
sudo apt-get install -y gcc-$(gcc --version | head -n1 | sed 's/\..*//' | sed 's/.* //')-plugin-dev libstdc++-$(gcc --version | head -n1 | sed 's/\..*//' | sed 's/.* //')-dev
sudo apt-get install -y ninja-build # for QEMU mode
git clone https://github.com/AFLplusplus/AFLplusplus
cd AFLplusplus
make distrib
sudo make install

# copy the dependencies to the user bin directory
sudo cp -r runtime/*.c /usr/local/bin/stfuzz/
sudo cp runtime/Makefile /usr/local/bin/stfuzz/
sudo cp code_analysis/src/*.py /usr/local/bin/stfuzz/
sudo cp code_analysis/src/*.sh /usr/local/bin/stfuzz/
sudo cp -r code_analysis/tree-sitter-structured-text/ /usr/local/bin/stfuzz/
sudo cp -r code_analysis/rebuild.sh /usr/local/bin/stfuzz/build-tree-sitter.sh

sudo cp -r code_analysis/requirements.txt /usr/local/bin/stfuzz/

# Install the tree-sitter parser
cd /usr/local/bin/stfuzz/
pip install -r requirements.txt

sudo ./build-tree-sitter.sh

# Add the paths to the user's bashrc
echo "export PATH=\$PATH:/usr/local/bin/stfuzz" >>~/.bashrc
echo "export PATH=\$PATH:/usr/local/bin/stfuzz" >>~/.zshrc
