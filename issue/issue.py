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

points_t1_norm = np.zeros(len(points_t1))
points_t2_norm = np.zeros(len(points_t2))

for i in range(0, len(points_t1)):
    points_t1_norm[i] = float(points_t1[0]) / float(points_t1[i])
    points_t2_norm[i] = float(points_t2[0]) / float(points_t2[i])

fig, ax = plt.subplots(1,1)

ax.set_title("Speedup vs Issue width")

ax.set(xlabel='Issue width', ylabel='Speedup')

line1, = ax.plot(range(1,len(points_t1)+1), points_t1_norm, 'x-', color='blue')
line2, = ax.plot(range(1,len(points_t1)+1), points_t2_norm, 'x-', color='orange')
plt.xlim((0,len(points_t1)+1))

line1.set_label("greyscale")
line2.set_label("compress")
ax.legend()

fig.tight_layout(pad=0.5)

plt.show()

# Save plot
fig.savefig("issue.pdf", bbox_inches='tight')

