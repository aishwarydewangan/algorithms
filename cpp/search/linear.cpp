#include <iostream>

using namespace std;

int main() {
	int a[] = {1, 9, 4, 0, 2, 7, 3, 8, 6, 5};

	int key = 5, f = -1;

	for(int i = 0; i < 10; i++)
		if(a[i] == key) {
			f = i + 1;
			cout << "\nElement found at position: " << i + 1;
		}

	if(f == -1)
		cout << "\nElement not found.";

	return 0;
}
