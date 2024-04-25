#!/bin/bash
#SBATCH -N 1
#SBATCH --time=24:00:00
#SBATCH --mem=4G
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=1
#SBATCH --cpus-per-task=4
#SBATCH -p reg
#SBATCH --array=100-120
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

# duration of 24 hours
duration=$((60 * 60 * 24))

# Get the list of programs to fuzz in the `programs` directory as bash array
folder=width
programs=($(ls programs/$folder))
num_programs=${#programs[@]}

echo "Number of programs: $num_programs"
echo "Programs: ${programs[*]}"

# Calculate the program index based on SLURM_ARRAY_TASK_ID and the number of programs
program_index=$(($SLURM_ARRAY_TASK_ID % $num_programs))

# Select the program based on the calculated index
program=${programs[$program_index]}
echo "Fuzzing program: $program, Job ID: $SLURM_ARRAY_TASK_ID"

srun ./fuzz.sh programs/$folder/${program} ${program}.st ${duration} $SLURM_ARRAY_TASK_ID

wait
