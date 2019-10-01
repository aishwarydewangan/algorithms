#include<bits/stdc++.h>
#define ll long long
using namespace std;
const long long MAX_SIZE = 2750131 + 1; 
vector<long long >isprime(MAX_SIZE , true); 
vector<long long >prime; 
vector<long long >SPF(MAX_SIZE); 
  
// function generate all prime number less then N in O(n) 
void manipulated_seive(int N) 
{ 
    // 0 and 1 are not prime 
    isprime[0] = isprime[1] = false ; 
  
    // Fill rest of the entries 
    for (long long int i=2; i<N ; i++) 
    { 
        // If isPrime[i] == True then i is 
        // prime number 
        if (isprime[i]) 
        { 
            // put i into prime[] vector 
            prime.push_back(i); 
  
            // A prime number is its own smallest 
            // prime factor 
            SPF[i] = i; 
        } 
  
        // Remove all multiples of  i*prime[j] which are 
        // not prime by making isPrime[i*prime[j]] = false 
        // and put smallest prime factor of i*Prime[j] as prime[j] 
        // [ for exp :let  i = 5 , j = 0 , prime[j] = 2 [ i*prime[j] = 10 ] 
        // so smallest prime factor of '10' is '2' that is prime[j] ] 
        // this loop run only one time for number which are not prime 
        for (long long int j=0; 
             j < (int)prime.size() && 
             i*prime[j] < N && prime[j] <= SPF[i]; 
             j++) 
        { 
            isprime[i*prime[j]]=false; 
  
            // put smallest prime factor of i*prime[j] 
            SPF[i*prime[j]] = prime[j] ; 
        } 
    } 
} 

ll find_greates_divisor(ll n)
{
        for(int i = 0 ; prime[i] <= n*n ; i++)
        {
                if(n%prime[i] == 0) return n/prime[i];
        }
        return -1;
}

int main()
{       
        manipulated_seive(2750132);
  //      cout<<"generated"<<endl;
        int n;
        cin>>n;
        vector<ll> primes;
        vector<ll> composites;
        vector<ll> all_nums(2*n);
        unordered_map<ll,ll> visible;
        for(int i =0  ; i < 2*n ; i++)
        {
                cin>>all_nums[i];
                visible[all_nums[i]] += 1;
                if(isprime[all_nums[i]]) primes.push_back(all_nums[i]);
                else composites.push_back(all_nums[i]); 
        }
        // cout<<"primes"<<endl;
        // for(auto x : primes)
        // {
        //         cout<<x<<" ";
        // }
        // cout<<endl;
        // cout<<"composites"<<endl;
        // for(auto x : composites)
        // {
        //         cout<<x<<" ";
        // }
        // cout<<endl;
        sort(composites.begin(),composites.end() , greater<ll>());
        sort(primes.begin(),primes.end());
        vector<ll> ans;
        ll gcd ;
        for(int i = 0 ; i < composites.size();i++)
        {       
                if(visible[composites[i]])
                {
               // cout<<"composite num"<<composites[i]<<endl;
                ans.push_back(composites[i]);
                gcd = find_greates_divisor(composites[i]);  
               // cout<<"gcd"<<gcd<<endl;             
                visible[gcd]-=1;
                visible[composites[i]] -= 1;
                }
        }
        ll next_prime;
        for(int i = 0 ; i <  primes.size() ; i++)
        {
                if(visible[primes[i]])
                {       
                        //cout<<prim
                     //   cout<<primes[i]<<"prime"<<endl;
                        ans.push_back(primes[i]);
                        next_prime = prime[primes[i]-1];
                     //   cout<<"next prime"<<next_prime<<endl;
                        visible[primes[i]] -= 1;
                        visible[next_prime] -= 1;
                }
        }
        for(auto x  : ans)
        {
                cout<<x<<" ";
        }
        cout<<endl;
        return 0;
}
