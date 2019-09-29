/*
Given an integer array, find if an integer p exists in the array such that the number of integers greater than p in the array equals to p
If such an integer is found return 1 else return -1.
*/

int Solution::solve(vector<int> &A) {
    sort(A.begin(), A.end());
    int n = A.size(), ele = A[0], i = 1;
    for(i = 1; i < n; i++) {
        if(ele != A[i]) {
            if(n-i == ele) {
                // cout << "Ele: " << abs(ele) << endl;
                return 1;
            }
            ele = A[i];
        }
    }
    if(n-i == ele) {
        return 1;
    }
    return -1;
}