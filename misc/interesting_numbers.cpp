/*
Interesting numbers are positive integers whose decimal representation contains only the digits 4 and 7. 
For example, numbers 44, 74, 4 are interesting and 5, 17, 467 are not.Let next(x) be the minimum 
interesting number which is larger than or equals x. What is the value of the expression 
next(l) + next(l + 1) + ... + next(r - 1) + next(r)?

Input Format

First line contains T i.e number of testcases.

Each of T lines contains two space separated integers l and r

Constraints

1<= T <= 10000

1<= l <= r <= 1000000000

Output Format

Corresponding to each test case print the required answer on new line.

Sample Input 0

2
1 5
1 4

Sample Output 0

23
16

Explanation 0

In first test case next(1)=4 next(2)=4 next(3)=4 next(4)=4 next(5)=7 , so , 4+4+4+4+7=23 */


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int insertarr(vector<long long>& arr,int x){
    int n=arr.size();
    for(int i=x;i<n;i++){
        arr.push_back(arr[i]*10+4);
        arr.push_back(arr[i]*10+7);
    }
    return n;
}

int main() {
    vector<long long> arr;
    arr.push_back(0);
    arr.push_back(4);
    arr.push_back(7);
    int d=1;
    for(int i=0;i<10;i++){
        d=insertarr(arr,d);
    }
    sort(arr.begin(),arr.end());
    int n=arr.size();
    vector<long long>::iterator lower1;
    int t;
    cin>>t;
    for(int w=0;w<t;w++){
        long long a,b,m;
        cin>>a>>b;
        long long int s=0;
        lower1= lower_bound(arr.begin(),arr.end(),a);
        long index=lower1 - arr.begin();
        while(a <= b) {
            if(b < arr[index]){
                m = b - a + 1;
            }else{
                m = arr[index]-a+1;
            }
            s += arr[index]*m;
            a = arr[index]+1;
            index++;
        }
        cout<<s<<endl;
    }
    return 0;
}

