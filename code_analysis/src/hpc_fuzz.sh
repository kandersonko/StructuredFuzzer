#!/bin/bash
#SBATCH -N 1
#SBATCH --time=04:00:00
#SBATCH --mem=12G
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=1
#SBATCH --cpus-per-task=2
#SBATCH -p reg
#SBATCH --array=0-1
#SBATCH --output=jobs/fuzz_%A_%a.stdout
#SBATCH --error=jobs/fuzz_%A_%a.stderr

echo "JOB timestamp: $(date)"
echo "JOB ID: $SLURM_JOB_ID"
echo "Array Task ID: $SLURM_ARRAY_TASK_ID"

cd $SLURM_SUBMIT_DIR

echo "Current directory: $(pwd)"

hostname

#source /usr/modules/init/bash
source ~/.bashrc

# activate conda environment
conda activate plc

module load gcc

# gcc version
gcc --version

python --version
which python

iec2c -v

# duration of 4 hours
duration=$((60 * 60 * 4))

# Get the list of programs to fuzz in the `programs` directory as bash array
programs=($(ls programs))

# Calculate the program index and run ID based on SLURM_ARRAY_TASK_ID
program_index=$(($SLURM_ARRAY_TASK_ID / 10))
run_id=$(($SLURM_ARRAY_TASK_ID % 10))

# Select the program based on the calculated index
program=${programs[$program_index]}
echo "Fuzzing program: $program, Run ID: $run_id"

srun ./fuzz.sh programs/${program} ${program}.st ${duration} $run_id

wait
