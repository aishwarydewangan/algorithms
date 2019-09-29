/*

Give a N*N square matrix, return an array of its anti-diagonals. Look at the example for more details.

Example:

		
Input: 	

1 2 3
4 5 6
7 8 9

Return the following :

[ 
  [1],
  [2, 4],
  [3, 5, 7],
  [6, 8],
  [9]
]

Input : 
1 2
3 4

Return the following  : 

[
  [1],
  [2, 3],
  [4]
]
*/

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int n = A.size(), r = 0, c = 1, k = 0;
    vector<vector<int>> res;
    res.push_back({A[0][0]});
    if(n == 1) {
        return res;
    }
    while(r < n && c < n) {
        int i = r, j = c;
        vector<int> t;
        while(j >= k) {
            // cout << "[" << i << ", " << j << "]" << endl;
            t.push_back(A[i][j]);
            i++;
            j--;
        }
        res.push_back(t);
        if(c != n-1) {
            c++;
        } else {
            r++;
            k++;
        }
        if(r == n-1) {
            break;
        }
    }
    res.push_back({A[n-1][n-1]});
    return res;
}