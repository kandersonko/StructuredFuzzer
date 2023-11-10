#!/bin/bash

#/usr/bin/zsh

# conda activate plc

COMPILER=~/projects/plc_runtime_fuzzer/runtime/compile.sh

folder=$1
program=$2
duration=$3

cd $folder

python ../../main.py -f $program
$COMPILER $program ./harness.c

cp harness our-softplc
cp harness afl-softplc

mv indir our-indir

mkdir -p afl-indir
echo "00" > afl-indir/testcase

rm -rf our-outdir afl-outdir

screen -dmS "${program}-afl" bash -c "timeout $duration afl-fuzz -i our-indir -o our-outdir -x inputs.dict -- ./our-softplc @@" 


screen -dmS "${program}-our" bash -c "timeout $duration afl-fuzz -i afl-indir -o afl-outdir -x inputs.dict -- ./afl-softplc @@"
