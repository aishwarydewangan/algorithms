#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{       


        int n;
        cin>>n;
        vector<ll> arr(n);
        for(int i = 0 ; i < n ; i++)
        {
                cin>>arr[i];
        }
        sort(arr.begin(),arr.end());
        if(arr[n-1] >= (arr[n-2]+arr[n-3]))
        {
                cout<<"NO"<<endl;
                exit(0);
        }
        else
        {
                swap(arr[n-1],arr[n-2]);
                int flag  = 0;
                for(int i = 0 ; i <  n ;i++)
                {
                        if(i == 0)
                        {
                                if( (arr[n-1] + arr[1]) <= arr[i] )
                                {
                                        flag = 1;
                                }
                        }
                        else if(i == n-1)
                        {
                                if( (arr[n-2] + arr[0]) <= arr[i] )
                                {
                                        flag = 1;
                                }    
                        }
                        else
                        {
                                if( (arr[i-1]+arr[i+1]) <= arr[i] )
                                {
                                        flag = 1;
                                }
                        }
                        
                }
                if(flag)
                {
                        cout<<"NO"<<endl;
                        exit(0);
                }
                else
                {       
                        cout<<"YES"<<endl;
                        for(auto x : arr)
                        {
                                cout<<x<<" ";
                        }
                        cout<<endl;
                        exit(0);
                }
                
        }
        
        return 0;
}