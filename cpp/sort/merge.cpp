#include <iostream>

using namespace std;

void show(int a[], int size) {
	for(int i = 0; i < size; i++)
		cout << a[i] << "\t";
}

void merge(int a[], int l, int m, int r) {

	int *ta;
	int i = 0, x = l, y = m + 1;
	ta = new int[r-l+1];
	
	while(x <= m && y <= r) 
		ta[i++] = (a[x] <= a[y]) ? a[x++] : a[y++];

	if(x <= m) {
		for(int j = x; j <= m; j++) {
			ta[i++] = a[j];
		}
	}

	if(y <= r) {
		for(int j = y; j <= r; j++)
			ta[i++] = a[j];
	}
	
	i = 0;
	
	for(int j = l; j <= r; j++)
		a[j] = ta[i++];

	delete ta;
}

void mergeSort(int a[], int l, int r) {

	if(l < r) {
		int m = (l+r)/2;
		mergeSort(a, l, m);
		mergeSort(a, m+1, r);
		merge(a, l, m, r);
	}
}

int main() {

	int a[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

	mergeSort(a, 0, 9);

	show(a, 10);
	cout << endl;

	return 0;
}
