#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main()
{       
        int n;
        cin>>n;
        while(n--)
        {
                string s;
                string t;
                cin>>s;
                cin>>t;

                int size1 = s.size();
                int size2 = t.size();
                if(s[0] != t[0] || size1 > size2)
                {       
                        //cout<<"here1"<<endl;
                        cout<<"NO"<<endl;
                        continue;
                }
                if(s[size1 - 1] != t[size2-1])
                {       
                       // cout<<"here2"<<endl;
                        cout<<"NO"<<endl;
                        continue;
                }

                int p1 = 0;
                int p2 = 0;
                int flag = 1;
                while(p1 < size1 && p2 < size2)
                {       
                       // cout<<p1<<p2<<endl;
                        
                        if(s[p1] == t[p2])
                        {
                                p1+=1;
                                p2 += 1;
                        }
                        else if(t[p2] == s[p1-1])
                        {
                                p2 += 1;
                        }
                        else
                        {       
                                flag = 0;
                               // cout<<"here3"<<endl;
                                cout<<"NO"<<endl;
                                break;
                        }
                        
                }
                if(p1 != size1 && flag)
                {
                        cout<<"NO"<<endl;
                        continue;
                }
                if(!flag) continue;
                else
                {
                        if(p2 == size2)
                        {
                                cout<<"YES"<<endl;
                                continue;
                        }
                        else
                        {
                                while(p2<size2)
                                {
                                        if(t[p2] != s[size1-1])
                                        {       
                                                flag = 0;
                                                cout<<"NO"<<endl;
                                                break;
                                        }
                                        p2 += 1;
                                }
                        }

                        if(flag)
                        {
                                cout<<"YES"<<endl;
                                continue;
                        }
                        else
                        {
                                continue;
                        }
                        
                        
                }
                
        }
        return 0;
}