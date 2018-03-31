#include <iostream>

using namespace std;

void show(int a[], int size) {
	for(int i = 0; i < size; i++)
		cout << a[i] << "\t";
}

void swap(int *a, int *b) {
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

int partition(int a[], int low, int high) {
}

void quickSort(int a[], int low, int high) {

	if(low < high) {

		int pos = partition(a, low, high);

		quickSort(a, low, pos-1);

		quickSort(a, pos+1, high);
	}
}

int main() {

	int a[10] = {4, 9, 7, 8, 1, 3, 0, 2, 5, 6};

	quickSort(a, 0, 9);

	show(a, 0 , 9);
	cout << endl;

	return 0;
}
