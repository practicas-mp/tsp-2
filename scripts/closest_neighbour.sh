#!/bin/bash

PROGRAM_NAME="bin/closest_neighbour"
DATA_FILE=$1

bin/closest_neighbour $DATA_FILE > tmp/out.tsp

gnuplot <<EOF
plot "$DATA_FILE" using 2:3 with points, "tmp/out.tsp" using 2:3 with lines
pause 100
EOF

