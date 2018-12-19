#!/bin/bash
#SBATCH --workdir /home/fgabriel
#SBATCH --nodes 1
#SBATCH --ntasks 1
#SBATCH --cpus-per-task 16
#SBATCH --mem 2G

echo STARTING AT `date`

./assignment2 1 10 1 output.csv

echo FINISHED at `date`
