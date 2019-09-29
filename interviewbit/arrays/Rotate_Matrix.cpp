/*

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

You need to do this in place.

Note that if you end up using an additional array, you will only receive partial score.

Example:

If the array is

[
    [1, 2],
    [3, 4]
]
Then the rotated array becomes:

[
    [3, 1],
    [4, 2]
]
*/

#define ll long long
 
void Solution::rotate(vector<vector<int> > &A) {
    ll i = 0, n = A.size();
    if(n <= 1) {
        return;
    }
    while(i < n/2) {
        swap(A[i], A[n-i-1]);
        i++;
    }
    for(ll i = 0; i < n; i++) {
        for(ll j = i; j < n; j++) {
            swap(A[i][j], A[j][i]);
        }
    }
}