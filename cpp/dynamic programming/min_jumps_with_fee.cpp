/*

Given a staircase with ‘n’ steps and an array of ‘n’ numbers representing the fee that 
you have to pay if you take the step. Implement a method to calculate the minimum fee 
required to reach the top of the staircase. At every step, you have an option to take 
either 1 step, 2 steps, or 3 steps. You should assume that you are standing at the first step.

Example 1:
    Number of stairs (n) : 6    Fee: {1,2,5,2,1,2}
    Output: 3
    Explanation: Starting from index '0', we can reach the last index through: 0->3->top
    The total fee we have to pay will be (1+2).

Example 2:
    Number of stairs (n): 4     Fee: {2,3,4,5}
    Output: 5
    Explanation: Starting from index '0', we can reach the last index through: 0->1->top
    The total fee we have to pay will be (2+3).

*/

#include <bits/stdc++.h>

using namespace std;

vector<int> memo;

int minFee(vector<int>& fees, int index) {
    if(index >= fees.size()) {
        return 0;
    }
    
    if(memo[index] != -1) {
        return memo[index];
    }
    
    int jump1 = minFee(fees, index+1);
    int jump2 = minFee(fees, index+2);
    int jump3 = minFee(fees, index+3);
    
    int jump = fees[index] + min(jump1, min(jump2, jump3));
    
    return (memo[index] = jump);
}

int main() {
    vector<int> fees = {2,3,4,5};
    memo.resize(fees.size()+1, -1);
    cout << "\nMinimum jumps with fee: " << minFee(fees, 0);
}