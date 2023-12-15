#!/bin/bash

# Determine the directory where this script is located
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"

# Check if an argument is provided
if [ -z "$1" ]; then
    echo "Usage: $0 <path_to_main.st>"
    exit 1
fi

STFILE="$(realpath $1)"
EXECUTABLE_NAME=${3:-softplc}
HARNESS="$(realpath $4)"
SET_INPUT="$(realpath $5)"

CC=afl-clang-fast
IECGENERATEDSOURCES="STD_CONF.c STD_RESSOURCE.c"  # These will be generated in the temp folder
SOURCES="$IECGENERATEDSOURCES main.c plc.c"
CFLAGS="-std=gnu99 -w -I $MATIEC_C_INCLUDE_PATH -c"
LDFLAGS="-lrt"

# export AFL_LLVM_DICT2FILE=~/auto_dictionary

# Create a temporary directory within the script's directory
TMP_DIR=$(mktemp -d "$SCRIPT_DIR/tmp.XXXXXX")
echo "Created temporary directory: $TMP_DIR"

# Copy main.c and plc.c to the temporary directory
cp "$SCRIPT_DIR/main.c" "$TMP_DIR/"
cp "$SCRIPT_DIR/plc.c" "$TMP_DIR/"
cp "$SCRIPT_DIR/inputs.h" "$TMP_DIR/"

# Change to the temporary directory
cd $TMP_DIR

build() {
    # Check if STFILE exists
    if [ ! -f "$STFILE" ]; then
        echo "Error: $STFILE not found!"
        exit 2
    fi

    # Generate IEC sources from ST file
    echo "Generating IEC sources from ST file"
    iec2c $STFILE -I $MATIEC_INCLUDE_PATH

    # Compile the sources
    OBJECTS=""
    for source in $SOURCES; do
        object_file=$(basename ${source//.c/.o})
        $CC $CFLAGS $source -o $object_file
        OBJECTS="$OBJECTS $object_file"  # Append the object file name to OBJECTS
    done

    # compile the fuzzing harness
    echo "Compiling the fuzzing harness"
    $CC $CFLAGS $HARNESS -o harness.o

    echo "Compiling the set_input"
    $CC $CFLAGS $SET_INPUT -o SET_INPUT.o

    # Link the object files with the fuzzing harness
    echo "Creating the executable"
    $CC $OBJECTS harness.o SET_INPUT.o -o $EXECUTABLE_NAME $LDFLAGS

    # Move the executable to the original directory
    # mv $EXECUTABLE_NAME "$(dirname $STFILE)/$(basename $EXECUTABLE_NAME)"

}

clean() {
    rm -rf $TMP_DIR
    echo "Cleaned up temporary directory."
}

# # Check for additional command-line arguments
# if [[ "$2" == "clean" ]]; then
#     clean
#     exit 0
# elif [[ "$2" == "fresh" ]]; then
#     clean
#     build
#     exit 0
# fi

# Default build
build
