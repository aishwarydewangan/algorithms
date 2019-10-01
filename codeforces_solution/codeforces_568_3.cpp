#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{       

        int n;
        int m;
        cin>>n>>m;
        vector<int> nums(n);
        int cumsum = 0 ;
        priority_queue<int> pq;
        for(int i = 0 ; i <n;i++)
        {
                cin>>nums[i];
        }
        for(int i = 0 ; i < n ; i++)
        {
                cumsum += nums[i];
                if(cumsum <= m)
                {
                        cout<<0<<" ";
                }
                else
                {
                        vector<int> temp;
                        for(int j = 0 ; j < i;j++)
                        {
                                temp.push_back(nums[j]);
                        }
                        sort(temp.begin(),temp.end());
                        int reqsum  = cumsum - m;
                        int p2 = temp.size()-1;
                        int count  = 0;
                        while(reqsum > 0 && p2 >=0)
                        {
                                count+=1;
                                reqsum -= temp[p2];
                                p2-=1;
                        }
                        cout<<count<<" ";
                }
                
        }
        //cout<<endl;
        return 0;
}