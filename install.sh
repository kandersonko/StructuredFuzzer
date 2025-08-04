#!/usr/bin/env sh

mkdir -p /usr/local/bin/stfuzz/
export PATH="$HOME/.cargo/bin:$PATH"
export PATH="$HOME/.local/bin:$PATH"
export PATH="/usr/bin/:$PATH"

# # Install the afl++ fuzzer
# echo "=============================="
echo "Installing the AFL++ fuzzer..."

# apt-get update && apt-get install -y build-essential curl python3-dev automake cmake git flex bison libglib2.0-dev libpixman-1-dev python3-setuptools cargo libgtk-3-dev
# # try to install llvm 14 and install the distro default if that fails
# apt-get install -y lld-14 llvm-14 llvm-14-dev clang-14 || apt-get install -y lld llvm llvm-dev clang
# apt-get install -y gcc-$(gcc --version | head -n1 | sed 's/\..*//' | sed 's/.* //')-plugin-dev libstdc++-$(gcc --version | head -n1 | sed 's/\..*//' | sed 's/.* //')-dev
# apt-get install -y ninja-build # for QEMU mode

git clone https://github.com/AFLplusplus/AFLplusplus
cd AFLplusplus
make distrib
make install
cd ..
echo "AFL++ installed successfully."
# echo "=============================="

# # Setup the MATIEC compiler
# echo "=============================="
# if [ ! -d "/usr/local/bin/stfuzz/matiec" ]; then
#     echo "Matiec compiler not found. Cloning and setting up..."
#     echo "Setting up MATIEC compiler..."

#     # cd /usr/local/bin/stfuzz/

#     # clone matiec compiler
#     git clone https://github.com/nucleron/matiec

#     # compile matiec compiler
#     cd matiec/

#     autoreconf -i

#     ./configure
#     make

#     # Matiec compiler path
#     matiec_base_path="/usr/local/bin/stfuzz"

#     # Move the paths to the .bashrc
#     echo "export MATIEC_INCLUDE_PATH=${matiec_base_path}/matiec/lib" >>~/.bashrc
#     echo "export MATIEC_C_INCLUDE_PATH=${matiec_base_path}/matiec/lib/C" >>~/.bashrc
#     echo "export PATH=${matiec_base_path}/matiec:\$PATH" >>~/.bashrc

#     # Move the paths to the .zshrc
#     echo "export MATIEC_INCLUDE_PATH=${matiec_base_path}/matiec/lib" >>~/.zshrc
#     echo "export MATIEC_C_INCLUDE_PATH=${matiec_base_path}/matiec/lib/C" >>~/.zshrc
#     echo "export PATH=${matiec_base_path}/matiec:\$PATH" >>~/.zshrc

#     cd ..

#     cp -r matiec /usr/local/bin/stfuzz/

# else
#     echo "Matiec compiler is already set up."
#     fi
# echo "=============================="

# # Install the Rust compiler
# echo "=============================="
#     echo "Installing Rust..."
#     curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
# echo "=============================="


# # Install uv
# echo "=============================="
# if ! command -v uv &> /dev/null; then
#     echo "Installing uv..."
#     curl -LsSf https://astral.sh/uv/install.sh | sh
#     echo "export PATH=\$PATH:/root/.cargo/bin" >>~/.bashrc
# else
#     echo "uv is already installed."
#     fi
# echo "=============================="

# # Installing the fuzzer
# echo "=============================="
# echo "Installing the fuzzer 'stfuzz'..."
# # move the runtime compiler to the user bin directory
# cp runtime/build.sh /usr/local/bin/stfuzz/
# cd fuzzer
# cargo build --release
# # move the fuzzer to the user bin directory
# chmod +x target/release/fuzzer
# cp target/release/fuzzer /usr/local/bin/stfuzz/stfuzz
# cd ..
# echo "Fuzzer 'stfuzz' installed successfully."
# echo "=============================="


# # copy the dependencies to the user bin directory
# cp -r runtime/ /usr/local/bin/stfuzz/
# cp runtime/Makefile /usr/local/bin/stfuzz/
# cp runtime/stcompile.sh /usr/local/bin/stfuzz/stcompile

# mkdir -p /usr/local/bin/stfuzz/code_analysis/

# Install the tree-sitter parser
# # echo "=============================="
# echo "Installing tree-sitter parser..."
# # # Install nodejs and npm is not installed
# if ! command -v node &> /dev/null; then
#     echo "Node.js is not installed. Installing Node.js..."
#     apt-get install -y nodejs npm
# else
#     echo "Node.js is already installed."
# fi

cd code_analysis/

# install tree-sitter-cli
cargo install tree-sitter-cli --version 0.20.0

cd tree-sitter-structured-text

# tree-sitter --version
# tree-sitter generate

gcc -o parser.so -shared src/parser.c -Isrc -fPIC

cd ..


echo "Tree-sitter parser installed successfully."
echo "=============================="

# Installing the code analysis tool
echo "Installing the code analysis tool..."
uv add tree-sitter==0.21.0
uv pip install . --target /usr/local/bin/stfuzz/code_analysis/
SCRIPT_CONTENT=$(cat << 'EOF'
#!/usr/bin/env bash
PYTHONPATH="/usr/local/bin/stfuzz/code_analysis/" python3 -m analyzer.main "$@"
EOF
)
# Create the script file
echo "$SCRIPT_CONTENT" > /usr/local/bin/stfuzz/stcode
chmod +x /usr/local/bin/stfuzz/stcode


cd ..
echo "Code analysis tool installed successfully."
echo "=============================="


cp -r code_analysis/ /usr/local/bin/stfuzz/


# Add the paths to the user's bashrc
echo "export PATH=\$PATH:/usr/local/bin/stfuzz" >>~/.bashrc
echo "export PATH=\$PATH:/usr/local/bin/stfuzz" >>~/.zshrc

# # Source the .bashrc and .zshrc files to apply changes
echo "Sourcing .bashrc and .zshrc to apply changes..."
