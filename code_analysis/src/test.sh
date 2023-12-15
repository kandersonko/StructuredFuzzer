#!/bin/bash

# Define the range of the simulated Slurm array
array_start=0
array_end=189

# Get the list of programs to fuzz in the `programs` directory as a bash array
programs=($(ls programs))

# Loop to simulate Slurm array behavior
for SLURM_ARRAY_TASK_ID in $(seq $array_start $array_end); do
    # Calculate the program index and run ID
    program_index=$(($SLURM_ARRAY_TASK_ID / 10))
    run_id=$(($SLURM_ARRAY_TASK_ID % 10))

    # Select the program based on the calculated index
    program=${programs[$program_index]}

    # Echo the values for testing
    echo "Simulated Task ID: $SLURM_ARRAY_TASK_ID"
    echo "Program: $program, Run ID: $run_id"
    echo "-------------------------"
done

