#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main()
{       

        int q;
        cin>>q;
        while(q--)
        {
                ll k,n,a,b;
                cin>>k>>n>>a>>b;
                if(b*n >=  k)
                {
                        cout<<-1<<endl;
                        continue;
                }
                if(n*a < k)
                {
                        cout<<n<<endl;
                        continue;
                }
                ll ans;
                ll num = k - b*n;
                ll deno = a-b;
                ll division = num/deno;
                if(division < 0)
                {
                        cout<<-1<<endl;
                }
                else
                {
                        if(num%deno == 0)
                        {
                                cout<<min(n,division-1)<<endl;
                        }
                        else
                        {
                                cout<<min(n,division)<<endl;
                        }
                        
                }
                
        }
        exit(0);
        return 0 ;

}