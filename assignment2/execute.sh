#!/bin/bash
#SBATCH --workdir /home/fgabriel
#SBATCH --nodes 1
#SBATCH --ntasks 1
#SBATCH --cpus-per-task 16
#SBATCH --mem 2G

echo STARTING AT `date`

./assignment2 1 10000 100 output.csv
./assignment2 2 10000 100 output.csv
./assignment2 4 10000 100 output.csv
./assignment2 8 10000 100 output.csv
./assignment2 16 10000 100 output.csv

./assignment2FirstTry 1 10000 100 output.csv
./assignment2FirstTry 2 10000 100 output.csv
./assignment2FirstTry 4 10000 100 output.csv
./assignment2FirstTry 8 10000 100 output.csv

./assignment2FirstTryNoIF 1 10000 100 output.csv
./assignment2FirstTryNoIF 2 10000 100 output.csv
./assignment2FirstTryNoIF 4 10000 100 output.csv
./assignment2FirstTryNoIF 8 10000 100 output.csv

./assignment2Tiles1 1 10000 100 output.csv
./assignment2Tiles1 2 10000 100 output.csv
./assignment2Tiles1 4 10000 100 output.csv
./assignment2Tiles1 8 10000 100 output.csv

./assignment2TilesBest 1 10000 100 output.csv
./assignment2TilesBest 2 10000 100 output.csv
./assignment2TilesBest 4 10000 100 output.csv
./assignment2TilesBest 8 10000 100 output.csv


echo FINISHED at `date`
