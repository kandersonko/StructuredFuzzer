#!/bin/bash

# conda activate plc

COMPILER=~/projects/plc_runtime_fuzzer/runtime/compile.sh

folder=$1
program=$2
duration=$3
# run id defaults to 0
run_id=${4:-0}

cd $folder

rm -rf indir/

python ../../main.py -f $program

# check if the harness file exists
# if [ ! -f harness.c ]; then
#     echo "Harness file not found, compiling the program as the harness"
#     $COMPILER $program ./harness.c
#     cp harness our-softplc
#     cp harness afl-softplc
# else
#     echo "Harness file found, skipping compilation"
# fi

# create the run folder
mkdir -p runs/runs-${run_id}

# remove the previous indir in run folder
# rm -rf runs/runs-${run_id}/indir

mv indir/ runs/runs-${run_id}/

$COMPILER $program ./harness.c
cp harness our-softplc
cp harness afl-softplc

# move the programs to the run folder
mv harness runs/runs-${run_id}/harness
mv our-softplc runs/runs-${run_id}/our-softplc
mv afl-softplc runs/runs-${run_id}/afl-softplc
mv inputs.dict runs/runs-${run_id}/inputs.dict
mv set_plc_input.c runs/runs-${run_id}/set_plc_input.c

cd runs/runs-${run_id}

# remove previous runs indir folders
rm -rf our-indir/

mv indir our-indir

mkdir -p afl-indir
echo "00" > afl-indir/testcase.txt

# create the output folders
mkdir -p our-outdir
mkdir -p afl-outdir


export AFL_IGNORE_SEED_PROBLEMS=1

screen -dmS "${program}-afl" bash -c "timeout $duration ~/tools/afl-fuzz.sh -i our-indir -o our-outdir -x inputs.dict -- ./our-softplc @@"


screen -dmS "${program}-our" bash -c "timeout $duration ~/tools/afl-fuzz.sh -i afl-indir -o afl-outdir -x inputs.dict -- ./afl-softplc @@"
