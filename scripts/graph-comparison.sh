#!/bin/bash

DATA_FILE=$1

gnuplot <<EOF
set boxwidth 0.5
set style fill solid
plot "$1" using 1:3 with lines, "$1" using 1:4 with lines 
pause 10
EOF