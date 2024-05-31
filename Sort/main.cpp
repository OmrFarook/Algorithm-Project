#include <bits/stdc++.h>
using namespace std;


//********** Task 1 **********//

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}




// Bubble Sort
void bubbleSort(vector<int>& arr) {
    int n = (int)arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}



// QuickSort
void quickSort(vector<int>& arr,int low,int high) {
	if (low >= high)
		return;

	int pivot = arr[high];
	int idx = low;

	for (int i = low; i <= high;i++) {
		if (arr[i] < pivot) {
			swap(arr[i], arr[idx]);
			idx++;
		}
	}

	swap(arr[high], arr[idx]);

	quickSort(arr,low,idx-1);
	quickSort(arr, idx+1,high);

}



// Function to calculate the mean
double calculateMean(const vector<double>& times) {
    double sum = 0.0;
    for (double time : times) {
        sum += time;
    }
    return sum / times.size();
}



// Function to calculate the standard deviation
double calculateStdDev(const vector<double>& times, double mean) {
    double sum = 0.0;
    for (double time : times) {
        sum += pow(time - mean, 2);
    }
    return sqrt(sum / times.size());
}




// Benchmarking function
void benchmark(void (*sortFunction)(vector<int>&), vector<int> arr, vector<double>& times) {
    auto start = chrono::high_resolution_clock::now();
    sortFunction(arr);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    times.push_back(duration.count());
    //cout << "Time taken: " << duration.count() << " seconds" << std::endl;
}

int arrSize = 1000;

// Run benchmarks
void runBenchmarks(ofstream& outputFile,int num) {
    const int numTests = 10;


    vector<int> arr(arrSize);

    for (int i = 0; i < arrSize; ++i) {
        arr[i] = rand() % arrSize;
    }

    vector<int> arrCopy = arr;
    vector<double> BubbleSortTimes;
    vector<double> insertionSortTimes;
    vector<double> quickSortTimes;

    cout << "Benchmarking Bubble Sort #" << num << " :" << endl;
    for (int i = 0; i < numTests; ++i) {
        benchmark(bubbleSort, arr, BubbleSortTimes);
        arr = arrCopy;
    }
    double BubbleMean = calculateMean(BubbleSortTimes);
    double BubbleStdDev = calculateStdDev(BubbleSortTimes, BubbleMean);
    double BubbleMin = *min_element(BubbleSortTimes.begin(), BubbleSortTimes.end());
    double BubbleMax = *max_element(BubbleSortTimes.begin(), BubbleSortTimes.end());

    cout << "Array size : " << arrSize << "  Mean for 10 times : " << BubbleMean << "s  Standard deviation : " << BubbleStdDev << "s" << endl;
    cout << "Min time : " << BubbleMin << "s  Max time : " << BubbleMax << "s" << endl;
    outputFile << arrSize << ",BubbleSort," << BubbleMean << "," << BubbleStdDev << "," << BubbleMin << "," << BubbleMax << endl;

    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;

    cout << "Benchmarking Insertion Sort #" << num << " :" << endl;
    for (int i = 0; i < numTests; ++i) {
        benchmark(insertionSort, arr, insertionSortTimes);
        arr = arrCopy;
    }
    double insertionMean = calculateMean(insertionSortTimes);
    double insertionStdDev = calculateStdDev(insertionSortTimes, insertionMean);
    double insertionMin = *min_element(insertionSortTimes.begin(), insertionSortTimes.end());
    double insertionMax = *max_element(insertionSortTimes.begin(), insertionSortTimes.end());

    cout << "Array size : " << arrSize << "  Mean for 10 times : " << insertionMean << "s  Standard deviation : " << insertionStdDev << "s" << endl;
    cout << "Min time : " << insertionMin << "s  Max time : " << insertionMax << "s" << endl;
    outputFile << arrSize << ",InsertionSort," << insertionMean << "," << insertionStdDev << "," << insertionMin << "," << insertionMax << endl;



    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;

    cout << "Benchmarking QuickSort #" << num << " :" << endl;
    for (int i = 0; i < numTests; ++i) {
        benchmark([](vector<int>& arr) { quickSort(arr, 0, (int)arr.size() - 1); }, arr, quickSortTimes);
        arr = arrCopy;
    }
    double quickMean = calculateMean(quickSortTimes);
    double quickStdDev = calculateStdDev(quickSortTimes, quickMean);
    double quickMin = *min_element(quickSortTimes.begin(), quickSortTimes.end());
    double quickMax = *max_element(quickSortTimes.begin(), quickSortTimes.end());

    cout << "Array size : " << arrSize << "  Mean for 10 times : " << quickMean << "s  Standard deviation : " << quickStdDev << "s" << endl;
    cout << "Min time : " << quickMin << "s  Max time : " << quickMax << "s" << endl;

    outputFile << arrSize << ",QuickSort," << quickMean << "," << quickStdDev << "," << quickMin << "," << quickMax << endl;
}
///*
int main() {
    ofstream outputFile("benchmark_results.csv");
    outputFile << "ArraySize,Algorithm,Mean,StdDev,Min,Max" << endl;

    for (int i = 0; i < 35; i++) {
        cout << "---------------------------------------------------------- " << endl;
        runBenchmarks(outputFile,i);
        arrSize += 500;
        cout << "---------------------------------------------------------- " << endl;
    }

    outputFile.close();
    string filename = "Graph.py";
    string command = "python ";
    command += filename;
    system(command.c_str());
    return 0;
}
//*/




