#!/bin/bash

DATA_FILE=$1

gnuplot <<EOF
set boxwidth 0.5
set style fill solid
plot "$1" using 1:3 with lines title "Best Insertion", \
	 "$1" using 1:4 with lines title "Nearest Neighbour", \
	 "$1" using 1:5 with lines title "LKH"
pause 100
EOF