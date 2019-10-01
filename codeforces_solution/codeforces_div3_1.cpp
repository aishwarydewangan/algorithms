#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll moves(ll n)
{
        ll move = 0;
        int flag = 0 ;
        while(true)
        {       
                flag  = 0;
                if(n == 1)
                {
                        return move;
                }
                if(n%2 == 0)
                {       
                        flag = 1;
                        n = n/2;
                        move += 1;
                        continue;
                }
                if(n%3 == 0)
                {       
                        flag = 1;
                        n = (2*n)/3;
                        move+= 1;
                        continue;
                }
                if(n%5 == 0)
                {       
                        flag = 1;
                        n = (4*n)/5;
                        move+=1;
                        continue;
                }
                if(!flag)
                {
                        return -1;
                }
        }
}
int main()
{       

        int q;
        cin>>q;
        while(q--)
        {
                ll n;
                cin>>n;
                cout<<moves(n)<<endl;
                
        }
        return 0;
}