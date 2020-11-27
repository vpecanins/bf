import os
import re

# Explore variables
issuewidth=8
memload=4
memstore=4
mempft=2
alu=8
mpy=1
memory=4
dreg=64
breg=8

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

	os.mkdir(dir_name)

	# Write configuration.mm with explore variables
	out_file = open(dir_name + "/configuration.mm", "w")
	n = out_file.write(data)
	out_file.close()

	# Cd to working directory
	os.chdir(dir_name)

	# Execute benchmarks
	os.system("run greyscale -O3")
	os.system("run compress -O3")

	# Remove unused files to save disk space
	os.remove("output-greyscale.c/a.out")
	os.remove("output-greyscale.c/greyscale.cs.c")
	os.remove("output-greyscale.c/greyscale.c")
	os.remove("output-greyscale.c/greyscale.s")
	os.remove("output-greyscale.c/gmon-dcache.out")
	os.remove("output-greyscale.c/gmon-icache.out")
	os.remove("output-greyscale.c/gmon-nocache.out")
	os.remove("output-greyscale.c/gmon.out")
	os.remove("output-compress.c/a.out")
	os.remove("output-compress.c/compress.cs.c")
	os.remove("output-compress.c/compress.c")
	os.remove("output-compress.c/compress.s")
	os.remove("output-compress.c/gmon-dcache.out")
	os.remove("output-compress.c/gmon-icache.out")
	os.remove("output-compress.c/gmon-nocache.out")
	os.remove("output-compress.c/gmon.out")
	
	# Extract cycles
	
	# Calculate area estimation (slide 26)
	area = alu * 3273 + mpy * 40614 + (memory) * 1500
	area += dreg * 243788/64 + breg * 258/8 + (memload+memstore)*1000
	
	with open("area", "w") as out_file:
		n = out_file.write(str(area))
		out_file.close()
		
	ncycles_greyscale=0
	ncycles_compress=0
	
	with open("cycles-greyscale", "w") as out_file:
		with open("output-greyscale.c/ta.log.000", "r") as in_file:
			regex = r"(?:Execution Cycles:\s*)(?P<ncycles>[0-9\-e.]*).*?"
			data = in_file.read()
			matches = re.finditer(regex, data, re.MULTILINE)
			for match in matches:
				ncycles_greyscale = match.group("ncycles")
			in_file.close()
			
		n = out_file.write(str(ncycles_greyscale))
		out_file.close()
		
	with open("cycles-compress", "w") as out_file:
		with open("output-compress.c/ta.log.000", "r") as in_file:
			regex = r"(?:Execution Cycles:\s*)(?P<ncycles>[0-9\-e.]*).*?"
			data = in_file.read()
			matches = re.finditer(regex, data, re.MULTILINE)
			for match in matches:
				ncycles_compress = match.group("ncycles")
			in_file.close()
			
		n = out_file.write(str(ncycles_compress))
		out_file.close()

	os.chdir('../')
	
	with open("bruteforce-results.txt", "a") as out_file:
		out_file.write(dir_name)
		out_file.write("\t" + str(area))
		out_file.write("\t" + str(ncycles_greyscale))
		out_file.write("\t" + str(ncycles_compress) + "\n")
		out_file.close()

# Sweep variables as needed
for dreg in [32, 64, 96]:
	for breg in [8, 16]:
		do_bruteforce()