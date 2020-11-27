import numpy as np
import matplotlib.pyplot as plt
import sys

# Setup matplotlib to generate Latex output
plt.rc('text', usetex=True)
plt.style.use('seaborn-whitegrid')

# Set text size
font = {'weight' : 'bold',
        'size'   : 20}
plt.rc('font', **font)

# Load data files
data_lines = open("bruteforce-results.txt", 'r').readlines()
#data_lines.pop(0)
num_cols = data_lines[1].count('\t')

area = np.genfromtxt(data_lines, delimiter="\t", usecols=1, dtype=np.uint)
points_t1 = np.genfromtxt(data_lines, delimiter="\t", usecols=2, dtype=np.uint) # greyscale
points_t2 = np.genfromtxt(data_lines, delimiter="\t", usecols=3, dtype=np.uint) # compress

fig, ax = plt.subplots()

ax.set(xlabel='Area', ylabel='Execute cycles')

plt.plot(area, points_t1, 'o', color='black')

plt.show()

# Save plot
fig.savefig("pareto.pdf", bbox_inches='tight')

