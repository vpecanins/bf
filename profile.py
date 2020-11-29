import os
import re
import numpy as np
import matplotlib.pyplot as plt

# my_dict["opcode"] = <count>
my_dict = {}

total_instr = 0

# Load dyn_prof_file.txt
with open('dyn_prof_file_greyscale.txt', 'r') as in_file:
    regex = r"(?:operation:\s*)(?P<opcode>[A-Z01-9a-z]*)(?:\s*n\. times:\s*)(?P<nops>[01-9]*).*?"
    data = in_file.read()
    matches = re.finditer(regex, data, re.MULTILINE)
    for match in matches:
	    opcode = match.group("opcode")
	    nops = int(match.group("nops"))
	    total_instr += nops
	    if (nops > 0):
	        print(opcode + ": " + str(nops))
	    my_dict[opcode] = nops
    in_file.close()



# Sort my_dict by n.ops
ops_sorted = (sorted(my_dict.items(), key=lambda item: -item[1]))

# Prepare graph
bar_y = []
bar_x = []
bar_labels = []
width = 0.5
N = 10

for i in range (0,N):
    bar_y.append(ops_sorted[i][1])
    bar_x.append(i)
    bar_labels.append(ops_sorted[i][0])
    
# Merge rest
rest = 0

for i in range (N, len(ops_sorted)):
    rest += ops_sorted[i][1]
    
# Setup matplotlib to generate Latex output
plt.rc('text', usetex=True)
plt.style.use('seaborn-whitegrid')

# Set text size
font = {'weight' : 'bold',
        'size'   : 16}
plt.rc('font', **font)
    
fig, ax = plt.subplots(1,1)

bar_y.append(rest)
bar_x.append(N)
bar_labels.append("Other")
    
p1 = plt.bar(bar_x, bar_y, width)

p1[len(p1)-1].set_color('grey')

plt.ylabel('Count')
plt.xlabel('Opcode')
plt.title('greyscale, dynamic profile')
#plt.title('compress, dynamic profile')
plt.xticks(bar_x, bar_labels, rotation=90)

plt.show()
# Save plot
fig.savefig("profile_greyscale.pdf", bbox_inches='tight')
#fig.savefig("profile_compress.pdf", bbox_inches='tight')
