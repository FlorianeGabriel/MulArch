#!/bin/bash
#SBATCH --workdir /home/vonfelte
#SBATCH --nodes 1
#SBATCH --ntasks 1
#SBATCH --cpus-per-task 16
#SBATCH --mem 2G

echo STARTING AT `date`

./assignment2TilesBest 1 10000 100 output.csv
./assignment2TilesBest 2 10000 100 output.csv
./assignment2TilesBest 4 10000 100 output.csv
./assignment2TilesBest 8 10000 100 output.csv
./assignment2TilesBest 16 10000 100 output.csv

echo FINISHED at `date`
