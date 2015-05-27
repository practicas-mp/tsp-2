#!/usr/bin/python
import sys, subprocess

PROGRAM_NAME = "bin/bb"

def get_execution_result(map_filename):
	return subprocess.check_output([PROGRAM_NAME, map_filename, "metrics"])



problem_sizes = range(10, 21)
maps = map(lambda n: "eil" + str(n) + ".tsp", problem_sizes)
maps = map(lambda m: "data/" + m, maps)

for i, map_filename in zip(problem_sizes, maps):
	print i, get_execution_result(map_filename),
