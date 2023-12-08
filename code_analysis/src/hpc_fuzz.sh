#!/bin/bash
#SBATCH -N 1
#SBATCH --time=04:00:00
#SBATCH --mem=8G
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=2
#SBATCH -p reg
#SBATCH --array=0-2
#SBATCH --output=jobs/fuzz_%A_%a.stdout
#SBATCH --error=jobs/fuzz_%A_%a.stderr

cd $SLURM_SUBMIT_DIR

echo "JOB timestamp: $(date)"
echo "JOB ID: $SLURM_JOB_ID"
echo "Array Task ID: $SLURM_ARRAY_TASK_ID"
cd $SLURM_SUBMIT_DIR


hostname

# source /usr/modules/init/bash
source ~/.bashrc

# activate conda environment
conda activate plc

conda env list

module load gcc/11.3.0
module load cmake

# gcc version
gcc --version

python --version
which python

# duration of 4 hours
duration=$((60 * 60 * 4))

# Get the list of programs to fuzz in the `programs` directory as bash array
programs=($(ls programs))

# fuzz the program at the index of the array task id
program=${programs[$SLURM_ARRAY_TASK_ID]}
echo "Fuzzing program: $program"

srun ./fuzz.sh ./programs/$program "$program.st" $duration $SLURM_ARRAY_TASK_ID
