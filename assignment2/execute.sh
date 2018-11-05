#!/bin/bash
#SBATCH --workdir /home/vonfelte
#SBATCH --nodes 1
#SBATCH --ntasks 1
#SBATCH --cpus-per-task 16
#SBATCH --mem 2G

echo STARTING AT `date`

./assignment2Tiles1 1 10000 100 output.csv
./assignment2Tiles1 2 10000 100 output.csv
./assignment2Tiles1 4 10000 100 output.csv
./assignment2Tiles1 8 10000 100 output.csv
./assignment2Tiles1 16 10000 100 output.csv



echo FINISHED at `date`
