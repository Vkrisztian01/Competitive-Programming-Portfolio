// Problem Name: Movie Festival
// Link to the Problem: https://cses.fi/problemset/task/1629
// Link to the Solution: https://cses.fi/paste/f3db05ee1e1d83ce607d71/

#include <iostream>
#include<set>
 
using namespace std;
 
int main()
{
    int db=0,n;
    cin>>n;
    set<pair<int,int> > seged;
    while(n)
    {
        --n;
        int a,b;
        cin>>a>>b;
        seged.insert(make_pair(b,a));
    }
    int k=0;
    for(auto x:seged)
    {
        if(x.second>=k)
        {
            k=x.first;
            db++;
        }
    }
    cout<<db;
    return 0;
}
