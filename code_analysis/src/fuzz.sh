#!/bin/bash

script_dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
stfuzz_dir=/usr/local/bin/stfuzz/
COMPILER="${stfuzz_dir}/runtime/compile.sh"


folder=$1
program=$2
duration=$3
# run id defaults to 0
run_id=${4:-0}
# fuzzer default to afl-fuzz
fuzzer=${5:-afl-fuzz}

cd $folder

# rm -rf indir/
if [ -d ./indir/ ]; then
  echo "input dir exist, skipping"
else
  echo "input dir does not exist, creating"
  python ${script_dir}/main.py -f $program
fi

# create the run folder
mkdir -p runs/run-${run_id}

# remove the previous indir in run folder
# rm -rf runs/run-${run_id}/indir

if [ -f harness ]; then
  echo "harness file exist, skipping"
else
  echo "harness executable does not exist, creating"
  $COMPILER $program ./harness.c
fi

cp harness our-softplc-$run_id
cp harness afl-softplc-$run_id

# move the programs to the run folder
cp harness runs/run-${run_id}/harness
cp harness runs/run-${run_id}/fuzzer-softplc-$run_id
cp harness runs/run-${run_id}/our-softplc-$run_id
cp harness runs/run-${run_id}/afl-softplc-$run_id
cp inputs.dict runs/run-${run_id}/afl-inputs.dict
cp inputs.dict runs/run-${run_id}/our-inputs.dict
cp inputs.dict runs/run-${run_id}/fuzzer-inputs.dict


# cp set_plc_input.c runs/run-${run_id}/set_plc_input.c

# rm -rf runs/run-${run_id}/our-indir
rm -rf runs/run-${run_id}/fuzzer-indir
cp -r indir runs/run-${run_id}/our-indir
cp -r indir runs/run-${run_id}/fuzzer-indir

cd runs/run-${run_id}

mkdir -p afl-indir
echo "00" > afl-indir/testcase.txt

# remove previous output folders
rm -rf our-outdir afl-outdir 
rm -rf fuzzer-outdir
# create the output folders
mkdir -p our-outdir
mkdir -p afl-outdir
mkdir -p fuzzer-outdir

# remove fuzzer log
rm -rf libafl.log

echo "Running the fuzzers"

export AFL_IGNORE_SEED_PROBLEMS=1

# stop the afl++ fuzzer after first crash 
export AFL_BENCH_UNTIL_CRASH=1

# screen -dmS "${program}-afl" bash -c "timeout $duration apptainer exec ~/tools/afl.sif afl-fuzz -i our-indir -o our-outdir -x inputs.dict -- ./our-softplc-$run_id @@"
#
# screen -dmS "${program}-our" bash -c "timeout $duration apptainer exec ~/tools/afl.sif afl-fuzz -i afl-indir -o afl-outdir -x inputs.dict -- ./afl-softplc-$run_id @@"
timeout $duration apptainer exec ~/tools/afl.sif ~/tools/fuzzer -i fuzzer-indir -o fuzzer-outdir -x fuzzer-inputs.dict -n 1 -- ./fuzzer-softplc-$run_id @@ &
timeout $duration apptainer exec ~/tools/afl.sif afl-fuzz -i our-indir -o our-outdir -x our-inputs.dict -- ./our-softplc-$run_id @@ &
timeout $duration apptainer exec ~/tools/afl.sif afl-fuzz -i afl-indir -o afl-outdir -x afl-inputs.dict -- ./afl-softplc-$run_id @@ &
wait
