// Problem Name: Apartments
// Link to the Problem: https://cses.fi/problemset/task/1084
// Link to the Solution: https://cses.fi/paste/7723787ff8da5986605a52/

#include <iostream>
#include<algorithm>
#include<vector>
#include<queue>
 
using namespace std;
 
int main()
{
    long long int n,m,k,db=0;
    cin>>n>>m>>k;
    priority_queue<long long int>rooms;
    priority_queue<long long int>people;
    while(n)
    {
        --n;
        long long int x;
        cin>>x;
        people.push(x);
    }
    while(m)
    {
        --m;
        long long int x;
        cin>>x;
        rooms.push(x);
    }
 
    while(!rooms.empty() && !people.empty())
    {
        long long int szoba=rooms.top();
        long long int ember=people.top();
        if(ember-k>szoba) people.pop();
        else if(ember+k<szoba) rooms.pop();
        else
        {
            db++;
            rooms.pop();
            people.pop();
        }
    }
 
    cout<<db;
 
    return 0;
}
