// Problem Name: Tree Diameter
// Link to the Problem: https://cses.fi/problemset/task/1131
// Link to the Solution: https://cses.fi/paste/faeb166d8fb099919c3cb4/

#include <iostream>
#include<bits/stdc++.h>
 
using namespace std;
 
pair<int,int> dfs(int v,int p,vector<vector<int> > &adj)
{
    pair<int,int> ans={v,0};
    for(int to:adj[v])
    {
        if(to==p) continue;
        pair<int,int> r = dfs(to,v,adj);
        r.second++;
        if(r.second>ans.second) ans=r;
    }
    return ans;
}
 
int main()
{
    int n; cin>>n;
    vector<vector<int> > adj(n+1);
    for(int i=1;i<n;i++)
    {
        int u,v; cin>>u>>v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    pair<int,int> first=dfs(1,-1,adj);
    pair<int,int> second=dfs(first.first,-1,adj);
    cout<<second.second;
    return 0;
}
