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

void insertionSort(int a[], int size) {

	for(int i = 1; i < size; i++) {

		int j = i;
		
		while(j > 0) {
			if(a[j] < a[j-1])
				swap(&a[j], &a[j-1]);
			j--;
		}
	}

	show(a, size);
}

int main() {

	int a[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

	insertionSort(a, 10);

	return 0;
}
