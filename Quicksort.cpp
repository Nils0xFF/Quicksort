#include "Quicksort.h"

void quickSort(int* toSort, int left, int right) {
	if (left < right) {
		int s = partition(toSort, left, right);
		quickSort(toSort, left, s - 1);
		quickSort(toSort, s + 1, right);
	}
	return;
}

void quickSortIterativ(int* toSort, int size) {
	int saved = 0, left = 0, right = size - 1;
	int* kl = new int[size];
	int* kr = new int[size];
	while (left <right || saved >0)
	{
		if (left >= right) {
			left = kl[saved];
			right = kr[saved];
			saved--;
		}
		int pivotIndex = partition(toSort, left, right);
		if (right-left >= 2) {
			if ((pivotIndex - left) > (right - pivotIndex)) {
				saved++;
				kl[saved] = left;
				kr[saved] = pivotIndex - 1;
				left = pivotIndex;
			}
			else {
				saved++;
				kl[saved] = pivotIndex;
				kr[saved] = right;
				right = pivotIndex - 1;
			}
		}
		else {
			left = right;
		}
	}
	delete[] kl;
	delete[] kr;
}

void quickSortMedian(int* toSort, int left, int right) {
	if (left < right) {
		int s = partitionOfThree(toSort, left, right);
		quickSort(toSort, left, s - 1);
		quickSort(toSort, s + 1, right);
	}
	return;
}

void quickSortMedianIterativ(int* toSort, int size) {
	int saved = 0, left = 0, right = size - 1;
	int* kl = new int[size];
	int* kr = new int[size];
	while (left <right || saved >0)
	{
		if (left >= right) {
			left = kl[saved];
			right = kr[saved];
			saved--;
		}
		int pivotIndex = partitionOfThree(toSort, left, right);
		if (right - left >= 2) {
			if ((pivotIndex - left) > (right - pivotIndex)) {
				saved++;
				kl[saved] = left;
				kr[saved] = pivotIndex - 1;
				left = pivotIndex;
			}
			else {
				saved++;
				kl[saved] = pivotIndex;
				kr[saved] = right;
				right = pivotIndex - 1;
			}
		}
		else {
			left = right;
		}
	}
	delete[] kl;
	delete[] kr;
}

int partition(int* toSort, int left, int right) {
	int pivot = toSort[right];
	int i = left - 1;
	for (int j = left; j < right; j++) {
		if (toSort[j] <= pivot) {
			i++;
			swap(toSort + i, toSort + j);
		}
	}
	swap(toSort + (i + 1), toSort + right);
	return i+1;
}

int partitionOfThree(int* toSort, int left, int right) {
	medianOfThree(toSort, left, right, (int)((left + right) / 2));
	int pivot = toSort[right];
	int i = left - 1;
	for (int j = left; j < right; j++) {
		if (toSort[j] <= pivot) {
			i++;
			swap(toSort + i, toSort + j);
		}
	}
	swap(toSort + (i + 1), toSort + right);
	return i + 1;
}

void medianOfThree(int* toSort, int l, int r, int m) {
	if (toSort[l] > toSort[m]) swap(&toSort[l], &toSort[m]);
	if (toSort[l] > toSort[r]) swap(&toSort[l], &toSort[r]);
	if (toSort[m] < toSort[r]) swap(&toSort[m], &toSort[r]);
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}