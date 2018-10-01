#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int n;

vector< vector<int> > board;

void printSolution() {
    cout << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }
    cout << endl;
}

bool isSafe(int x, int y) {
    for(int i = 0; i < n; i++) {    //Check Row
        if(i == y)
            continue;
        if(board[x][i] == 1)
            return false;
    }
    for(int i = 0; i < n; i++) {    //Check Column
        if(i == x)
            continue;
        if(board[i][y] == 1)
            return false;
    }
    int i = 0;
    while(x-i >= 0 && y-i >= 0) {    //Check Up Left
        if(x-i != x && y-i != y) {
            if(board[x-i][y-i] == 1)
                return false;
        }
        i++;
    }
    i = 0;
    while(x+i < n && y+i < n) {        //Check Down Right
        if(x+i != x && y+i != y) {
            if(board[x+i][y+i] == 1)
                return false;
        }
        i++;
    }
    i = 0;
    while(x-i >= 0 && y+i < n) {    //Check Up Right
        if(x-i != x && y+i != y) {
            if(board[x-i][y+i] == 1)
                return false;
        }
        i++;
    }
    i = 0;
    while(x+i < n && y-i >= 0) {    //Check Down Left
        if(x+i != x && y-i != y) {
            if(board[x+i][y-i] == 1)
                return false;
        }
        i++;
    }
    return true;
}

void NQueen(int y) {

    if(y == n) {
    	printSolution();
        return;
    }
    
    for(int i = 0; i < n; i++) {
	    if(isSafe(i, y)) {
	        board[i][y] = 1;
	        NQueen(y+1);
	        board[i][y] = 0;
	    }
    }
}

int main() {
    
    cin >> n;

    board.resize(n , vector<int>(n, 0));

    NQueen(0);

    return 0;
}