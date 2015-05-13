#!/bin/bash

DATA_FILE=$1

gnuplot <<EOF
set term png
set output 'results/algorithm-comparison.png'

plot "$1" using 1:3 with lines title "Best Insertion", \
	 "$1" using 1:4 with lines title "Nearest Neighbour", \
	 "$1" using 1:5 with lines title "LKH"
EOF