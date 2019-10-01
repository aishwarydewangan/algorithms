#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main()
{       

        ll q;
        cin>>q;
        while(q--)
        {
                ll n;
                ll k;
                cin>>n>>k;
                vector<ll> arr(n);
                for(ll i= 0 ; i< n ; i++)
                        cin>>arr[i];
                

                ll flag  = 1;
               // cout<<min_b<<" "<<max_b<<endl;
                sort(arr.begin(),arr.end());
                ll min_b = max(arr[0]-k,0LL);
                ll max_b = arr[0] + k;
                ll min_c = max(arr[n-1]-k,0LL);
                ll max_c = arr[n-1] + k;
                if(max_b < min_c)
                {
                        cout<<-1<<endl;
                }
                else
                {       
                        if(max_b == min_c)
                        {
                                cout<<max_b<<endl;
                                continue;
                        }
                        cout<<min(max_b,max_c)<<endl;
                }
                
        }
        exit(0);
        return 0;
}