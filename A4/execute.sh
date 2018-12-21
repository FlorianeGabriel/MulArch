#!/bin/bash
#SBATCH --workdir /home/vonfelte
#SBATCH --partition=gpu
#SBATCH --qos=gpu_free
#SBATCH --gres=gpu:1
#SBATCH --partition=gpu
#SBATCH --account cs307
#SBATCH --nodes=1
#SBATCH --time=1:0:0
#SBATCH --ntasks-per-node=1
#SBATCH --cpus-per-task=16


module load gcc cuda

echo STARTING AT `date`
make all

./assignment4 100 10

./assignment4 100 1000

./assignment4 1000 100

./assignment4 1000 10000

echo FINISHED at `date`
