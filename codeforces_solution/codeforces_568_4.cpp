#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll try_run(vector<ll>& nums , ll d)
{
        ll a = nums[0];
        ll i = 1;
        ll count  = 0;
        ll p = 1;
        ll index = -1;
        while(i<nums.size())
        {       
                ll temp = a+(p*d);
                if(nums[i] == temp)
                {
                        p++;
                        i++;
                }
                else
                {       
                        if(count == 0)
                           {    
                                index = i;
                                count += 1;
                                i++;
                           }
                        else
                        {
                                return -2;
                        }
                }
                

        }
        return index;
}

int main()
{       
        ll n;
        cin>>n;
        vector<ll> nums(n);
        unordered_map<ll,ll> um;
        unordered_map<ll,ll> imap;
        for(int i = 0 ; i < n ;i++)
        {
                cin>>nums[i];
                imap[nums[i]] = i;
        }
        sort(nums.begin(),nums.end());
        vector<ll> poss_diff;
        ll count_diffs = 0;
        ll d;
        for(int i = 0 ; i <  nums.size()-1 ; i++)
        {
               d = nums[i+1] - nums[i];
               if(um[d] == 0)
               {        
                       
                       count_diffs += 1;
                       um[d] += 1;
                        if(count_diffs > 3)
                        {
                                cout<<-1<<endl;
                                exit(0);
                        }
                
                poss_diff.push_back(d);
               } 

               
        }
        if(poss_diff.size() == 1)
        {
                cout<<1<<endl;
                exit(0);
        }
        else 
        {
                for(auto di : poss_diff)
                {       
                        int flag2 = 1;
                        for(int i = 1 ;i < nums.size() - 1 ; i++)
                        {
                                if((nums[i+1] - nums[i]) != d)
                                {
                                        flag2 = 0;
                                }
                        }
                        if(flag2)
                        {
                                cout<<imap[nums[0]]+1<<endl;
                                exit(0);
                        }
                        ll ind  = try_run(nums,di);
                        if( ind != -2)
                        {
                                cout<<imap[nums[ind]] + 1<<endl;
                                exit(0);
                        }
                }

        }
        cout<<-1<<endl;
        exit(0);
        
        return 0;
}