#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main()      
{       


        int t;
        cin>>t;
        while(t--)
        {
                int n;
                cin>>n;
                vector<ll> nums(n);
                int count  = 0;
                vector<ll> remainders;
                ll ones_count = 0;
                ll twos_count = 0;
                for(int i = 0 ; i  < n ; i++)
                {
                        cin>>nums[i];
                        if(nums[i]%3 == 0)
                        {
                                count += 1;
                        }
                        else
                        {
                                //remainders.push_back(nums[i] % 3);
                                if(nums[i] %3 == 2) twos_count += 1;
                                if(nums[i] % 3 == 1) ones_count += 1;
                        }
                        
                }

                ll temp = min(ones_count,twos_count);
               // cout<<temp<<"temp"<<endl;
                ll temp2 = (int)((ones_count - temp)/3);
               // cout<<temp2<<"temp2"<<endl;
                ll temp3 = twos_count - temp;
                if(temp3 != 0 )
                {
                        count += (int)temp3/3;
                }
                count += temp;
                count +=temp2;

                cout<<count<<endl;
        }
        return 0;
}