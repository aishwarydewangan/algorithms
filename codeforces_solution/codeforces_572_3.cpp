#include<bits/stdc++.h>
#define ll long long
using namespace std;



void buildSparseTable(vector<vector<pair<int,int>> >& lookup  , vector<int> arr, int n) 
{ 
    // Initialize M for the intervals with length 1 
    for (int i = 0; i < n; i++) 
        lookup[i][0] = make_pair(arr[i],0); 
  
    // Compute values from smaller to bigger intervals 
    for (int j = 1; (1 << j) <= n; j++) { 
  
        // Compute minimum value for all intervals with 
        // size 2^j 
        for (int i = 0; (i + (1 << j) - 1) < n; i++) { 
  
            // For arr[2][10], we compare arr[lookup[0][7]]  
            // and arr[lookup[3][10]] 
            int num =  lookup[i][j - 1].first + lookup[i + (1 << (j - 1))][j - 1].first;
            int fcount = 0;
            if(num >= 10) fcount =1 ;
            lookup[i][j] = make_pair(num%10,lookup[i][j - 1].second + lookup[i + (1 << (j - 1))][j - 1].second + fcount);

        } 
    } 
} 
  

int main()
{       
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0 ; i<  n ; i++)
        {
                cin>>arr[i];
        }
        int maxv = log2(n) + 1;
        vector<vector<pair<int,int>>> lookup(n,vector<pair<int,int>>(maxv));
        buildSparseTable(lookup,arr,n);
       // cout<<"iske bhar"<<endl;
        int q;
        cin>>q;
        while(q--)
        {
                int l ;
                int r;
                cin>>l>>r;
                int level = log2(r-l+1);
                cout<<lookup[l-1][level].second<<endl;

        }
        return 0;
}