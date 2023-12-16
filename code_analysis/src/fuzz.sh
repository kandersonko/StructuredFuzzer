#!/bin/bash

COMPILER=~/projects/plc_runtime_fuzzer/runtime/compile.sh

folder=$1
program=$2
duration=$3
# run id defaults to 0
run_id=${4:-0}

cd $folder


# rm -rf indir/

python ../../main.py -f $program

# create the run folder
mkdir -p runs/run-${run_id}

# remove the previous indir in run folder
# rm -rf runs/run-${run_id}/indir

$COMPILER $program ./harness.c
# cp harness our-softplc
# cp harness afl-softplc

# move the programs to the run folder
cp harness runs/run-${run_id}/harness
cp harness runs/run-${run_id}/our-softplc
cp harness runs/run-${run_id}/afl-softplc
cp inputs.dict runs/run-${run_id}/inputs.dict

# cp set_plc_input.c runs/run-${run_id}/set_plc_input.c

rm -rf runs/run-${run_id}/our-indir
cp -r indir runs/run-${run_id}/our-indir

cd runs/run-${run_id}

mkdir -p afl-indir
echo "00" > afl-indir/testcase.txt

# create the output folders
mkdir -p our-outdir
mkdir -p afl-outdir

echo "Running the fuzzers"

export AFL_IGNORE_SEED_PROBLEMS=1

# screen -dmS "${program}-afl" bash -c "timeout $duration apptainer exec ~/tools/afl.sif afl-fuzz -i our-indir -o our-outdir -x inputs.dict -- ./our-softplc @@"
#
# screen -dmS "${program}-our" bash -c "timeout $duration apptainer exec ~/tools/afl.sif afl-fuzz -i afl-indir -o afl-outdir -x inputs.dict -- ./afl-softplc @@"
timeout $duration apptainer exec ~/tools/afl.sif afl-fuzz -i our-indir -o our-outdir -x inputs.dict -- ./our-softplc @@ &
timeout $duration apptainer exec ~/tools/afl.sif afl-fuzz -i afl-indir -o afl-outdir -x inputs.dict -- ./afl-softplc @@ &
wait
