import os
import re

benchmarks = ['greyscale', 'compress', 'x264', 'convolution_7x7']

out_dir = "bf"
os.mkdir(out_dir)

# DSE Variables, defined here.
# Initial values set at the end of this file.
issuewidth=0
memload=0
memstore=0
mempft=0
alu=0
mpy=0
memory=0
dreg=0
breg=0

def do_bruteforce():
	# Load configuration.mm template
	in_file = open('configuration.mm.template', 'r')
	data = in_file.read()
	in_file.close()

	# Replace placeholders in template with explore variables
	data = data.replace('<issuewidth>', str(issuewidth))
	data = data.replace('<memload>', str(memload))
	data = data.replace('<memstore>', str(memstore))
	data = data.replace('<mempft>', str(mempft))
	data = data.replace('<alu>', str(alu))
	data = data.replace('<mpy>', str(mpy))
	data = data.replace('<memory>', str(memory))
	data = data.replace('<dreg>', str(dreg))
	data = data.replace('<breg>', str(breg))

	# Create directory with meaningful mame
	dir_name = str(issuewidth) + '_'
	dir_name += str(memload) + '_'
	dir_name += str(memstore) + '_'
	dir_name += str(mempft) + '_'
	dir_name += str(alu) + '_'
	dir_name += str(mpy) + '_'
	dir_name += str(memory) + '_'
	dir_name += str(dreg) + '_'
	dir_name += str(breg)

	os.chdir(out_dir)

	os.mkdir(dir_name)

	# Write configuration.mm with explore variables
	out_file = open(dir_name + "/configuration.mm", "w")
	n = out_file.write(data)
	out_file.close()

	# Cd to working directoryplt.title('compress, dynamic profile')
	os.chdir(dir_name)
	
	# Area estimation (slide 26, 27)
	# https://brightspace.tudelft.nl/d2l/le/content/280562/viewContent/1851938/View
	
	# Alu, Multipliers & Memory Load/Store units
	area = alu * 3273 + mpy * 40614 + (memory) * 1500
	# GPR area
	area += 26388/64 * dreg * (issuewidth*issuewidth) / 16
	# BR area
	area += 258/8 * breg * (issuewidth*issuewidth) / 16
	# Connections
	area += (memload+memstore+mempft)*1000
	
	with open("area", "w") as out_file:
		n = out_file.write(str(area))
		out_file.close()
		
	# Execute benchmarks
	ncycles = {}
	
	
	for b in benchmarks:
		# Run VEX compiler and simulator
		os.system("run " + b + " -O3 -H3")
		
		with open("cycles-" + b, "w") as out_file:
			with open("output-" + b + ".c/ta.log.000", "r") as in_file:
				regex = r"(?:Execution Cycles:\s*)(?P<ncycles>[0-9\-e.]*).*?"
				data = in_file.read()
				matches = re.finditer(regex, data, re.MULTILINE)
				for match in matches:
					ncycles[b] = match.group("ncycles")
				in_file.close()
				
			n = out_file.write(str(ncycles[b]))
			out_file.close()
	
	os.chdir('../')
	
	os.chdir('../')
	
	with open("bruteforce-results.txt", "a") as out_file:
		out_file.write(dir_name)
		out_file.write("\t" + str(area))
		for b in benchmarks:
			out_file.write("\t" + str(ncycles[b]))
		out_file.write("\n")
		out_file.close()

# DSE variables
issuewidth=1
memload=128
memstore=128
mempft=128
alu=128
mpy=128
memory=128
dreg=128
breg=128

for issuewidth in range(1,32+1):
	do_bruteforce()