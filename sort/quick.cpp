#include <iostream>

using namespace std;

void show(int a[], int size) {
	for(int i = 0; i < size; i++)
		cout << a[i] << "\t";
	cout << endl;
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int a[], int low, int high) {

	int pivot = a[high];

	int i = low - 1;

	for(int j = low; j <= high - 1; j++)
		if(a[j] <= pivot)
			swap(&a[++i], &a[j]);

	swap(&a[i+1], &a[high]);

	return i+1;
}

void quickSort(int a[], int low, int high) {

	if(low < high) {

		int pos = partition(a, low, high);

		quickSort(a, low, pos-1);

		quickSort(a, pos+1, high);
	}
}

int main() {

	int a[10] = {7, 9, 2, 4, 8, 0, 1, 6, 3, 5};

	quickSort(a, 0, 9);

	show(a, 10);

	return 0;
}
