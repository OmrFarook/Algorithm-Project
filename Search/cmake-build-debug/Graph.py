import pandas as pd
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# Load the benchmark data
data = pd.read_csv("search_benchmark_results.csv")

# Plotting the mean runtime
fig = plt.figure(figsize=(12, 8))
ax = fig.add_subplot(111, projection='3d')

# Scatter plot for each algorithm
algorithms = data['Algorithm'].unique()
markers = ['o', '^', 's']

for algorithm, marker in zip(algorithms, markers):
    algo_data = data[data['Algorithm'] == algorithm]
    ax.scatter(algo_data['TextSize'], algo_data['PatternSize'], algo_data['Mean'], label=algorithm, marker=marker)

# Adding titles and labels
ax.set_title("Search Algorithm Benchmark")
ax.set_xlabel("Text Size")
ax.set_ylabel("Pattern Size")
ax.set_zlabel("Mean Runtime (microseconds)")
ax.legend()

plt.savefig("search_benchmark_mean_runtime_3d.png")
plt.show()