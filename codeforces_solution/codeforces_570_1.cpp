#include<bits/stdc++.h>
#define ll long long
using namespace std;


int sum_of_digits(int n)
{
        int sum = 0 ;
        int rem = 0;
        while(n)
        {
                rem = n%10;
                sum += rem;
                n = n/10;
        }
        if(sum%4 == 0) return 1;
        else return 0;
}

int main()
{       
        int a;
        cin>>a;
        while(true)
        {
                if(sum_of_digits(a))
                        {
                                cout<<a<<endl;
                                exit(0);
                        }
                a+=1;
        }
        return 0;
}