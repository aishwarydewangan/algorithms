/*

You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

Example 1:

	Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
	Output: 4

Example 2:

	Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
	Output: -1
	Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

Example 3:

	Input: grid = [[0,2]]
	Output: 0
	Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
*/

#include <bits/stdc++.h>

using namespace std;

struct node {
    int i, j;
};

bool isSafe(vector<vector<int>>& grid, int i, int j) {
    int m = grid.size(), n = grid[0].size();
    return ((i >= 0) && (i < m) && (j >= 0) && (j < n) && (grid[i][j] == 1));
}

bool isDelim(node d) {
    return ((d.i == -1) && (d.j == -1));
}

int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    queue<node> q;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 2) {
                node n;
                n.i = i;
                n.j = j;
                q.push(n);
            }
        }
    }
    node delim;
    delim.i = -1;
    delim.j = -1;
    q.push(delim);
    int time = 0;
    while(q.size() > 1) {
        while(!isDelim(q.front())) {
            node n = q.front();
            node k;
            if(isSafe(grid, n.i-1, n.j)) {
                grid[n.i-1][n.j] = 2;
                k.i = n.i-1;
                k.j = n.j;
                q.push(k);
            }
            if(isSafe(grid, n.i+1, n.j)) {
                grid[n.i+1][n.j] = 2;
                k.i = n.i+1;
                k.j = n.j;
                q.push(k);
            }
            if(isSafe(grid, n.i, n.j-1)) {
                grid[n.i][n.j-1] = 2;
                k.i = n.i;
                k.j = n.j-1;
                q.push(k);
            }
            if(isSafe(grid, n.i, n.j+1)) {
                grid[n.i][n.j+1] = 2;
                k.i = n.i;
                k.j = n.j+1;
                q.push(k);
            }
            q.pop();
        }
        q.pop();
        if(q.size() > 0)
            time += 1;
        q.push(delim);
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 1) 
                return -1;
        }
    }
    return time;
}

int main() {
	vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
	cout << orangesRotting(grid);
	return 0;
}