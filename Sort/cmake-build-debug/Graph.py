import pandas as pd
import matplotlib.pyplot as plt

# Load the benchmark data
data = pd.read_csv("benchmark_results.csv")

# Separate data for Insertion Sort and QuickSort
Bubble_data = data[data["Algorithm"] == "BubbleSort"]
insertion_data = data[data["Algorithm"] == "InsertionSort"]
quick_data = data[data["Algorithm"] == "QuickSort"]

# Plot the mean runtime
plt.figure(figsize=(10, 6))
plt.plot(Bubble_data["ArraySize"], Bubble_data["Mean"], label="Bubble Sort", marker='o')
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