#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{       

        int t;
        cin>>t;
        while(t--)
        {
                int chip_position,k;
                cin>>chip_position>>k;
                int turn = 0;
                if(chip_position <= 0)
                {
                        cout<<"Bob"<<endl;
                        continue;
                }
                if(chip_position > 0 && chip_position<=2)
                {
                        cout<<"Alice"<<endl;
                        continue;
                }
                if(chip_position <=k)
                {
                        if( k > chip_position)
                        {
                                if(chip_position%2 == 0)
                                {
                                        cout<<"Alice"<<endl;
                                        continue;
                                }
                                else
                                {
                                        cout<<"Bob"<<endl;
                                        continue;
                                }
                                
                        }
                         if(k == chip_position)
                        {
                                cout<<"Alice"<<endl;
                                continue;
                        }
                }
                else
                {       
                        
                        int oneturns = chip_position - k  ;
                        if(oneturns%2 == 0)
                        {
                                cout<<"Alice"<<endl;
                                continue;
                        }
                        else
                        {
                                cout<<"Bob"<<endl;
                                continue;
                        }
                        
                }
                        
                }
        exit(0);
        return 0;

        }
        
