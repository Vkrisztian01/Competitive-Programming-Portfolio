// Problem Name: Restaurant Customers
// Link to the Problem: https://cses.fi/problemset/task/1619
// Link to the Solution: https://cses.fi/paste/1ee7e693ee1e3936607d3f/

#include <iostream>
#include<set>
#include<algorithm>
 
using namespace std;
 
int main()
{
    int n,db=0,maxdb=0;
    set<pair<int,int> > seged;
    cin>>n;
    while(n)
    {
        --n;
        int a,b;
        cin>>a>>b;
        seged.insert(make_pair(a,true));
        seged.insert(make_pair(b,false));
    }
    for(auto x:seged)
    {
        if(x.second)
        {
            db++;
            maxdb=max(maxdb,db);
        }
        else db--;
    }
 
    cout<<maxdb;
 
    return 0;
}
