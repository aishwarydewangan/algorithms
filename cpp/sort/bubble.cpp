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

void bubbleSort(int a[], int size) {

	int check = -1;
	
	for(int j = 0; j < size; j++) {
		for(int i = 0; i < size-j-1; i++) {
			if(a[i] > a[i+1]) {
				swap(a[i], a[i+1]);
				check = i;
			}
			if(check == -1)
				break;

			check = -1;
		}
	}

	show(a, size);
}

int main() {

	int a[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

	bubbleSort(a, 10);

	cout << endl;

	return 0;
}
