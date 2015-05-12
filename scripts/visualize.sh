#!/bin/bash

PROGRAM_NAME=$1
DATA_FILE=$2

$PROGRAM_NAME $DATA_FILE path > tmp/out.tsp

gnuplot <<EOF
set size 1, 1
plot "$DATA_FILE" using 2:3 with points, "tmp/out.tsp" using 2:3 with lines
pause 10
EOF

