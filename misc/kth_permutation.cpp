/*

The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note:

Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.

Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"
*/

class Solution {
public:
    string getPermutation(int n, int k) {
        
        vector<int> fact(n+1, 0);
        fact[0] = 1;
        for(int i = 1; i <= n; i++) {
            fact[i] = i*fact[i-1];
        }
        
        string num = "";
         
        k -= 1;
        
        vector<int> nums(n, 0);
        
        for(int i = 1; i <= n; i++) {
            nums[i-1] = i;
        }
        
        for(int i = 1; i <= n; i++) {
            int index = k/fact[n-i];
            num += to_string(nums[index]);
            nums.erase(nums.begin()+index);
            k -= index*fact[n-i];
        }
        
        return num;
    }
};