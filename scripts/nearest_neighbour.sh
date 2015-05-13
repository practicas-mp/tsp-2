#!/bin/bash

DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
PROGRAM_NAME="bin/nearest_neighbour"
DATA_FILE=$1

$DIR/visualize.sh $PROGRAM_NAME $DATA_FILE "Vecino Mas Cercano"