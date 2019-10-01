#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main()
{       



        int q;
        cin>>q;
        while(q--)
        {
                int n;
                cin>>n;
                vector<int> freqcount(n+1);
                int temp;
                for(int i = 0 ; i < n ; i++)
                {
                        cin>>temp;
                        freqcount[temp]+=1;
                }
                vector<int> freqind;
                for(int i  = 1 ; i <= n ; i++)
                {
                        if(freqcount[i]!=0)
                        {
                                freqind.push_back(freqcount[i]);
                        }
                }
                sort(freqind.begin(),freqind.end());
                if(n == 1)
                {
                        cout<<freqind[0]<<endl;
                        continue;
                }
                // for(auto x : freqind) 
                // cout<<x<<" ";
                // cout<<endl;
                int pt = freqind.size()-1;
                int gredsum = freqind[pt];
                freqind[pt]--;
                pt--;
               // cout<<"start gred sum"<<" "<<gredsum<<endl;
                while(pt>=0 && freqind[pt+1]>0)
                {       

                      //  cout<<pt<<" "<<freqind[pt+1]<<" "<<freqind[pt]<<endl;
                        
                        
                        int temp_sum =  min(freqind[pt],freqind[pt+1]) ;
                        gredsum += temp_sum;
                        freqind[pt]=temp_sum-1;
                        pt-=1;
                }
                cout<<gredsum<<endl;
        }      
        exit(0);
        return 0;
}