#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{       
        int q;
        cin>>q;
        while(q--)
        {
                int n,m;
                cin>>n>>m;
                vector<int> row_white(n+1,0);
                vector<int> column_white(m+1,0);
                vector<vector<char> > arr(n , vector<char>(m,'.'));
                string s;
                for(int i = 0 ; i <  n ; i++)
                {       cin>>s;
                        for(int j = 0  ; j < m ; j++)
                        {
                            arr[i][j] = s[j];
                             if(arr[i][j] == '.')
                             {
                                     row_white[i]+=1;
                                     column_white[j]+=1;
                             }   
                        }
                }
                int minans = INT_MAX;
                for(int i = 0 ; i <  n ; i++)
                {
                        for(int j = 0  ; j < m ; j++)
                        {
                             
                             if(arr[i][j] == '.')
                             {
                                     minans = min(minans,row_white[i]+column_white[j]-1);
                             }   
                             else
                             {
                                     minans = min(minans,row_white[i]+column_white[j]);
                             }
                             
                        }
                }
                cout<<minans<<endl;

        }
        return 0;
}