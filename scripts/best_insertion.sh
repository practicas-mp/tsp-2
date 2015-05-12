#!/bin/bash

PROGRAM_NAME="bin/best_insertion"
DATA_FILE=$1

$PROGRAM_NAME $DATA_FILE > tmp/out.tsp

gnuplot <<EOF
set size 1, 1
plot "$DATA_FILE" using 2:3 with points, "tmp/out.tsp" using 2:3 with lines
pause 10
EOF

