#!/bin/bash

# conda activate plc

COMPILER=~/projects/plc_runtime_fuzzer/runtime/compile.sh

folder=$1
program=$2
duration=$3
# run id defaults to 0
run_id=${4:-0}

cd $folder

python ../../main.py -f $program

$COMPILER $program ./harness.c

cp harness our-softplc
cp harness afl-softplc

rm -rf our-indir

mv indir our-indir

mkdir -p afl-indir
echo "00" > afl-indir/testcase

# rm -rf our-outdir afl-outdir
mkdir our-outdir/run_${run_id} afl-outdir/run_${run_id}

export AFL_IGNORE_SEED_PROBLEMS=1

screen -dmS "${program}-afl" bash -c "timeout $duration ~/tools/afl-fuzz.sh -i our-indir -o our-outdir -x inputs.dict -- ./our-softplc @@"


screen -dmS "${program}-our" bash -c "timeout $duration ~/tools/afl-fuzz.sh -i afl-indir -o afl-outdir -x inputs.dict -- ./afl-softplc @@"
