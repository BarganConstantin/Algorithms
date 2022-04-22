#include <iostream>
#include <chrono>
#include <fstream>
using namespace std;

int *n = nullptr;
int *A = nullptr;
int comparatii = 0;

void insert_sorted(int NrElemente);
void insert_random(int NrElemente);
void insert_reverse(int NrElemente);

void show();

void quick_sort(int *Arr, int start, int end);
int partition(int *Arr, int start, int end);
void merge_sort(int *Arr, int start, int end);
void merge(int *Arr, int left, int center, int right);

int getMax(int *A, int n);
void radixsort(int *A, int n);
void countSort(int *A, int n, int i);

void binaryInsertionSort(int *A, int n);
int binarySearch(int *A, int num, int start, int end);

void test_sorted();
void test_random();
void test_reverse();

int main()
{
	insert_random(10);

	auto begin = chrono::high_resolution_clock::now();
	show();
	merge_sort(A, 0, 9);


	auto end = chrono::high_resolution_clock::now();
	auto dur = end - begin;
	auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();

	cout << "time = " << ms << " ms\n";
	show();
	return 0;
}

void insert_sorted(int NrElemente)
{
	if (n != nullptr)
	{
		delete n;
	}
	if (A != nullptr)
	{
		delete[] A;
	}
	n = new int;
	*n = NrElemente;
	A = new int[*n];
	for (int i = 0; i < *n; i++)
	{
		A[i] = i;
	}
}

void insert_random(int NrElemente)
{
	if (n != nullptr)
	{
		delete n;
	}
	if (A != nullptr)
	{
		delete[] A;
	}
	n = new int;
	*n = NrElemente;
	A = new int[*n];
	for (int i = 0; i < *n; i++)
	{
		A[i] = rand() % 10000;
	}
}

void insert_reverse(int NrElemente)
{
	if (n != nullptr)
	{
		delete n;
	}
	if (A != nullptr)
	{
		delete[] A;
	}
	n = new int;
	*n = NrElemente;
	A = new int[*n];
	int j = *n;
	for (int i = 0; i < *n; i++)
	{
		A[i] = j;
		j--;
	}
}

void show()
{
	for (int i = 0; i < *n; i++)
	{
		cout << A[i] << endl;
	}
}

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
		comparatii++;
	}
	int tmp = Arr[end];
	Arr[end] = Arr[part_index];
	Arr[part_index] = tmp;

	return part_index;
}

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
		comparatii++;
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
		comparatii++;
	}
	for (int i = 0; i < n; i++)
	{
		A[i] = result[i];
	}

	delete[] result;
}

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
		comparatii++;
	}
	return start;
}

void test_sorted()
{
	int k = 0;
	ofstream File("sorted.txt");
	ofstream File1("sortedcomparatii.txt");
	for (int i = 1; i < 10000000;)
	{
		auto begin = chrono::high_resolution_clock::now();
		auto end = chrono::high_resolution_clock::now();
		auto dur = end - begin;
		auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();

		if (k <= 10)
		{
			insert_sorted(i);
			comparatii = 0;
			begin = chrono::high_resolution_clock::now();
			quick_sort(A, 0, *n - 1);
			end = chrono::high_resolution_clock::now();
			dur = end - begin;
			ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
			cout << "Nr." << k << "   Nr.elemente = " << i << "   Sortat in   Quick: " << ms;
			File << k << "\t\t\t" << i << "\t\t\t" << ms;
			File1 << k << "\t\t\t" << i << "\t\t\t" << comparatii;
		}
		else
		{
			cout << "Nr." << k << "   Nr.elemente = " << i << "   Sortat in   Quick: -";
			File << k << "\t\t\t" << i << "\t\t\t0";
			File1 << k << "\t\t\t" << i << "\t\t\t0";
		}

		insert_sorted(i);
		comparatii = 0;
		begin = chrono::high_resolution_clock::now();
		merge_sort(A, 0, *n - 1);
		end = chrono::high_resolution_clock::now();
		dur = end - begin;
		ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
		cout << "   Merge: " << ms;
		File << "\t\t\t" << ms;
		File1 << "\t\t\t" << comparatii;

		insert_sorted(i);
		begin = chrono::high_resolution_clock::now();
		radixsort(A, *n);
		end = chrono::high_resolution_clock::now();
		dur = end - begin;
		ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
		cout << "   Radix: " << ms;
		File << "\t\t\t" << ms;
		File1 << "\t\t\t" << comparatii;


		insert_sorted(i);
		begin = chrono::high_resolution_clock::now();
		binaryInsertionSort(A, *n);
		end = chrono::high_resolution_clock::now();
		dur = end - begin;
		ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
		cout << "   BIns: " << ms;
		File << "\t\t\t" << ms;
		File1 << "\t\t\t" << comparatii;

		cout << endl;
		File << endl;
		File1 << endl;

		if (i < 10000) i *= 3;
		else if (i < 200000) i += 10000;
		else if (i < 500000) i += 50000;
		else if (i < 800000) i += 50000;
		else i += 500000;
		k++;
	}
	File.close();
	File1.close();
}

