#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool check_sequence(string &s , string &t)
{
        int i = 0;
        int j = 0;
        while(i<s.size() && j<t.size())
        {
                if(s[i] == t[j])
                {
                        i++;
                }
                j++;
        }
        if(i == s.size())
        {
                return true;
        }
        return false;
}
bool check_freq(string&s, string&t, string &p)
{
        vector<int> requirement(27 ,0);
        vector<int> resource(27,0);
        vector<int> given(27,0);
        for(auto x : s)
        {
                given[(int)(x - 'a')]+=1;
        }
        for(auto x :t)
        {
                int charnum = (int)(x-'a');
                requirement[charnum]+=1;
        }
        for(auto x : p)
        {
                int charnum = (int)(x-'a');
                resource[charnum]+=1;
        }
        for(int i = 0 ; i < 27 ; i++)
        {
                if ( (requirement[i] - given[i] ) > resource[i])
                        return false;
        }
        return true;

}
int main()
{       int q;
        cin>>q;
        while(q--)
        {
                string s,t,p;
                cin>>s>>t>>p;
                if(check_sequence(s,t)== false)
                {
                        cout<<"NO"<<endl;
                        continue;
                }
                if(check_freq(s,t,p)==true)
                {
                        cout<<"YES"<<endl;
                }
                else
                {
                        cout<<"NO"<<endl;
                }
                


        }
        exit(0);
        return 0;
}