/*
It’s Tushar’s birthday today and he has N friends.

Friends are numbered [0, 1, 2, …., N-1] and i-th friend have a positive strength B[i].

Today being his birthday, his friends have planned to give him birthday bombs (kicks :P).

Tushar’s friends know Tushar’s pain bearing limit and would hit accordingly.

If Tushar’s resistance is denoted by A (>=0) then find the lexicographically smallest order of friends to kick Tushar so that 
the cumulative kick strength (sum of the strengths of friends who kicks) doesn’t exceed his resistance capacity and total no. of 
kicks hit are maximum.

Also note that each friend can kick unlimited number of times (If a friend hits x times, his strength will be counted x times)

Return the lexicographically smallest array of maximum length where the ith index represents the index of the friend who will hit.

Note:
1. [a1, a2, ...., am] is lexicographically smaller than [b1, b2, .., bm]  if a1 < b1 or (a1 = b1 and a2 < b2) ... .
2. Input cases are such that the length of the answer does not exceed 100000.
Input Format:

The first argument contains an integer, A of length N.
The second argument contains an array of integers, B.
Output Format:

Return an array of integer, as described in the problem statement.

Constraints:
	1 <= N <= 100
	1 <= A <= 15000000
	1 <= B[i] <= 3000

Examples:
	Input 1:
	    A = 12
	    B = [3, 4]

	Output 1:
	    [0, 0, 0, 0]

	Explanation 1:
	    [1, 1, 1] is also a possible answer.

	Input 2:
	    A = 11
	    B = [6, 8, 5, 4, 7]

	Output 2:
	    [0, 2]

	Explanation 2:
	    [2, 3], [2, 2] and [3, 3] are also possible answers.


Solution Approach:

Let the index of the first minimum strength be m. Then the maximum number of kicks is n=R/S[m]. 
So O=[m,m,...,m], where the number of m's is n, is a kick order with maximum number of kicks, with total strength n*S[m].

How can we get a lexicographically smaller order with the same number of kicks? If we can find an index i smaller than m such that 
we can replace a kick of strength S[m] by a kick of strength S[i] without overpassing the resistance capacity R, then we can replace 
the first element in O by i, making the order lexicographically smaller. To make it as lexicographically as small as possible, we would 
like the index i as small as possible and, then, we would like to use it as many times as possible.

For example, R=11,S=[6,8,5,4,7,4]. Then the first minimum strength is the first 4 whose index is 3. So n=11/4=2 and O=[3,3] with total 
strength 4*2=8. To make it smaller, we will check the strengths before 4 in order. The first one is 6. Since 8−4+6=10<11, we find a smaller 
order [0,3]. If we apply 6 again, we would get 10−4+6=12>11. So we go ahead to check the next strength 8, which is too large. So we go ahead 
to check 5. Since 10−4+5=11≤11, we find a smaller order [0,2]. Since the room left for replacement, 11−11=0, we stop our effort. The final 
answer is [0,2].
*/

vector<int> Solution::solve(int A, vector<int> &B) {
    if(B.empty()) return {};
    int mn = B[0], mnid = 0;
    for(int i = 1; i < B.size(); i++) {
        if(mn > B[i]) {
            mn = B[i];
            mnid = i;
        }
    }
    if(mn > A) return {};
    int kicks = A/mn;
    vector<int> res(kicks, mnid);
    int i = 0, j = 0;
    int total = kicks*mn;
    while(i < kicks && j < mnid) {
        int temp = total-B[res[i]]+B[j];
        if(temp > total && temp <= A) {
            res[i++] = j;
            total = temp;
        } else {
            j++;
        }
    }
    return res;
}