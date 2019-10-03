#include<bits/stdc++.h>
using namespace std;
int main()
{       


        long long t;
        cin>>t;
        while(t--)
        {
                long long n;
                long long k;
                cin>>n>>k;
                long long no_steps = 0;
                while(n)
                {       
                        //cout<<n<<endl;
                        no_steps += n%k;
                        n = n/k;
                        if(n != 0)
                                no_steps += 1;
                }
                cout<<no_steps<<endl;
        }
        return 0;       
}