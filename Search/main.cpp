#include <bits/stdc++.h>
using namespace std;

//------------------------------------------------KMP Algorithm------------------------------------------------------

// Function to compute the Longest Prefix Suffix (LPS) array
void computeLPSArray(const string& pattern, vector<int>& lps) {
    int m = pattern.size();
    int length = 0;
    lps[0] = 0;  // lps[0] is always 0

    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP algorithm
vector<int> KMPSearch(const string& s, const string& pattern) {
    int n = s.size();
    int m = pattern.size();
    vector<int> out;
    vector<int> lps(m);

    // Preprocess the pattern to create the LPS array
    computeLPSArray(pattern, lps);

    int i = 0;  // index for text
    int j = 0;  // index for pattern
    while (i < n) {
        if (pattern[j] == s[i]) {
            i++;
            j++;
        }

        if (j == m) {
          //  return i - j;  // Match found at index i - j
          out.push_back(i-j);
          i++;
        } else if (i < n && pattern[j] != s[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return out;

 //   return -1;
}



//-------------------------------------------------Boyer Moore------------------------------------------------------


// Boyer Moore
vector<int> boyerMoore(const string& text, const string& pattern) {
    vector<int> foundIndices;
    vector<int> indices(256, -1);

    for (int i = 0; i < pattern.size(); i++) {
        indices[pattern[i]] = i;
    }

    for (int i = 0; i <= text.size() - pattern.size();) {
        bool found = true;
        int j = pattern.size() - 1;
        for (; j >= 0; j--) {
            if (text[i + j] != pattern[j]) {
                found = false;
                i += max(1, j - indices[text[i + j]]);
                break;
            }
        }

        if (found) {
            foundIndices.push_back(i);

            if (i + j < text.size()) {
                i += text.size() - indices[text[i + j]];
            }
            else {
                i += 1;
            }
        }
    }

    return foundIndices;
}




// Brute Force
vector<int> bruteForce(const string& s, const string& pattern){
    int n =s.size();
    int m = pattern.size();
    vector<int> out;
    for(int i = 0 ; i < n-(m-1) ; i++){
        int ctr = 0;
        for(int j = 0 ; j < m ; j++){
            if(s[i+j]==pattern[j]){
                ctr++;
            }
        }
        if(ctr==pattern.size()){
           // return i;
           out.push_back(i);
        }
    }
  //  return -1;
    return out;

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
void benchmark(vector<int>(*searchFunction)(const string&, const string&), const string& text, const string& pattern, vector<double>& times) {
    auto start = chrono::high_resolution_clock::now();
    searchFunction(text, pattern);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    times.push_back(chrono::duration_cast<std::chrono::microseconds>(duration).count());
}
string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZabsdefghijklmnopqrstuvwxyz";

// Run benchmarks
void runBenchmarks(ofstream& outputFile, int textSize, int patternSize, int num) {
    const int numTests = 10;

    // Generate random text and pattern
    string text =  "";
    string pattern = "";

    // Place a pattern at the end of the text to ensure worst-case scenario for search
    for (int i = 0; i < textSize; ++i) {
        text+=s[rand()%s.size()];
    }
    for (int i = 0; i < patternSize; ++i) {
        pattern+=s[rand()%s.size()];
    }
    text.insert(rand() % text.size(),pattern);
    text.insert(rand() % text.size(),pattern);
    text.insert(rand() % text.size(),pattern);

    vector<double> kmpTimes;
    vector<double> boyerMooreTimes;
    vector<double> bruteForceTimes;

    // Benchmark KMP
    cout << "Benchmarking KMP #" << num << " :" << endl;
    for (int i = 0; i < numTests; ++i) {
        benchmark(KMPSearch, text, pattern, kmpTimes);
    }
    double kmpMean = calculateMean(kmpTimes);
    double kmpStdDev = calculateStdDev(kmpTimes, kmpMean);
    double kmpMin = *min_element(kmpTimes.begin(), kmpTimes.end());
    double kmpMax = *max_element(kmpTimes.begin(), kmpTimes.end());

    cout << "Text size: " << textSize << ", Pattern size: " << patternSize
         << " => KMP Time: Mean=" << kmpMean << "s, StdDev=" << kmpStdDev << "s, Min=" << kmpMin << "s, Max=" << kmpMax << "s" << endl;
    outputFile << textSize << "," << patternSize << ",KMP," << kmpMean << "," << kmpStdDev << "," << kmpMin << "," << kmpMax << endl;

    // Benchmark Boyer-Moore
    cout << "Benchmarking Boyer-Moore #" << num << " :" << endl;
    for (int i = 0; i < numTests; ++i) {
        benchmark(boyerMoore, text, pattern, boyerMooreTimes);
    }
    double boyerMooreMean = calculateMean(boyerMooreTimes);
    double boyerMooreStdDev = calculateStdDev(boyerMooreTimes, boyerMooreMean);
    double boyerMooreMin = *min_element(boyerMooreTimes.begin(), boyerMooreTimes.end());
    double boyerMooreMax = *max_element(boyerMooreTimes.begin(), boyerMooreTimes.end());

    cout << "Text size: " << textSize << ", Pattern size: " << patternSize
         << " => Boyer-Moore Time: Mean=" << boyerMooreMean << "s, StdDev=" << boyerMooreStdDev << "s, Min=" << boyerMooreMin << "s, Max=" << boyerMooreMax << "s" << endl;
    outputFile << textSize << "," << patternSize << ",Boyer-Moore," << boyerMooreMean << "," << boyerMooreStdDev << "," << boyerMooreMin << "," << boyerMooreMax << endl;

    // Benchmark Brute Force
    cout << "Benchmarking Brute Force #" << num << " :" << endl;
    for (int i = 0; i < numTests; ++i) {
         benchmark(bruteForce, text, pattern, bruteForceTimes);
    }
    double bruteForceMean = calculateMean(bruteForceTimes);
    double bruteForceStdDev = calculateStdDev(bruteForceTimes, bruteForceMean);
    double bruteForceMin = *min_element(bruteForceTimes.begin(), bruteForceTimes.end());
    double bruteForceMax = *max_element(bruteForceTimes.begin(), bruteForceTimes.end());

    cout << "Text size: " << textSize << ", Pattern size: " << patternSize
         << " => Brute Force Time: Mean=" << bruteForceMean << "s, StdDev=" << bruteForceStdDev << "s, Min=" << bruteForceMin << "s, Max=" << bruteForceMax << "s" << endl;
    outputFile << textSize << "," << patternSize << ",BruteForce," << bruteForceMean << "," << bruteForceStdDev << "," << bruteForceMin << "," << bruteForceMax << "s" << endl;
}

int main() {
    ofstream outputFile("search_benchmark_results.csv");
    outputFile << "TextSize,PatternSize,Algorithm,Mean,StdDev,Min,Max" << endl;

    int textSize = 1000;
    int patternSize = 10;

int num = 1;
    for (int i = 0; i < 16; i++) {
        textSize += 50;
        for(int j = 0 ; j < i*2 ; j++){


        cout << "---------------------------------------------------------- " << endl;
        runBenchmarks(outputFile, textSize, patternSize, num);
        patternSize += 5;
        cout << "---------------------------------------------------------- " << endl;
        num++;
        }
        }

    outputFile.close();

    std::string filename = "Graph.py";
    std::string command = "python ";
    command += filename;
    system(command.c_str());
    return 0;
}

