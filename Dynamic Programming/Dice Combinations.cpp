// Problem Name: Dice Combinations
// Link to the Problem: https://cses.fi/problemset/task/1633
// Link to the Solution: https://cses.fi/paste/b6408d352772e61a6fefe4/

#include <iostream>
#include<queue>
 
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    deque<pair<int,long long int> > seged;
    seged.push_back(make_pair(0,1));
    seged.push_back(make_pair(1,1));
    seged.push_back(make_pair(2,2));
    seged.push_back(make_pair(3,4));
    seged.push_back(make_pair(4,8));
    seged.push_back(make_pair(5,16));
    if(n<6) cout<<seged[n].second;
    else
    {
        while(seged.back().first!=n)
        {
            seged.push_back(make_pair(seged.back().first+1,seged[0].second+seged[1].second+seged[2].second+seged[3].second+seged[4].second+seged[5].second  ));
            seged.back().second%=1000000007;
            seged.pop_front();
        }
        cout<<seged.back().second;
    }
    return 0;
