#!/bin/bash

COMPILER=~/projects/plc_runtime_fuzzer/runtime/compile.sh

folder=$1
program=$2
duration=$3
# run id defaults to 0
run_id=${4:-0}

cd $folder


if [ -d indir/ ]; then
  echo "input dir indir/ exists, skipping"
else
  echo "input dir indir/ does not exist, creating..."
  python ../../main.py -f $program
fi

# create the run folder
mkdir -p runs/run-${run_id}

# remove the previous indir in run folder
# rm -rf runs/run-${run_id}/indir

if [ -f harness ]; then
  echo "harness executable exists, skipping"
else
  echo "harness does not exist, creating"
  $COMPILER $program ./harness.c
fi

# cp harness our-softplc
# cp harness afl-softplc

# move the programs to the run folder
cp harness runs/run-${run_id}/harness
cp harness runs/run-${run_id}/our-softplc
cp harness runs/run-${run_id}/afl-softplc
cp harness runs/run-${run_id}/fuzzer-softplc

cp inputs.dict runs/run-${run_id}/afl-inputs.dict
cp inputs.dict runs/run-${run_id}/our-inputs.dict
cp inputs.dict runs/run-${run_id}/fuzzer-inputs.dict


# cp set_plc_input.c runs/run-${run_id}/set_plc_input.c

rm -rf runs/run-${run_id}/our-indir
rm -rf runs/run-${run_id}/fuzzer-indir
cp -r indir runs/run-${run_id}/our-indir
cp -r indir runs/run-${run_id}/fuzzer-indir

cd runs/run-${run_id}

mkdir -p afl-indir
echo "00" > afl-indir/testcase.txt

# delete the previous output folders
rm -rf our-outdir afl-outdir fuzzer-outdir
# create the output folders
mkdir -p our-outdir
mkdir -p afl-outdir
mkdir -p fuzzer-outdir

# delete fuzzer log
rm -rf libafl.log

echo "Running the fuzzers"

export AFL_IGNORE_SEED_PROBLEMS=1

# exit afl++ fuzzing after first crash
export AFL_BENCH_UNTIL_CRASH=1

# screen -dmS "${program}-afl" bash -c "timeout $duration apptainer exec ~/tools/afl.sif afl-fuzz -i our-indir -o our-outdir -x inputs.dict -- ./our-softplc @@"
#
# screen -dmS "${program}-our" bash -c "timeout $duration apptainer exec ~/tools/afl.sif afl-fuzz -i afl-indir -o afl-outdir -x inputs.dict -- ./afl-softplc @@"
timeout $duration apptainer exec ~/tools/afl.sif ~/tools/fuzzer -i fuzzer-indir -o fuzzer-outdir -n 1 -x fuzzer-inputs.dict -- ./fuzzer-softplc @@ &
timeout $duration apptainer exec ~/tools/afl.sif afl-fuzz -i our-indir -o our-outdir -x our-inputs.dict -- ./our-softplc @@ &
timeout $duration apptainer exec ~/tools/afl.sif afl-fuzz -i afl-indir -o afl-outdir -x afl-inputs.dict -- ./afl-softplc @@ &
wait
