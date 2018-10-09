#!/bin/bash
#SBATCH --workdir /scratch/<username>
#SBATCH --nodes 1
#SBATCH --ntasks 1
#SBATCH --cpus-per-task 1
#SBATCH --mem 1G

echo STARTING AT `date`

./pi 1 5000000000
./pi 2 5000000000
./pi 4 5000000000
./pi 8 5000000000
./pi 16 5000000000
./pi 32 5000000000
./pi 48 5000000000
./pi 64 5000000000

./integral 1 5000000000 5 9
./integral 2 5000000000 5 9
./integral 4 5000000000 5 9
./integral 8 5000000000 5 9
./integral 16 5000000000 5 9
./integral 32 5000000000 5 9
./integral 48 5000000000 5 9
./integral 64 5000000000 5 9

echo FINISHED at `date`
