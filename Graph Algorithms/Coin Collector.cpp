// Problem Name: Coin Collector
// Link to the Problem: https://cses.fi/problemset/task/1686
// Link to the Solution: https://cses.fi/paste/0b41ea56646f805f951076/

#include <iostream>
#include<bits/stdc++.h>
typedef long long ll; using ll = long long;
 
using namespace std;
 
int n,m,cnt;
ll ans;
vector<ll> weight;
vector<vector<int> > adj;
vector<vector<int> > revadj;
vector<int> scc;
vector<ll> sccsize;
vector<bool> visited;
stack<int> order;
vector<vector<int> > dag;
vector<int> d;
vector<ll> dp;
 
void dfs1(int v)
{
    visited[v]=true;
    for(int to:adj[v]) if(!visited[to]) dfs1(to);
    order.push(v);
}
 
void dfs2(int v)
{
    visited[v]=true;
    sccsize.back()+=weight[v];
    scc[v]=cnt;
    for(int from:revadj[v]) if(!visited[from]) dfs2(from);
}
 
void dfs3(int v,ll adding)
{
    --d[v]; dp[v]=max(dp[v],sccsize[v] + adding); ans=max(ans,dp[v]);
    if(d[v]) return;
    visited[v]=true;
    for(int to:dag[v]) dfs3(to,dp[v]);
}
 
int main()
{
    cin>>n>>m; cnt=0; ans=0;
    adj.resize(n+1); revadj.resize(n+1); weight.resize(n+1); scc.resize(n+1); sccsize={0}; visited.assign(n+1,false);
    for(int v=1;v<=n;v++) cin>>weight[v];
    for(int i=1;i<=m;i++)
    {
        int a,b; cin>>a>>b;
        adj[a].push_back(b); revadj[b].push_back(a);
    }
    for(int v=1;v<=n;v++)
    {
        if(!visited[v]) dfs1(v);
    }
    visited.assign(n+1,false);
    while(!order.empty())
    {
        int v=order.top(); order.pop();
        if(!visited[v])
        {
            cnt++;
            sccsize.push_back(0);
            dfs2(v);
        }
    }
    dag.resize(cnt+1);
    d.assign(cnt+1,0);
    visited.assign(cnt+1,false);
    dp.assign(cnt+1,0);
    for(int v=1;v<=n;v++)
    {
        for(int to:adj[v])
        {
            if(scc[v]==scc[to]) continue;
            else d[scc[to]]++; dag[scc[v]].push_back(scc[to]);
        }
    }
    for(int v=1;v<=cnt;v++)
    {
        if(d[v]==0 && !visited[v])
        {
            d[v]=1; dfs3(v,0);
        }
    }
    cout<<ans;
    return 0;
}
