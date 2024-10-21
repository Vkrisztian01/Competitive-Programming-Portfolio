// Problem Name: Longest Flight Route
// Link to the Problem: https://cses.fi/problemset/task/1680
// Link to the Solution: https://cses.fi/paste/ecad137d89987425949536/

#include <iostream>
#include<bits/stdc++.h>
typedef long long ll; using ll = long long;
 
using namespace std;
 
ll n,m;
vector<vector<ll> > adj;
vector<ll> d;
vector<bool> visited;
vector<ll> cnt;
vector<ll> from;
 
void dfs1(ll v)
{
    --d[v];
    if(visited[v] || d[v] || v==1) return;
    visited[v]=true;
    for(ll to:adj[v]) dfs1(to);
}
 
void dfs2(ll v,ll parent)
{
    --d[v];
    if(cnt[v]<cnt[parent]+1)
    {
        cnt[v]=cnt[parent]+1;
        from[v]=parent;
    }
    if(d[v] || visited[v]) return;
    visited[v]=true;
    for(ll to:adj[v]) dfs2(to,v);
 
}
 
int main()
{
    cin>>n>>m;
    adj.resize(n+1); d.assign(n+1,0); visited.assign(n+1,false); cnt.assign(n+1,0);from.assign(n+1,0);
    for(ll i=1;i<=m;i++)
    {
        ll a,b; cin>>a>>b;
        adj[a].push_back(b); d[b]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(d[i]==0)
        {
            d[i]=1;
            dfs1(i);
        }
    }
    if(visited[n]) {cout<<"IMPOSSIBLE"; return 0; }
    d[1]=1;dfs2(1,1);
    if(cnt[n]==0) cout<<"IMPOSSIBLE";
    else
    {
        vector<int> ans;
        int curr=n;
        while(curr!=1)
        {
            ans.push_back(curr);
            curr=from[curr];
        }
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        cout<<ans.size()<<endl;
        for(ll v:ans) cout<<v<<" ";
    }
    return 0;
}
