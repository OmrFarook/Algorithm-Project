
<a name="_page1_x39.00_y730.00"></a>**Introduction** 

This report investigates the differences between the measured runtime and the theoretical O notation of several algorithms, namely the Knuth-Morris-Pratt (KMP), Boyer-Moore, Brute Force search algorithms, and Insertion Sort, Bubble Sort, and QuickSort sorting algorithms. The theoretical complexities of these algorithms are well- documented in literature, and this study aims to compare these complexities with empirical data obtained through benchmarking. 

<a name="_page2_x29.00_y184.00"></a>**Theoretical Complexities** 

<a name="_page2_x29.00_y207.00"></a>Search Algorithms 

1. **Knuth-Morris-Pratt (KMP) Algorithm**: 
- **Theoretical Complexity**: O(n + m) 
- **Explanation**: The KMP algorithm preprocesses the pattern in O(m) time to create the Longest Prefix Suffix (LPS) array. The actual search phase then takes O(n) time, resulting in a total time complexity of O(n + m), where n is the length of the text and m is the length of the pattern. 
2. **Boyer-Moore Algorithm**: 
- **Theoretical Complexity**: O(n) 
- **Explanation**: The Boyer-Moore algorithm preprocesses the pattern to create bad character and good suffix tables, which takes O(m) time. The actual searching phase can vary between O(n/m) in the best case and O(nm) in the worst case, but it is generally considered O(n) for practical purposes. 
3. **Brute Force Algorithm**: 
- **Theoretical Complexity**: O(nm) 
- **Explanation**: The brute force approach compares the pattern to the text at every possible position, resulting in a worst-case complexity of O(nm). 

<a name="_page2_x29.00_y472.00"></a>Sorting Algorithms 

1. **Insertion Sort**: 
- **Theoretical Complexity**: O(n^2) 
- **Explanation**: Insertion Sort involves inserting each element into its correct position, leading to O(n^2) comparisons and swaps in the worst case. However, it performs better on nearly sorted data. 
2. **Bubble Sort**: 
- **Theoretical Complexity**: O(n^2) 
- **Explanation**: Bubble Sort repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. This results in O(n^2) comparisons and swaps in the worst case. 
3. **Quick Sort**: 
- **Theoretical Complexity**: O(n log n) on average, O(n^2) in the worst case 
- **Explanation**: QuickSort is a divide-and-conquer algorithm that works by selecting a pivot and partitioning the array into subarrays. The average case complexity is O(n log n), but it can degrade to O(n^2) if the pivot selection is poor (e.g., already sorted arrays). 

<a name="_page3_x29.00_y59.00"></a>**Empirical Analysis** 

To investigate the empirical performance, we benchmarked these algorithms with varying input sizes. The benchmarks were run 10 times for each input size to ensure statistical significance. The mean, standard deviation, minimum, and maximum runtimes were recorded. 

<a name="_page3_x29.00_y152.00"></a>Search Algorithms 

The empirical data for the search algorithms are shown below: 



|**TextSize** |**PatternSize** |**Algorithm** |**Mean** |**StdDev** |**Min** |**Max** |
| - | - | - | - | - | - | - |
|**1100** |10 |KMP |34\.5 |7\.10282 |28 |54 |
|**1100** |10 |Boyer-Moore |2\.7 |2\.1 |2 |9 |
|**1100** |10 |BruteForce |52\.6 |3\.92938 |49 |60s |
|**1100** |15 |KMP |30\.7 |10\.3252 |18 |54 |
|**1100** |15 |Boyer-Moore |2\.4 |1\.2 |2 |6 |
|**1100** |15 |BruteForce |80\.5 |17\.1887 |71 |130s |
|**1150** |20 |KMP |46\.4 |9\.23255 |37 |62 |
|**1150** |20 |Boyer-Moore |2 |2\.36643 |1 |9 |
|**1150** |20 |BruteForce |107\.4 |6\.13514 |102 |123s |
|**1150** |25 |KMP |43\.5 |17\.3393 |29 |85 |
|**1150** |25 |Boyer-Moore |2\.5 |1\.5 |2 |7 |
|**1150** |25 |BruteForce |150\.3 |51\.1411 |87 |261s |
|**1150** |30 |KMP |46\.5 |23\.517 |34 |116 |
|**1150** |30 |Boyer-Moore |2\.5 |1\.5 |2 |7 |

