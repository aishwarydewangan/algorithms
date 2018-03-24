#include <iostream>

using namespace std;

int main() {

	int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	int key = 5;

	int low = 0, high = 9, mid, f = -1;

	while(low <= high) {
		mid = (low + high) / 2;
		
		if(a[mid] == key) {
			f = mid + 1;
			cout << "\nElement found at position: " << mid + 1;
			break;
		}

		if(a[mid] > key)
			high = mid - 1;
		
		if(a[mid] < key)
			low = mid + 1;
	}

	if(f == -1)
		cout << "\nElement not found.";

	return 0;
}
