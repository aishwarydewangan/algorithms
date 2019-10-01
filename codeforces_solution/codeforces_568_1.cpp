#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main()
{       
        vector<ll> nums(3);
        ll temp;
        ll diff;
        ll ans = 0;
        for(int i  =  0 ; i < 3 ; i++)
        {
                cin>>nums[i];
        }
        sort(nums.begin(),nums.end());
        cin>>diff;
       // cout<<diff<<endl;
        if(diff == 0)
        {
                cout<<0<<endl;
                exit(0);
        }
        else
        {
               if( (nums[1] - nums[0]) < diff) 
               {        
                       //cout<<"inside1"<<endl;
                       ans += diff - (nums[1] - nums[0]);
               }
               if( (nums[2] - nums[1]) < diff)
               {        
                       //cout<<"inside2"<<endl;
                       ans += diff - (nums[2] - nums[1]);
               }
        }
        cout<<ans<<endl;
        exit(0);
        
        return 0;
}