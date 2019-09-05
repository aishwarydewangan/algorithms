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

void selectionSort(int a[], int size) {

	for(int i = 0; i < size; i++) {
		int key = a[i], j = i + 1, pos = -1;

		while(j < size) {
			if(key > a[j])
				pos = j;
			j++;
		}

		if(pos != -1)
			swap(&a[i], &a[pos]);
	}

	show(a, size);
}

int main() {

	int a[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

	selectionSort(a, 10);

	return 0;
}
