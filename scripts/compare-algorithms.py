#!/usr/bin/python
import subprocess, sys, os

def get_command_output(*command):
	return subprocess.check_output(command)

def get_optimum_cost(map_file_name):
	program_name = "./bin/optimum-cost"
	return float(get_command_output(program_name, map_file_name))

def get_cost_in(map_file_name, bin):
	return float(get_command_output(bin, map_file_name, "cost"))

def compare(binaries, data_files):
	for data_file in data_files:
		data_file = "./data/" + data_file
		optimum_cost = get_optimum_cost(data_file[:-4])
		print data_file, 
		
		for binary in binaries:
			print get_cost_in(data_file, binary)/optimum_cost,

		print 


algorithms = ["best_insertion", "nearest_neighbour"]
maps = filter(lambda filename: len(filename) > 4 and filename[-4:] == ".tsp", os.listdir("./data"))
maps.sort()
binaries = map(lambda p: "bin/" + p, algorithms)

compare(binaries, maps)

