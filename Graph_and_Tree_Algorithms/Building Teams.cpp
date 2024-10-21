// Problem Name: Building Teams
// Link to the Problem: https://cses.fi/problemset/task/1668/
// Link to the Solution: https://cses.fi/paste/c409e2409b71a66d93e901/

#include <iostream>
#include<bits/stdc++.h>
 
using namespace std;
 
vector<vector<int> > g;
vector<int>l;
bool possible;
 
void dfs(int vertex,int label)
{
    if(l[vertex])
    {
        if(l[vertex]!=label) possible=false;
        return;
    }
    l[vertex]=label;
    for(int to:g[vertex])
    {
        dfs(to,3-label);
        if(!possible) return;
    }
}
 
int main()
{
    int n,m; cin>>n>>m; possible=true;
    g.resize(n+1);
    l.assign(n+1,0);
    for(int i=1;i<=m;i++)
    {
        int a,b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
    {
        if(!possible) break;
        if(!l[i]) dfs(i,1);
    }
    if(!possible) cout<<"IMPOSSIBLE";
    else for(int i=1;i<=n;i++) cout<<l[i]<<" ";
    return 0;
}
