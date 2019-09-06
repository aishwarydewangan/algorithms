/*

Given a positive integer n and a string s consisting only of letters D or I, you have to find any 
permutation of first n positive integer that satisfy the given input string.

D means the next number is smaller, while I means the next number is greater.

Example :
	Input 1:
	n = 3
	s = ID
	Return: [1, 3, 2]
*/

/*
Intuiton: Make the count of D. We know that numbers less than D are not used.
*/

#define ll long long

vector<int> Solution::findPerm(const string A, int B) {
    vector<int> res;
    ll D = 0, I = 0;
    for(ll i = 0; i < A.size(); i++) {
        if(A[i] == 'D') {
            D++;
        }
    }
    res.push_back(D+1);
    I = res.back()+1;
    for(ll i = 0; i < A.size(); i++) {
        if(A[i] == 'D') {
            res.push_back(D--);
        } else {
            res.push_back(I++);
        }
    }
    return res;
}