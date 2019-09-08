/*

Implement the next permutation, which rearranges numbers into the numerically next greater permutation 
of numbers for a given array A of size N.

If such arrangement is not possible, it must be rearranged as the lowest possible order i.e., sorted 
in an ascending order.	

The following algorithm generates the next permutation lexicographically after a given permutation. 
It changes the given permutation in-place.

	(i) 	Find the largest index k such that a[k] < a[k + 1]. If no such index exists, the permutation is the last permutation.
	(ii) 	Find the largest index l greater than k such that a[k] < a[l].
	(iii) 	Swap the value of a[k] with that of a[l].
	(iv) 	Reverse the sequence from a[k + 1] up to and including the final element a[n].
*/

void nextPermutation(vector<int> &a) {
    int n = a.size(), k = -1;
    int i = n-1;
    while(i > 0) {
        if(a[i-1] < a[i]) {
            k = i-1;
            break;
        }
        i--;
    }
    if(k == -1) {
        reverse(a.begin(), a.end());
        return;
    }
    int l = k+1;
    i = n-1;
    while(i > k) {
        if(a[i] > a[k]) {
            l = i;
            break;
        }
        i--;
    }
    swap(a[k], a[l]);
    reverse(a.begin()+k+1, a.end());
}