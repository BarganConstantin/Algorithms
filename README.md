Table of Contents
=================
* [Sorting Algorithms](#Sorting-Algorithms)
	* [Quicksort](#Sorting-by-Quicksort-algorithm)
		* [Implementation of Quicksort](#Implementation-of-Quicksort)
	* [MergeSort](#Sorting-by-MergeSort-algorithm)
		* [Implementation of MergeSort](#Implementation-of-MergeSort)
	* [RadixSort](#Sorting-by-RadixSort-algorithm)
		* [Implementation of Radix Sort](#Implementation-of-Radix-Sort)
	* [Binary InseritonSort](#Sorting-by-Binary-InseritonSort-algorithm)
		* [Implementation of Binary InseritonSort](#Implementation-of-Binary-InseritonSort)


# Sorting Algorithms

## Sorting by Quicksort algorithm
&nbsp;&nbsp;&nbsp;&nbsp;Quicksort is a sorting algorithm based on a divide et impera strategy. This divides the sorting list into two easier-to-sort sublists. The steps of the algorithm are:

1. Choose an item from the list, called a pivot
2. Rearrange the list so that all items smaller than the pivot are placed before the pivot and all items larger than the pivot are placed after the pivot. After this partitioning, the pivot is in its final position.
3. Recursively sort the sublist of items smaller than the pivot and the sublist of items larger than the pivot.

<div align="center">
  <kbd>
    <img src="https://user-images.githubusercontent.com/60443226/164789300-3baadc80-ca39-4ab5-aa2a-948698588686.png" alt="MarineGEO circle logo"/>
  </kbd>
</div>
<br/>
&nbsp;&nbsp;&nbsp;&nbsp;In general, there are several versions of quickSort depending on the choice of pivot:
- Pivot is always chosen first element 
- Pivot is always chosen last element 
- Pivot is chosen randomly  
- Pivot is median
<br/>
<br/>
&nbsp;&nbsp;&nbsp;&nbsp;The key process in QuickSort is performed by the partition function, which always arranges all the smaller elements like the pivot before it and all the larger elements after it, and the respective action is performed in a linear time.
<br/> 
<br/>

### Implementation of Quicksort

```cpp
void quick_sort(int *Arr, int start, int end)
{
	int piv_index;
	if (start < end)
	{
		piv_index = partition(Arr, start, end);
		quick_sort(Arr, start, piv_index - 1);
		quick_sort(Arr, piv_index + 1, end);
	}
}

int partition(int *Arr, int start, int end)
{
	int pivot = Arr[end];
	int part_index = start;
	for (int i = start; i <= end - 1; i++)
	{
		if (Arr[i] <= pivot)
		{
			int tmp = Arr[i];
			Arr[i] = Arr[part_index];
			Arr[part_index] = tmp;

			part_index++;
		}
	}
	int tmp = Arr[end];
	Arr[end] = Arr[part_index];
	Arr[part_index] = tmp;

	return part_index;
}

```
<br/>

## Sorting by MergeSort algorithm
&nbsp;&nbsp;&nbsp;&nbsp;The MergeSort algorithm involves the use of interclassing in the solution assembly stage: following the recursive solution of the subproblems obtained by applying the “Divide et Impera” programming technique, ordered lists result and by interclassing them we obtain the initial sorted list.
<br/>
<br/>
&nbsp;&nbsp;&nbsp;&nbsp;The sorting algorithm involves three steps:
1. the string is divided up to half into two strings of equal lengths (or which differ by at most one unit), then by recursion, with the obtained strings the same procedure is done, until the strings have a length of 1 or at most 2 elements;
2. the two substrings corresponding to the last recursive call are sorted;
3. the sorted substrings are interclassed, by returning from recursion, the whole sorted initial vector is gradually reconstructed;
<br/>
<div align="center">
  <kbd>
    <img src="https://user-images.githubusercontent.com/60443226/164793108-350ff78f-5fd6-4526-9ccf-5a8589109fea.png" alt="MarineGEO circle logo"/>
  </kbd>
</div>
<br/>
&nbsp;&nbsp;&nbsp;&nbsp;The problem of interclassing two sorted vectors a and b is solved as follows:
<br/>

- an intermediate vector c is used;
- compare the element from the first position in the first vector with the element from the first position in the second vector; if the element of the first vector is smaller, it is copied to the vector c, then the scroll index is increased so that at the next comparison it indicates the second element; if the element in b is smaller, it will be copied to c, and the scroll index of b will be incremented to select the second element in b;
- by successive comparisons, the ordered vector c is constructed, until the elements from a or b are finished; the remaining items in b, or a, as the case may be, shall be copied in order to c; 

### Implementation of MergeSort

```cpp
void merge_sort(int *Arr, int start, int end)
{
	if (start >= end) return;

	int center = start + (end - start) / 2;

	merge_sort(Arr, start, center);
	merge_sort(Arr, center + 1, end);
	merge(Arr, start, center, end);
}

void merge(int *Arr, int left, int center, int right)
{
	int n_arr_1 = center - left + 1;
	int n_arr_2 = right - center;

	int *tmpArr1 = new int[n_arr_1];
	int *tmpArr2 = new int[n_arr_2];

	for (int i = 0; i < n_arr_1; i++)
	{
		tmpArr1[i] = Arr[left + i];
	}

	for (int i = 0; i < n_arr_2; i++)
	{
		tmpArr2[i] = Arr[center + 1 + i];
	}

	int indexTmpArr1 = 0;
	int indexTmpArr2 = 0;
	int indexArr = left;

	while (indexTmpArr1 < n_arr_1 && indexTmpArr2 < n_arr_2)
	{
		if (tmpArr1[indexTmpArr1] <= tmpArr2[indexTmpArr2])
		{
			Arr[indexArr] = tmpArr1[indexTmpArr1];
			indexTmpArr1++;
		}
		else
		{
			Arr[indexArr] = tmpArr2[indexTmpArr2];
			indexTmpArr2++;
		}
		indexArr++;
	}

	while (indexTmpArr1 < n_arr_1)
	{
		Arr[indexArr] = tmpArr1[indexTmpArr1];
		indexArr++;
		indexTmpArr1++;
	}

	while (indexTmpArr2 < n_arr_1)
	{
		Arr[indexArr] = tmpArr2[indexTmpArr2];
		indexArr++;
		indexTmpArr2++;
	}
	delete[] tmpArr1;
	delete[] tmpArr2;
}
```

<br/>

## Sorting by RadixSort algorithm
&nbsp;&nbsp;&nbsp;&nbsp;Radix Sort is one of the fastest sorting methods. It is based on sorting by the most insignificant "digit":
- Radix Sort is not based on a comparison technique. Each element in the vector (or attribute of an element, in the case of structures) after which we sort will be called the key.
- Keys are thought of as strings of "characters" (where a "character" can be a bit, a number, a letter,…).

<br/>

&nbsp;&nbsp;&nbsp;&nbsp;The algorithm goes through the following steps:
1. starting from the position of the most insignificant "character", we count how many times each "character" appears on that position, then we divide an auxiliary vector into sections (imaginary). The number of sections is the number of different "characters" that can exist in the vector, ie each section is associated with a "character", the size of a section depends on the number of occurrences of the associated "character";
2. put each element (in the auxiliary vector) in the corresponding section, then copy the auxiliary vector back to the vector to be sorted. A sorted vector is obtained to the current position;
3. we move on to the next position and repeat the steps, the last position being that of the most significant "character".

<br/>
<div align="center">
  <kbd>
    <img src="https://user-images.githubusercontent.com/60443226/164964858-53a7fb3c-0eb0-477b-8f64-d3f8115e776d.png" alt="MarineGEO circle logo"/>
  </kbd>
</div>

<br/>

### Implementation of Radix Sort

```cpp

int getMax(int *A, int n)
{
	int max = A[0];
	for (int i = 0; i < n; i++)
	{
		if (A[i] > max)
			max = A[i];
	}
	return max;
}

void radixsort(int *A, int n)
{
	int m = getMax(A, n);

	for (int i = 1; m / i > 0; i = i * 10)
	{
		countSort(A, n, i);
	}
}

void countSort(int *A, int n, int exp)
{
	int* result = new int[n];
	int count[10] = { 0 };

	for (int i = 0; i < n; i++)
	{
		count[(A[i] / exp) % 10]++;
	}

	for (int i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];
	}

	for (int i = n - 1; i >= 0; i--) {
		result[count[(A[i] / exp) % 10] - 1] = A[i];
		count[(A[i] / exp) % 10]--;
	}
	for (int i = 0; i < n; i++)
	{
		A[i] = result[i];
	}

	delete[] result;
}

```

<br/>
<br/>

## Sorting by Binary InseritonSort algorithm
&nbsp;&nbsp;&nbsp;&nbsp;To reduce the number of comparisons in the usual form of the InsertionSort algorithm, we could use binary search, which Binary Insertion Sort does when looking for the correct location to add the item to each iteration.
<br/>
&nbsp;&nbsp;&nbsp;&nbsp;Thus, if in the normal form of the algorithm the complexity of the insertion represents O (n), using the binary search we will be able to obtain a complexity O (log n).

<br/>
<div align="center">
  <kbd>
    <img src="https://user-images.githubusercontent.com/60443226/164965608-d921b080-aa9d-4368-8f14-5a04e3b4fea8.png" alt="MarineGEO circle logo"/>
  </kbd>
</div>

<br/>

### Implementation of Binary InseritonSort

```cpp
void binaryInsertionSort(int *A, int n)
{
	int position;
	int num;
	int j;

	for (int i = 1; i < n; i++)
	{
		j = i - 1;
		num = A[i];

		position = binarySearch(A, num, 0, j);

		while (j >= position)
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = num;
	}
}

int binarySearch(int *A, int num, int start, int end)
{
	while (start <= end)
	{
		int center = start + (end - start) / 2;
		if (num == A[center])
		{
			return center + 1;
		}
		else if (num > A[center])
		{
			start = center + 1;
		}
		else
		{
			end = center - 1;
		}
	}
	return start;
}
```

<br/>

## Execution time in different situations

&nbsp;&nbsp;&nbsp;&nbsp;After studying, analyzing and implementing the proposed sorting algorithms, we could reach certain conclusions regarding the efficiency of each, because each has certain advantages, but also certain disadvantages.
<br/>
&nbsp;&nbsp;&nbsp;&nbsp;If we make a comparison between MergeSort and QuickSort, we notice that MergeSort requires large memory resources, even if there are some possibilities to reduce this, the implementation in the program will be very difficult, while QuickSort performs the sorting process in the same array, without use extra space. But if QuickSort has the advantage of low memory usage, then MergeSort has its advantage in complexity which is O (n log) and which remains the same regardless of the case, while QuickSort, even if in some situations has complexity O (n log ), for the unfavorable case it constitutes O (n ^ 2).
<br/>
&nbsp;&nbsp;&nbsp;&nbsp;If we talk about Radix Sort, it can be an alternative to the classic sorting algorithms, especially in times when the dependence on a high sorting speed is in the foreground, and the time for implementation is sufficient, so we have the advantage: Execution speed, the ability to sort different types of values (words, numbers), and the disadvantage: difficult implementation and of course extra memory consumption.

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
  
<div align="center">
  <kbd>
    <img src="https://user-images.githubusercontent.com/60443226/164966837-5c67551b-ad2b-4d78-a427-810fb34072c3.png" alt="MarineGEO circle logo"/>
  </kbd>
</div>

<br/>

### Medium sorted array

<p align="center">Execution time (in ms)<p/>

|                             |     N = 100    |     N = 1000    |     N = 10000    |     N = 100000    |     N = 1000000    |     N = 10000000    |
|:---------------------------:|:--------------:|:---------------:|:----------------:|:-----------------:|:------------------:|:-------------------:|
|           MergeSort         |        0       |         0       |       0.003      |        0.029      |        0.296       |         3.169       |
|           QuickSort         |        0       |         0       |         0        |        0.011      |        0.274       |        17.874       |
|           RadixSort         |        0       |         0       |         0        |        0.007      |        0.074       |         0.773       |
|     Binary InsertionSort    |        0       |         0       |       0.0039     |       12.744      |         30+        |          30+        |
  
  <br/>
  <p align="center">Number of comparisons<p/>

|                             |     N = 100    |     N = 1000    |     N = 10000    |     N = 100000    |     N = 1000000    |     N = 10000000    |
|:---------------------------:|:--------------:|:---------------:|:----------------:|:-----------------:|:------------------:|:-------------------:|
|           MergeSort         |       697      |       12179     |       12179      |       2645840     |       91483800     |      5586340000     |
|           QuickSort         |       1249     |       20897     |       308536     |       4191970     |       72818800     |      5368800000     |
|           RadixSort         |       1649     |       24897     |       348536     |       4591970     |       95483900     |      5626340000     |
|     Binary InsertionSort    |       2181     |       33377     |       459400     |       5741580     |        10^8+       |         10^8+       |
 
 <br/>
  <p align="center">Graphic number of comparisons<p/>

<div align="center">
  <kbd>
    <img src="https://user-images.githubusercontent.com/60443226/164967208-5483b48e-b457-4988-bee5-214f5b69534d.png" alt="MarineGEO circle logo"/>
  </kbd>
</div>

<br/>

### Unsorted array

<p align="center">Execution time (in ms)<p/>

|                             |     N = 100    |     N = 1000    |     N = 10000    |     N = 100000    |     N = 1000000    |     N = 10000000    |
|:---------------------------:|:--------------:|:---------------:|:----------------:|:-----------------:|:------------------:|:-------------------:|
|           MergeSort         |        0       |         0       |       0.002      |        0.08       |        0.513       |         6.67        |
|           QuickSort         |        0       |       0.003     |       0.405      |       48.593      |         40+        |          40+        |
|           RadixSort         |        0       |         0       |       0.001      |        0.027      |        0.366       |         6.287       |
|     Binary InsertionSort    |        0       |       0.001     |       0.288      |       30.565      |         40+        |          40+        ||
  
  <br/>
  <p align="center">Number of comparisons<p/>

|                             |     N = 100    |     N = 1000    |     N = 10000    |     N = 100000    |     N = 1000000    |     N = 10000000    |
|:---------------------------:|:--------------:|:---------------:|:----------------:|:-----------------:|:------------------:|:-------------------:|
|           MergeSort         |       505      |       7993      |       132017     |       1681060     |       19699600     |       242631000     |
|           QuickSort         |       5415     |       51204     |       506227     |       5052180     |        10^9+       |         10^9+       |
|           RadixSort         |       813      |       12001     |       181997     |       2281540     |       26680800     |       322631000     |
|     Binary InsertionSort    |       6195     |       52402     |       507864     |       5054250     |        10^9+       |         10^9+       |
 
 <br/>
  <p align="center">Graphic number of comparisons<p/>
  
<div align="center">
  <kbd>
    <img src="https://user-images.githubusercontent.com/60443226/164967292-e2b3b7bf-1319-43b8-9ab1-093316bb15bf.png" alt="MarineGEO circle logo"/>
  </kbd>
</div>

<br/>
