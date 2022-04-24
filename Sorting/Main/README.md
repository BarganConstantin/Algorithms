## Execution time in different situations

After studying, analyzing and implementing the proposed sorting algorithms, we could reach certain conclusions regarding the efficiency of each, because each has certain advantages, but also certain disadvantages.
<br/>
If we make a comparison between MergeSort and QuickSort, we notice that MergeSort requires large memory resources, even if there are some possibilities to reduce this, the implementation in the program will be very difficult, while QuickSort performs the sorting process in the same array, without use extra space. But if QuickSort has the advantage of low memory usage, then MergeSort has its advantage in complexity which is O (n log) and which remains the same regardless of the case, while QuickSort, even if in some situations has complexity O (n log ), for the unfavorable case it constitutes O (n ^ 2).
<br/>
If we talk about Radix Sort, it can be an alternative to the classic sorting algorithms, especially in times when the dependence on a high sorting speed is in the foreground, and the time for implementation is sufficient, so we have the advantage: Execution speed, the ability to sort different types of values (words, numbers), and the disadvantage: difficult implementation and of course extra memory consumption.

### Sorted array

<p align="center">Execution time (in ms)<p/>

  |         | N = 100 |	N = 1000 | N = 10000 |	N = 100000 |	N = 1000000	| N = 10000000 |
  | :-----: | :-----: | :------: | :--------:| :---------: | :----------: | :----------: |
  | MergeSort |	0 |	0 |	0.001 |	0.024 |	0.234 |	2.683 |
  | QuickSort |	0 |	0.002 |	0.165 |	35.511 |	40+ |	40+ |
  | RadixSort |	0 |	0 |	0.001 |	0.009 |	0.113 |	1.362 |
  | Binary InsertionSort |	0 |	0 |	0 |	0.006 |	0.076 |	0.903 |
  
  <br/>
  <p align="center">Number of comparisons<p/>

  |         | N = 100 |	N = 1000 | N = 10000 |	N = 100000 |	N = 1000000	| N = 10000000 |
  | :-----: | :-----: | :------: | :--------:| :---------: | :----------: | :----------: |
  | MergeSort |	424 |	7936 |	113343 |	1413320 |	14544600 |	215046000 |
  | QuickSort |	4950 |	499500 |	49995000 |	4999950000 |	10^9+ |	10^9+ |
  | RadixSort |	624 |	10936 |	153343 |	1913320 |	20544600 |	285046000 |
  | Binary InsertionSort |	1197 |	19913 |	276960 |	3482250 |	39496000 |	508269000 |
 
 <br/>
  <p align="center">Graphic number of comparisons<p/>
  
  ![image](https://user-images.githubusercontent.com/60443226/164966837-5c67551b-ad2b-4d78-a427-810fb34072c3.png)
