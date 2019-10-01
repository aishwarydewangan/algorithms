#include<bits/stdc++.h>
#define ll long long
using namespace std;
void perform_operation(ll opnum,unordered_map< ll,pair<int,int> > & ans,deque<int>& dq)
{
        int a = dq.front();
        dq.pop_front();
        int b = dq.front();
        dq.pop_front();
        ans[opnum] = make_pair(a,b);
        if(a>b)
        {
                dq.push_front(a);
                dq.push_back(b);
        }
        else
        {
                dq.push_front(b);
                dq.push_back(a);
        }
        
}
int main()
{       
        int n,q;
        cin>>n>>q;
        deque<int> dq;
        int temp;
        int maxv = INT_MIN;
        unordered_map<ll,pair<int,int> >ans;
        
        for(int i = 0 ; i < n ; i++)
        {
                cin>>temp;
                maxv = max(maxv,temp);
                dq.push_back(temp);
        }
        ll num_op = 0;
        int total_diff = 0;
        while(true)
        {       
                num_op += 1;
                perform_operation(num_op,ans,dq);   
                if(dq.front() == maxv)
                {
                        total_diff = num_op;
                }    
        }
        while(q--)
        {
                ll query;
                cin>>query;
                if(query<= total_diff)
                {
                        cout<<ans[query].first<<" "<<ans[query].second<<endl;
                }
                else
                {
                        cout<<dq.front()<<" "<<dq[(query%(n-1)) + 1]<<endl;
                }
                
        }

        return 0;
}