#include<bits/stdc++.h>
using namespace std;
int main()
{

        int n;
        cin>>n;
        vector<int> hands(n);
        vector<int> pile(n);
        deque<int> trial_q;
        priority_queue<int , vector<int> , greater<int> >  pq;
        int max_v = INT_MIN;
        int min_card ;
        int new_card;
        for(int i = 0 ; i < n ; i++)
        {
                cin>>hands[i];
                if(hands[i] != 0) pq.push(hands[i]);
                
        }

        for(int j =  0 ; j < n ; j++)
        {
                cin>>pile[j];
               // cout<<pile[j]<<endl;
                trial_q.push_back(pile[j]);
              //  cout<<"front"<<trial_q.front()<<endl;
                if(pile[j] != 0)
                {
                        max_v = max(max_v, j - pile[j] + 2 );
                }
        }
        int trial_count = 0;
        while(true)
        {
                if(pq.empty()) break;
                new_card = trial_q.front();
                trial_q.pop_front();
                
                min_card = pq.top();
               // cout<<"new_card: "<<new_card<<" mincard"<<min_card<<endl;
                //break;
                trial_q.push_back(min_card);
                pq.pop();
                if(new_card != 0 )
                        pq.push(new_card);
                trial_count += 1;
                
        }
        int l = 0;
        int flag = 1;
        for(auto it = trial_q.begin() ; it != trial_q.end() ; it++)
        {
                if(*it != l+1)
                {       
                        flag = 0 ;
                        break;
                }
                else
                {
                        l = *it;
                }
                
        }
        if(flag) cout<<trial_count<<endl;
        else cout<<max_v+n<<endl;
        //cout<< (max_v+n)<<endl;


        return 0;
}