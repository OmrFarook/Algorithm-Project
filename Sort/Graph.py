import pandas as pd
import matplotlib.pyplot as plt

# Load the benchmark data
data = pd.read_csv("cmake-build-debug/benchmark_results.csv")

# Separate data for Insertion Sort and QuickSort
insertion_data = data[data["Algorithm"] == "InsertionSort"]
quick_data = data[data["Algorithm"] == "QuickSort"]

# Plot the mean runtime
plt.figure(figsize=(10, 6))
plt.plot(insertion_data["ArraySize"], insertion_data["Mean"], label="Insertion Sort", marker='o')
plt.plot(quick_data["ArraySize"], quick_data["Mean"], label="Quick Sort", marker='o')

# Adding titles and labels
plt.title("Sorting Algorithm Benchmark")
plt.xlabel("Array Size")
plt.ylabel("Mean Runtime (seconds)")
plt.legend()
plt.grid(True)
plt.savefig("sorting_benchmark_mean_runtime.png")
plt.show()