/*

Given a non-negative number represented as an array of digits,

add 1 to the number ( increment the number represented by the digits ).

The digits are stored such that the most significant digit is at the head of the list.

Example:
	If the vector has [1, 2, 3] the returned vector should be [1, 2, 4] as 123 + 1 = 124.
*/

vector<int> Solution::plusOne(vector<int> &A) {
    reverse(A.begin(), A.end());
    int c = (A[0]+1)/10;
    A[0] = (A[0]+1)%10;
    for(int i = 1; i < A.size(); i++) {
        int t = (A[i]+c)%10;
        c = (A[i]+c)/10;
        A[i] = t;
    }
    if(c != 0)
        A.push_back(c);
    reverse(A.begin(), A.end());
    int i = 0, j = 0;
    while(A[j] == 0) {
        j++;
    }
    while(j < A.size()) {
        A[i] = A[j];
        i++;
        j++;
    }
    A.resize(i);
    return A;
}