void test_random()
{
	int k = 0;
	ofstream File("random.txt");
	ofstream File1("randomcomparatii.txt");
	for (int i = 1; i < 10000000;)
	{
		insert_random(i);

		auto begin = chrono::high_resolution_clock::now();
		quick_sort(A, 0, *n - 1);
		auto end = chrono::high_resolution_clock::now();
		auto dur = end - begin;
		auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
		cout << "Nr." << k << "   Nr.elemente = " << i << "   Sortat in   Quick: " << ms;
		File << k << "\t\t\t" << i << "\t\t\t" << ms;
		File1 << k << "\t\t\t" << i << "\t\t\t" << comparatii;

		insert_random(i);
		begin = chrono::high_resolution_clock::now();
		merge_sort(A, 0, *n - 1);
		end = chrono::high_resolution_clock::now();
		dur = end - begin;
		ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
		cout << "   Merge: " << ms;
		File << "\t\t\t" << ms;
		File1 << "\t\t\t" << comparatii;

		insert_random(i);
		begin = chrono::high_resolution_clock::now();
		radixsort(A, *n);
		end = chrono::high_resolution_clock::now();
		dur = end - begin;
		ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
		cout << "   Radix: " << ms;
		File << "\t\t\t" << ms;
		File1 << "\t\t\t" << comparatii;

		if (k <= 14)
		{
			insert_random(i);
			begin = chrono::high_resolution_clock::now();
			binaryInsertionSort(A, *n);
			end = chrono::high_resolution_clock::now();
			dur = end - begin;
			ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
			cout << "   BIns: " << ms;
			File << "\t\t\t" << ms;
			File1 << "\t\t\t" << comparatii;
		}
		else
		{
			cout << "   BIns: -";
		}

		cout << endl;
		File << endl;
		File1 << endl;

		if (i < 10000) i *= 3;
		else if (i < 200000) i += 10000;
		else if (i < 500000) i += 50000;
		else if (i < 800000) i += 50000;
		else i += 500000;
		k++;
	}
	File.close();
	File1.close();
}

void test_reverse()
{
	int k = 0;
	ofstream File("reverse.txt");
	ofstream File1("reversecomparatii.txt");
	for (int i = 1; i < 10000000;)
	{
		insert_reverse(i);

		auto begin = chrono::high_resolution_clock::now();
		auto end = chrono::high_resolution_clock::now();
		auto dur = end - begin;
		auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();

		if (k <= 10)
		{
			insert_reverse(i);
			begin = chrono::high_resolution_clock::now();
			quick_sort(A, 0, *n - 1);
			end = chrono::high_resolution_clock::now();
			dur = end - begin;
			ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
			cout << "Nr." << k << "   Nr.elemente = " << i << "   Sortat in   Quick: " << ms;
			File << k << "\t\t\t" << i << "\t\t\t" << ms;
			File1 << k << "\t\t\t" << i << "\t\t\t" << comparatii;
		}
		else
		{
			cout << "Nr." << k << "   Nr.elemente = " << i << "   Sortat in   Quick: -";
			File << k << "\t\t\t" << i << "\t\t\t0";
			File1 << k << "\t\t\t" << i << "\t\t\t0";
		}


		insert_reverse(i);
		begin = chrono::high_resolution_clock::now();
		merge_sort(A, 0, *n - 1);
		end = chrono::high_resolution_clock::now();
		dur = end - begin;
		ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
		cout << "   Merge: " << ms;
		File << "\t\t\t" << ms;
		File1 << "\t\t\t" << comparatii;

		insert_reverse(i);
		begin = chrono::high_resolution_clock::now();
		radixsort(A, *n);
		end = chrono::high_resolution_clock::now();
		dur = end - begin;
		ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
		cout << "   Radix: " << ms;
		File << "\t\t\t" << ms;
		File1 << "\t\t\t" << comparatii;

		if (k <= 10)
		{
			insert_reverse(i);
			begin = chrono::high_resolution_clock::now();
			binaryInsertionSort(A, *n);
			end = chrono::high_resolution_clock::now();
			dur = end - begin;
			ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
			cout << "   BIns: " << ms;
			File << "\t\t\t" << ms;
			File1 << "\t\t\t" << comparatii;
		}
		else
		{
			cout << "   BIns: -";
		}

		cout << endl;
		File << endl;
		File1 << endl;

		if (i < 10000) i *= 3;
		else if (i < 200000) i += 10000;
		else if (i < 500000) i += 50000;
		else if (i < 800000) i += 50000;
		else i += 500000;
		k++;
	}
	File.close();
	File1.close();
}
