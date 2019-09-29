/*

Given an integer A, generate a square matrix filled with elements from 1 to A2 in spiral order.

Input Format:	The first and the only argument contains an integer, A.

Output Format:	Return a 2-d matrix of size A x A satisfying the spiral order.

Constraints:	1 <= A <= 1000

Examples:

Input 1:
    A = 3

Output 1:
    [   [ 1, 2, 3 ],
        [ 8, 9, 4 ],
        [ 7, 6, 5 ]   ]

Input 2:
    4

Output 2:
    [   [1, 2, 3, 4],
        [12, 13, 14, 5],
        [11, 16, 15, 6],
        [10, 9, 8, 7]   ]
*/

vector<vector<int> > Solution::generateMatrix(int n) {
    int r = 0, c = 0, k = 1, A = n;
    int left = 0, right = n-1, top = 0, down = n-1;
    vector<vector<int>> grid(n, vector<int>(n));
    while(k <= A*A) {
        while(c <= right) {
            grid[r][c] = k;
            // cout << "[" << r << ", " << c << "]: " << k << endl;
            k++;
            c++;
        }
        r++;
        c--;
        top++;
        while(r <= down) {
            grid[r][c] = k;
            // cout << "[" << r << ", " << c << "]: " << k << endl;
            k++;
            r++;
        }
        c--;
        r--;
        right--;
        while(c >= left) {
            grid[r][c] = k;
            // cout << "[" << r << ", " << c << "]: " << k << endl;
            k++;
            c--;
        }
        r--;
        c++;
        down--;
        while(r >= top) {
            grid[r][c] = k;
            // cout << "[" << r << ", " << c << "]: " << k << endl;
            k++;
            r--;
        }
        c++;
        r++;
        left++;
    }
    return grid;
}
