// Problem Name: Course Schedule
// Link to the Problem: https://cses.fi/problemset/task/1679
// Link to the Solution: https://cses.fi/paste/fd005679fd014c7694940d/

#include <iostream>
#include<bits/stdc++.h>
typedef long long ll; using ll = long long;
 
using namespace std;
 
int n,m;
vector<vector<int> > adj;
vector<int> d;
vector<bool> visited;
vector<int> ans;
 
void dfs(int v)
{
    --d[v];
    if(d[v] || visited[v]) return;
    ans.push_back(v);
    visited[v]=true;
    for(int to:adj[v]) dfs(to);
}
 
int main()
{
    cin>> n >> m;
    adj.resize(n+1); d.assign(n+1,0); ans = {}; visited.assign(n+1,false);
    for(int i=1;i<=m;i++)
    {
        int a,b; cin>> a >> b;
        adj[a].push_back(b); d[b]++;
    }
    for(int i=1;i<=n;i++) { ++d[i],dfs(i);};
    if(ans.size()!=n) cout<<"IMPOSSIBLE";
    else
    {
        for(int v: ans) cout<<v<<" ";
    }
    return 0;
}
