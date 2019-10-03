
#include<bits/stdc++.h>
using namespace std;

int find(int a,vector<int>& nums)
{
    while(a != nums[a])
    {
        nums[a] = nums[nums[a]];
        a = nums[a];
    }
    return nums[a];
}
void unite(int a , int b,vector<int>& nums,vector<int>& sizes)
{   
    
    int r1 = find(a,nums);
    int r2 = find(b,nums);
    if(r1 == r2)
    {
        return;
    }
  //  cout<<a<<" "<<b<<" "<<r1<<" "<<r2<<endl;
    if(sizes[r1] > sizes[r2])
    {
        nums[r2] = r1;
        sizes[r1] += sizes[r2];
    }
    else
    {
        nums[r1] = r2;
        sizes[r2] += sizes[r1];
    }
}
int main() {
    int n,m;
    cin>>n>>m;
    vector<int> nums(n+1);
    for(int i = 0 ; i < n+1 ; i++)
    {
        nums[i] = i;
    }
    vector<int> sizes(n+1,1);
    int num_of_m;
    vector<int> temp;
    int temp_no;
    for(int i = 0 ; i < m ; i++)
    {   
        vector<int> temp;
        cin>>num_of_m;
        for(int i = 0 ; i < num_of_m ; i++)
        {   
            cin>>temp_no;
            temp.push_back(temp_no);
        }
        for(int i = 0 ; i < num_of_m-1 ; i++)
        {   
            unite(temp[i],temp[i+1],nums,sizes);
        }
        // for(auto x : nums)
        // {
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        // for(auto x : sizes)
        // {
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        // cout<<endl;
        
    }
    

    
    for(int i = 1 ; i < n+1 ; i++)
    {
        int r = find(i,nums);
        cout<<sizes[r]<<" ";
    }
    //cout<<endl;
    
	return 0;
}
