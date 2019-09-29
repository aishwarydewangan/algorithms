/*

Given an index k, return the kth row of the Pascal’s triangle.

Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

Example:

Input : k = 3

Return : [1,3,3,1]

NOTE : k is 0 based. k = 0, corresponds to the row [1]. 
*/

vector<int> Solution::getRow(int n) {
    if(n == 0) {
        return {};
    }
    vector<vector<int>> res;
    res.push_back({1});
    res.push_back({1, 1});
    int k = 1;
    for(int i = 2; i <= n; i++) {
        int m = res[k].size()+1;
        vector<int> row(m);
        row[0] = res[k][0];
        row[m-1] = res[k][m-2];
        for(int j = 1; j < m-1; j++) {
            row[j] = res[k][j] + res[k][j-1];
        }
        res.push_back(row);
        k++;
    }
    return res[n];
}
