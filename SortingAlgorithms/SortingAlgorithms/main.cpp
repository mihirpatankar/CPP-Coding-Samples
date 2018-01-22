#include <iostream>
using namespace std;


void selectionSort(int A[],int n) {
	for (int i = 0; i < n-1; i++) {
		int minIndex = i;
		for (int j = i; j < n; j++) {
			if (A[j]<A[minIndex]) {
				minIndex = j;
			}
		}
		int temp = A[minIndex];
		A[minIndex] = A[i];
		A[i] = temp;
	}
}

void insertionSort(int A[], int n) {
	for (int i = 1; i < n; i++) {
		int value = A[i];
		int hole = i;
		while (hole > 0 && A[hole-1] >= value) {
			A[hole] = A[hole - 1];
			hole--;
		}
		A[hole] = value;
	}
}

void merge(int left[], int l, int right[], int r, int A[]) {
	int i = 0, j = 0, k = 0;
	while (i < l && j < r) {
		if (left[i] < right[j]) {
			A[k] = left[i];
			i++;
		}
		else {
			A[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < l) {
		A[k] = left[i];
		k++;
		i++;
	}
	while (j < r) {
		A[k] = right[j];
		k++;
		j++;
	}
}

void mergeSort(int A[], int n) {
	if (n <= 1) {
		return;
	}
	int mid = n / 2;
	int* left = new int [mid];
	int* right = new int [n - mid];
	for (int i = 0; i < mid; i++) {
		left[i] = A[i];
	}
	for (int i = mid; i < n; i++) {
		right[i - mid] = A[i];
	}
	mergeSort(left, mid);
	mergeSort(right, n - mid);
	merge(left, mid, right, n - mid, A);
	delete(left);
	delete(right);
}

void printArray(int A[], int n) {
	for (int i = 0; i < n; i++) {
		cout << A[i] <<" ";
	}
	cout << endl;
}

int main() {
	int A[] = { 6,5,4,3,2,1,-1,10,3,5,7 };
	int size = sizeof(A) / sizeof(A[0]);
	printArray(A, size);
	//selectionSort(A, size);
	//insertionSort(A, size);
	mergeSort(A, size);
	printArray(A, size);
	getchar();
	return 0;
}