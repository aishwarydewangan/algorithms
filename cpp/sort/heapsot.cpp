#include <iostream>

using namespace std;

int left(int i) {
	return (2*i)+1;
}

int right(int i) {
	return (2*i)+2;
}

int parent(int i) {
	return (i-1)/2;
}

void heapify(int heap[], int size, int i) {
	if(left(i) >= size)
		return;

	if(right(i) >= size)
		return;

	int l = heap[left(i)];
	int r = heap[right(i)];
	int p = heap[i];

	
}