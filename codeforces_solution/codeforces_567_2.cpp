#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{       
        ll n;
        cin>>n;
        ll k;
        cin>>k;        
        map< ll ,ll > ul;
        ll med = (n-1)/2  ;
       // cout<<n<<" "<<k<<" "<<med;
        ll temp;
        for(int i = 0 ; i < n ; i++)
        {
                cin>>temp;
                ul[temp]++;       
        }
        ll i = 0 ;
        auto it = ul.begin();
        if(n == 1)
        {
                cout<<it->first+k<<endl;
                exit(0);
        }

        while(i!=med)
        {       
                i+= it->second;
                if(i<=med)
                        it++;
                else
                {       
                        //cout<<it->second<< " " << med << " "<<i<<endl;
                        it->second = it->second - abs(med -  ( i - it->second ));
                        break;
                }
                
                
        }
        ll currans = it->first;
      //  cout<<currans<<" "<<it->second<<endl;
        while(it!=ul.end())
        {       
              //  cout<<currans<<endl;
                auto next = it;
                next++;
                if(next!=ul.end())
                {
                        ll cost = (next->first - it->first)*it->second;
                        if(k >= cost)
                        {
                                currans = next->first;
                                k-= cost;
                        } 
                        else
                        {       
                                currans = it->first + k/it->second;
                                break;
                        }
                        
                        next->second += it->second;
                        it++;
                }
                else
                {
                        ll inc = k/it->second;
                       // cout<<inc<<" "<<k<<" "<<it->second<<endl;
                        currans = it->first+inc;
                        it++;
                }
             //   cout<<currans<<endl;
                
        }
        cout<<currans<<endl;
        return 0;
}