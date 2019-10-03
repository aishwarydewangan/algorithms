#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main()
{       
        vector<ll> dp(101);
        dp[1] = 1;
        dp[2] = 5;
        ll count_v = 8;
        for(int j = 3; j <= 100 ; j++)
        {
                dp[j] =  dp[j-1]+count_v;
                count_v += 4;
        }
        int n;
        cin>>n;
        cout<<dp[n]<<endl;
        return 0;
}