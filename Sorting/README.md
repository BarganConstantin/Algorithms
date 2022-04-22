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
