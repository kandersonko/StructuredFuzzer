#!/bin/bash
#
# source ~/.bashrc

# Check if an argument is provided
if [ -z "$1" ]; then
    echo "Usage: $0 <path_to_main.st>"
    exit 1
fi

STFILE="$1"

EXECUTABLE=${3:-softplc}

# the fuzzing harness to use
HARNESS=$4
SET_INPUT=$5

CC=afl-clang-fast
# CC=gcc
# CC=arm-none-eabi-gcc
IECGENERATEDSOURCES="STD_CONF.c STD_RESSOURCE.c"
SOURCES="$IECGENERATEDSOURCES plc.c main.c"
OBJECTS=${SOURCES//.c/.o}
CFLAGS="-I $MATIEC_C_INCLUDE_PATH -c"
LDFLAGS="-lrt"

export AFL_LLVM_DICT2FILE=~/auto_dictionary

build() {
    # Check if STFILE exists
    if [ ! -f "$STFILE" ]; then
        echo "Error: $STFILE not found!"
        exit 2
    fi

    # Generate IEC sources from ST file
    iec2c $STFILE -I $MATIEC_INCLUDE_PATH

    # Compile the sources
    for source in $SOURCES; do
        object_file=${source//.c/.o}
        $CC $CFLAGS $source -o $object_file
    done
    
    # compile the fuzzing harness
    $CC $CFLAGS $HARNESS -o harness.o 
    
    $CC $CFLAGS $SET_INPUT -o SET_INPUT.o 

    # Link the object files with the fuzzing harness
    $CC $OBJECTS harness.o SET_INPUT.o -o $EXECUTABLE $LDFLAGS
    
    # $CC $OBJECTS -o $EXECUTABLE $LDFLAGS
}

clean() {
    rm -f POUS.c POUS.h LOCATED_VARIABLES.h VARIABLES.csv STD_CONF.c STD_CONF.h STD_RESSOURCE.c *.o $EXECUTABLE
}

# Check for additional command-line arguments
if [[ "$2" == "clean" ]]; then
    clean
    exit 0
elif [[ "$2" == "fresh" ]]; then
    clean
    build
    exit 0
fi

# Default build
build
