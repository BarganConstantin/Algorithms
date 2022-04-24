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
