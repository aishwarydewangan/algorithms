
#include<bits/stdc++.h>
#define ll long long
using namespace std;



int min_cost(int ptr1 , int ptr2 , string& s , string& t ,int n , int m, int& starting_index , int& endind_index , int started)
{
        if(ptr2 == m)
        {       
                endind_index = min(endind_index,ptr1-1);
                return 0;
        }
        if(ptr1 == n)
        {
                return INT_MAX-1;
        }
        int cost = 0;
        if(s[ptr1]==t[ptr2])
        {       
                if(started)
                cost = min(1 +  min_cost(ptr1+1,ptr2,s,t,n,m,starting_index,endind_index,started) , 1 + min_cost(ptr1+1,ptr2+1,s,t,n,m,starting_index,endind_index,1)) ;
                else
                {
                        cost = min(  min_cost(ptr1+1,ptr2,s,t,n,m,starting_index,endind_index,started) , 1 + min_cost(ptr1+1,ptr2+1,s,t,n,m,starting_index,endind_index,1)) ;
                }
                

        }
        else
        {       
                
                cost = min_cost(ptr1+1,ptr2,s,t,n,m,starting_index,endind_index);
        }

        return cost;
        


}
int main()
{       
        string s;
        string t;
        cin>>s>>t;
        if(s== t)
        {
                cout<<0<<endl;
                exit(0);
        }
        else
        {
                int n = s.size();
                int m = t.size();
                int starting_index = 0;
                int ending_index = n  - 1;
                int ans = min_cost(0,0,s,t,n,m,starting_index,ending_index);
                cout<<ans<<" "<<starting_index<<" "<<ending_index<<endl;;
        }
        


        return 0;
}