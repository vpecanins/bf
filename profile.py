import os
import re
import numpy as np
import matplotlib.pyplot as plt


# Benchmark file to read is dyn_prof_file_<bm>.txt
#bm = "greyscale"
bm = "compress"

# The top N instructions have an individual bar in the graph
# The rest of instructions are merged into a single bin "Other"
N = 20

my_dict = {}

opcodes = {"alu": ["ADD", "ADDCG", "AND", "ANDC", "ANDL",
                   "CMPEQ","CMPGE","CMPGEU","CMPGT","CMPGTU",
                   "CMPLE","CMPLEU","CMPLT","CMPLTU","CMPNE",
                   "MAX","MAXU","MIN","MINU","MOV",
                   "NANDL","NORL","OR","ORC","ORL","SBIT","SBITF",
                   "SH1ADD","SH2ADD","SH3ADD","SH4ADD","SHL","SHR","SHRU",
                   "SXTB","SXTH","ZXTB","ZXTH","XOR","SUB"
                   ],
           "branch": ["BR","BRF","CALL","GOTO","ICALL","IGOTO","RETURN",
                      "SLCT","SLCTF"],
           "mul/div": ["MPYH","MPYHH","MPYHHU","MPYHS","MPYHU",
                      "MPYL","MPYLH","MPYLHU","MPYLL","MPYLLU",
                      "MPYLU","DIVS",
                      "MUL","MULH","MULHS","MULHU","MULL","MULLH","MULLHHU",
                      "MULLHU","MULLL","MULLLU","MULLU"],
           "memory":["LDB","LDBU","LDBUs","LDH","LDHU","LDHUs","LDHs","LDW","LDWs",
                  "STB","STH","STW","PFT"],
           "misc": ["MFB","MFL","MTB","MTBINV","MTL","NOP","XNOP","TBIT","TBITF"]
           }

opcode_colors = {
    "alu": "tab:blue",
    "branch": "tab:orange",
    "mul/div": "tab:green",
    "memory": "tab:red",
    "misc": "black"
    }

def get_opcode_color(op):
    for key in opcodes:
        for opcode in opcodes[key]:
            if (opcode == op):
                return opcode_colors[key]

total_instr = 0

# Load dyn_prof_file.txt
with open('dyn_prof_file_'+bm+'.txt', 'r') as in_file:
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

for i in range (0,N):
    bar_y.append(ops_sorted[i][1])
    bar_x.append(i)
    bar_labels.append(ops_sorted[i][0])
    
# Merge rest
rest = 0

for i in range (N, len(ops_sorted)):
    rest += ops_sorted[i][1]
    
bar_y.append(rest)
bar_x.append(N)
bar_labels.append("Other")

# Setup matplotlib to generate Latex output
plt.rc('text', usetex=True)
plt.style.use('seaborn-whitegrid')

# Set text size
font = {'weight' : 'bold',
        'size'   : 16}
plt.rc('font', **font)
    
fig, ax = plt.subplots(1,1)
    
width = 0.5
p1 = plt.bar(bar_x, bar_y, width)

for i in range (0,N):
    p1[i].set_color(get_opcode_color(ops_sorted[i][0]))

p1[-1].set_color("grey")

plt.ylabel('Count')
plt.xlabel('Opcode')
plt.title(bm + ', dynamic profile')
plt.xticks(bar_x, bar_labels, rotation=90)

# legend is tricky

from matplotlib.lines import Line2D
custom_lines = []

for c in opcode_colors.keys():
    custom_lines.append(Line2D([0], [0], color=opcode_colors[c], lw=4))

plt.legend(custom_lines,opcodes.keys())

plt.show()
# Save plot
fig.savefig("profile_"+bm+".pdf", bbox_inches='tight')
