#include<bits/stdc++.h>
#define ll long long
using namespace std;



void dfs(int n , vector<int>& visited , vector<int>& coloured , vector<int> gra[] )
{       
        //cout<<n<<endl;
        visited[n] = 1;
        for( int i = 0 ; i < gra[n].size() ; i++)
        {
                if(visited[gra[n][i]] == 1) continue;
                else
                {
                        if(coloured[gra[n][i]] == -1)
                        {
                                coloured[gra[n][i]] = coloured[n]?0:1;
                                dfs(gra[n][i],visited,coloured,gra);
                        }
                }
                
        }
}
int main()
{       
        int t;
        cin>>t;
        while(t--)
        {
                int n,m;
                cin>>n>>m;
                vector<int> gra[n+1];
               // map<ll,vector<ll>, greater<ll>> map;

                int a,b;
             //   ll max_indegree = INT_MIN;
                for(int i = 0 ; i < m ; i++)
                {
                        cin>>a>>b;
                        gra[a].push_back(b);
                        gra[b].push_back(a);
                        // indegree[a] += 1;
                        // indegree[b]+= 1;
                       // max_indegree = max(max_indegree,indegree[a]);
                        //max_indegree = max(max_indegree,indegree[b]);
                }

                vector<int> visited(n+1,0);
                vector<int> coloured(n+1,-1);
               // coloured[1] = 0;
                for(int i = 1 ; i<= n;i++)
                {       
                       // cout<<"dfs of started : "<<i<<endl;
                        if(coloured[i] == -1) coloured[i] = 0;
                        dfs(i,visited,coloured,gra);
                       // cout<<"dfs of ended : "<<i<<endl;
                }
                vector<int> c1;
                vector<int> c2;
                for(int i = 1; i <= n ;i++)
                {
                        if (coloured[i] == 1)
                        {
                                c1.push_back(i);
                        }
                        if(coloured[i] == 0)
                        {
                                c2.push_back(i);
                        }
                        
                }
               // cout<<c1.size()<<c2.size()<<endl;
                if(c1.size() < c2.size())
                {       
                        cout<<c1.size()<<endl;
                        for(auto x : c1) cout<<x<<" ";
                }
                else
                {
                        cout<<c2.size()<<endl;
                        for(auto x : c2) cout<<x<<" ";                       
                }
                cout<<endl;
                
        }
        return  0 ;
}