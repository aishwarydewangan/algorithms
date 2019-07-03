/*

The rod-cutting problem is the following:

Given a rod of length n inches and a table of prices pi for i = 1, 2,.....,n, determine the maximum revenue rn obtainable 
by cutting up the rod and selling the pieces. 
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> prices = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30, 32, 40};

map<int, int> mp;

int cutRod(int n) {
	if(n == 0) {
		return 0;
	}

	if(mp[n] != 0) {
		return mp[n];
	}

	int q = INT_MIN;

	for(int i = 1; i <= n; i++) {
		q = max(q, prices[i]+cutRod(n-i));
	}

	mp[n] = q;

	return mp[n];
}

int main() {
	int n = 1;
	cout << "\nRod Size: " << n << "\nMax Price: " << cutRod(n);
}