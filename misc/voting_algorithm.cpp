/*

Given an array of integer write an algorithm to find the majority element in it. If an element appears 
more than n/2 times in array where n is the size of the array.
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> nums = {1, 2, 3, 2, 4, 2, 5, 2, 6, 2, 7, 2, 8, 2};
    
    int count = 1, majority = nums[0], n = nums.size();
    for(int i = 1; i < n; i++) {
        if(count == 0) {
            majority = nums[i];
        }
        if(majority == nums[i]) {
            count += 1;
        } else {
            count -= 1;
        }
    }
    count = 0;
    for(int i = 0; i < n; i++) {
        if(majority == nums[i]) {
            count++;
        }
    }
    if(count > n/2) {
        cout << "\nMajority element: " << majority;
    } else {
        cout << "\nNo majority element exists";
    }
    return 0;
}