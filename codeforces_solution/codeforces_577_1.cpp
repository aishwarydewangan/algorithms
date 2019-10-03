#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{       
        int n, m;
        cin>>n>>m;
        vector<vector<char>> arr(1001,vector<char>(1001,'X'));
        char temp;
        for(int i = 0 ; i< n ; i++)
        {       
                string temp;
                cin>>temp;
                for(int j = 0 ; j < m ; j++) arr[i][j] = temp[j];
        }
        vector<int> points;
        int p;
        for(int i = 0 ; i< m ; i++)
        {
                cin>>p;
                points.push_back(p);
        }
        long long ans = 0;
        unordered_map<char,int> dp;
        for(int j = 0 ; j < m ; j++)
        {       
                int max_c =1;
                dp.clear();
                for(int i = 0 ; i < n ; i++)
                {       
                        dp[arr[i][j]]++;
                        max_c = max(max_c,dp[arr[i][j]]);
                }
                ans = ans + max_c*points[j];
        }
        cout<<ans<<endl;
        return 0;
}