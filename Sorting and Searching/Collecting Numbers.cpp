// Problem Name: Collecting Numbers
// Link to the Problem: https://cses.fi/problemset/task/2216/
// Link to the Solution: https://cses.fi/paste/a8fae1d0626d0807612e7d/

#include <iostream>
#include<vector>
#include<set>
#include<map>
 
using namespace std;
 
int main()
{
    int n,db=1,k=200001,elozo=-1;
    cin>>n;
    map<int,int> seged;
    seged.insert(make_pair(0,-1));
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        seged[a]=i;
        if(seged[a-1]==0) db++;
    }
    cout<<db;
    return 0;
}
