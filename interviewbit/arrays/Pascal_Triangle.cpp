/*

Given numRows, generate the first numRows of Pascal’s triangle.

Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

Example:

Given numRows = 5,

Return

[
     [1],
     [1,1],
     [1,2,1],
     [1,3,3,1],
     [1,4,6,4,1]
]
*/

vector<vector<int> > Solution::solve(int n) {
    vector<vector<int>> res;
    res.push_back({1});
    res.push_back({1, 1});
    int k = 1;
    for(int i = 2; i < n; i++) {
        int m = res[k].size()+1;
        vector<int> row(m);
        row[0] = res[k][0];
        row[m-1] = res[k][m-2];
        for(int j = 1; j < m-1; j++) {
            row[j] = res[k][j] + res[k][j-1];
        }
        res.push_back(row);
    }
    return res;
}