![Aspose Words b8fb5fd6-8c3f-447e-bbd8-e463b6b25586 014](https://github.com/OmrFarook/Algorithm-Project/assets/100935109/65ffd0d0-1d9b-462b-ba2a-c7b0a42f7d00)


<a name="_page5_x29.00_y33.00"></a>Sorting Algorithms 

The empirical data for the sorting algorithms are shown below: 



|**ArraySize** |**Algorithm** |**Mean** |**StdDev** |**Min** |**Max** |
| - | - | - | - | - | - |
|**1000** |BubbleSort |0\.00377625 |0\.000598933 |0\.0031073 |0\.0049927 |
|**1000** |InsertionSort |0\.00137782 |0\.000163116 |0\.001166 |0\.0016906 |
|**1000** |QuickSort |0\.00012775 |5\.62E-05 |8\.67E-05 |0\.0002738 |
|**1500** |BubbleSort |0\.00763473 |0\.00109357 |0\.0068664 |0\.0101014 |
|**1500** |InsertionSort |0\.00272514 |0\.000200307 |0\.0023216 |0\.0030485 |
|**1500** |QuickSort |0\.00018571 |4\.67E-05 |0\.0001599 |0\.0003167 |
|**2000** |BubbleSort |0\.0129817 |0\.000692616 |0\.0123898 |0\.0148114 |
|**2000** |InsertionSort |0\.00442683 |0\.000644618 |0\.0035719 |0\.0055309 |
|**2000** |QuickSort |0\.00021119 |4\.02E-05 |0\.000188 |0\.000325 |
|**2500** |BubbleSort |0\.0206478 |0\.000794271 |0\.0197393 |0\.0223386 |
|**2500** |InsertionSort |0\.00761913 |0\.000614745 |0\.0064341 |0\.0091208 |
|**2500** |QuickSort |0\.00030811 |2\.25E-05 |0\.0002792 |0\.0003611 |
|**3000** |BubbleSort |0\.0312018 |0\.00175111 |0\.0291018 |0\.0342142 |
|**3000** |InsertionSort |0\.0110833 |0\.000831565 |0\.0088696 |0\.0118391 |
|**3500** |BubbleSort |0\.0404162 |0\.000978313 |0\.0395484 |0\.0427717 |
|**3500** |InsertionSort |0\.0139115 |0\.00116919 |0\.0107862 |0\.0157416 |
|**3500** |QuickSort |0\.00042877 |4\.56E-05 |0\.0004046 |0\.0005513 |
|**4000** |BubbleSort |0\.0530134 |0\.00068292 |0\.052156 |0\.0541428 |
|**4000** |InsertionSort |0\.0180491 |0\.00243963 |0\.014309 |0\.0231537 |
|**4000** |QuickSort |0\.00042022 |2\.38E-05 |0\.0003956 |0\.0004573 |
|**4500** |BubbleSort |0\.0695414 |0\.00122415 |0\.0680274 |0\.0718354 |

![Aspose Words b8fb5fd6-8c3f-447e-bbd8-e463b6b25586 015](https://github.com/OmrFarook/Algorithm-Project/assets/100935109/44e85998-7bbd-4d7c-b37a-6a59688bb83f)


<a name="_page6_x29.00_y396.00"></a>**Graphical Comparison** 

The runtime data was plotted to visualize the performance of each algorithm. The following graphs illustrate the 

results: <a name="_page6_x29.00_y475.00"></a>2D Graph 

- **Sorting Algorithms**: 
- **Insertion Sort, Bubble Sort, and QuickSort**: A plot of array size vs. runtime. QuickSort consistently shows superior performance compared to the other two algorithms, with both Bubble Sort and Insertion Sort demonstrating quadratic growth in runtime. 

<a name="_page6_x29.00_y571.00"></a>3D Graph 

- **Search Algorithms**: 
- **KMP, Boyer-Moore, and Brute Force**: A 3D plot of text size, pattern size, and runtime. This graph demonstrates the increasing gap in performance between the linearithmic algorithms (KMP and Boyer- Moore) and the quadratic Brute Force algorithm. 

<a name="_page7_x29.00_y33.00"></a>**Influence of Pre-sorted Data** 

The influence of pre-sorted data on the performance of the sorting algorithms was also investigated. It was observed that: 

- **Insertion Sort**: Showed a significant decrease in runtime with nearly sorted data, performing almost linearly (O(n)) as the number of required shifts decreases drastically. 
- **Bubble Sort**: Benefited from pre-sorted data due to early termination when no swaps are made in a pass. 
- **QuickSort**: Showed little to no improvement with pre-sorted data unless using a median-of-three pivot strategy to avoid worst-case performance on already sorted arrays. 

<a name="_page7_x29.00_y215.00"></a>**Conclusion** 

The empirical results align with the theoretical expectations: 

- **KMP and Boyer-Moore**: Outperform Brute Force due to their linearithmic complexity, confirming O(n + m) and O(n) performance, respectively. 
- **Insertion Sort and Bubble Sort**: Demonstrate quadratic growth in runtime, confirming their O(n^2) complexity. 
- **QuickSort**: Shows superior performance with O(n log n) on average, validating its efficiency compared to other sorting algorithms. 

The graphical and tabular comparisons provide a clear visualization of these differences, and the additional investigation into pre-sorted data effects further highlights the practical considerations of algorithm choice in real-world applications. This study reinforces the importance of understanding both theoretical and empirical performance to make informed decisions in algorithm selection. 
