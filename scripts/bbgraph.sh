#!/bin/bash

DATA_FILE=$1

gnuplot <<EOF
set term png
set output 'results/bbnodes.png'
set xlabel "Problem size"
set ylabel "Nodes explored"

plot "results/bbresults.txt" using 1:2 with lines title "Nodes explored"
EOF

gnuplot <<EOF
set term png
set output 'results/bbqueuesize.png'
set xlabel "Problem size"
set ylabel "Max queue size"

plot "results/bbresults.txt" using 1:3 with lines title "Max Queue Size"
EOF

gnuplot <<EOF
set term png
set output 'results/bbcompletepaths.png'
set xlabel "Problem size"
set ylabel "Complete paths explored"

plot "results/bbresults.txt" using 1:5 with lines title "Complete paths"
EOF

gnuplot <<EOF
set term png
set output 'results/bbtime.png'
set xlabel "Problem size"
set ylabel "Execution time (ms)"

plot "results/bbresults.txt" using 1:6 with lines title "Time"
EOF