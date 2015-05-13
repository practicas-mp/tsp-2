#!/bin/bash

PROGRAM_NAME=$1
DATA_FILE=$2
TITLE=$3

$PROGRAM_NAME $DATA_FILE path > tmp/out.tsp


gnuplot <<EOF
set term png
set output "results/$TITLE.png"
set title "$TITLE"
plot "$DATA_FILE" using 2:3 with points title "Ciudades", \
	 "tmp/out.tsp" using 2:3 with lines title "Recorrido"

EOF

