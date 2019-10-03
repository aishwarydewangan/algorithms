#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{       
      int q;
      cin>>q;
      while(q--)
      { 
              // cout<<endl;
              int n;
              cin>>n;
              vector<int> arr(4*n);
              int flag = 0;
            //  ll total_product = 1;
              unordered_map<int,int> um;
              for(int i = 0 ; i <  4*n ; i++) 
              {
                      cin>>arr[i];
                      if(i!=0) if(arr[i] != arr[i-1]) flag  = 1;
                      um[arr[i]]++;
              }
              if(!flag || n==1)
              {
                      cout<<"YES"<<endl;
                      continue;
              }

              sort(arr.begin(),arr.end());
              int i = 0; 
              int j = 4*n -1;
              ll curr_product = - 1;
              ll temp = curr_product;
              while(i<j) 
              { 
                        curr_product =      arr[i]*arr[j];
                        if(i == 0)
                        {       
                                temp = curr_product;
                                i+=2;
                                j-=2;
                        }
                        else
                        {
                                if(curr_product == temp && arr[i]==arr[i+1] && arr[j] == arr[j-1])
                                {
                                        i += 2;
                                        j-=2;
                                }
                                else
                                {
                                        cout<<"NO"<<endl;
                                        flag  = 0;
                                        break;
                                }
                                
                        }

              }
              if(!flag) continue;
               cout<<"YES"<<endl;
             


              
              
      }
      exit(0);
      return 0;

}