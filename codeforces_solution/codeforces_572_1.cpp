#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{       
        int n;
        cin>>n;
        string s;
        cin>>s;
        int count0 = 0;
        int count1 = 0;
        if(n == 1)
        {
                cout<<1<<endl;
                cout<<s<<endl;
        }
        else
        {
                for(auto x : s)
                {
                        if(x == '0')count0+=1;
                        else count1 +=1;
                }
                if(count0 != count1)
                {
                        cout<<1<<endl;
                        cout<<s<<endl;
                }
                else
                {
                        cout<<2<<endl;
                        cout<<s[0]<<" "<<s.substr(1)<<endl;
                }
                
        }
        exit(0);
        return 0;
}