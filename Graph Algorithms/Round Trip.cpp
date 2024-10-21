// Problem Name: Round Trip
// Link to the Problem: https://cses.fi/problemset/task/1669
// Link to the Solution: https://cses.fi/paste/87330b7d47f51c1993e9a1/

#include <iostream>
#include<bits/stdc++.h>
 
using namespace std;
 
vector<vector<int> >g;
vector<int> cur;
vector<bool> visited;
bool possible;
 
void dfs(int vertex,int parent)
{
    if(visited[vertex])
    {
        vector<int> ans={};
        while(cur.back()!=vertex)
        {
            ans.push_back(cur.back());
            cur.pop_back();
        }
        ans.push_back(vertex); reverse(ans.begin(),ans.end());
        cur.pop_back();
        possible=true;
        cout<<ans.size()+1<<"\n";
        for(int node:ans) cout<<node<<" ";
        cout<<vertex;
        return;
    }
    visited[vertex]=true;
    cur.push_back(vertex);
    for(int to:g[vertex])
    {
        if(possible) return;
        if(to!=parent) dfs(to,vertex);
    }
    cur.pop_back();
}
 
int main()
{
    int n,m; cin>>n>>m; possible=false;
    g.resize(n+1); cur={};visited.assign(n+1,false);
    for(int i=1;i<=m;i++)
    {
        int a,b; cin>>a>>b;
        g[a].push_back(b); g[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
    {
        if(possible) return 0;
        if(!visited[i]) dfs(i,-1);
    }
    cout<<"IMPOSSIBLE";
    return 0;
}
