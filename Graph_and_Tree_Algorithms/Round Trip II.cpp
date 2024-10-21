// Problem Name: Round Trip II
// Link to the Problem: https://cses.fi/problemset/task/1678
// Link to the Solution: https://cses.fi/paste/396181cf8e40c3059493a5/

#include <iostream>
#include<bits/stdc++.h>
typedef long long ll; using ll = long long;
 
using namespace std;
 
ll n,m;
vector<vector<ll> > adj;
vector<bool> active;
vector<bool> visited;
vector<ll> ans;
stack<ll> akt;
 
void dfs(ll v)
{
    if(visited[v]) return;
    if(active[v])
    {
        ans.push_back(v);
        while(akt.top()!=v) {ans.push_back(akt.top()); akt.pop();}
        ans.push_back(v);
        akt.pop();
        return;
    }
    active[v]=true;
    akt.push(v);
    for(ll to:adj[v])
    {
        if(!ans.empty()) return;
        dfs(to);
    }
    active[v]=false;
    visited[v]=true;
    akt.pop();
}
 
int main()
{
    ll n,m; cin>>n>>m;
    adj.resize(n+1); active.assign(n+1,false); visited.assign(n+1,false);
    for(ll i=1;i<=m;i++)
    {
        ll a,b; cin>>a>>b;
        adj[a].push_back(b);
    }
    for(int i=1;i<=n;i++)
    {
        if(!visited[i] && ans.empty()) dfs(i);
    }
    if(ans.empty()) cout<<"IMPOSSIBLE";
    else
    {
        cout<<ans.size()<<endl;
        reverse(ans.begin(),ans.end());
        for(ll node: ans) cout<<node<<" ";
    }
    return 0;
}
