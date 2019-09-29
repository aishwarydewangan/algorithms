/*
Given a read only array of n + 1 integers between 1 and n, find one number that repeats in linear time using less than O(n) space and traversing the stream sequentially O(1) times.

Sample Input:

[3 4 1 4 1]
Sample Output:

1
If there are multiple possible answers ( like in the sample case above ), output any one.

If there is no duplicate, output -1
*/

//Solution 1
int Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    char ch[n+1];
    memset(ch, '0', sizeof(ch));
    for(int i = 0; i < n; i++) {
        if(ch[A[i]] == '1') {
            return A[i];
        }
        ch[A[i]] = '1';
    }
    return -1;
}

//Solution 2
int Solution::repeatedNumber(const vector<int> &A) {
    int xor1 = 0, xor2 = 1, n = A.size();
    
    for(int i=0;i<A.size();i++) {
        xor1 ^= A[i];
    }
    
    for(int i=2;i<=(n-1);i++) {
        xor2 ^= i;
    }
    
    return xor1^xor2;
}