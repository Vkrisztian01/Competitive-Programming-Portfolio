// Problem Name: Game Routes
// Link to the Problem: https://cses.fi/problemset/task/1681
// Link to the Solution: https://cses.fi/paste/8828988ee420d2f89498fd/

#include <iostream>
#include<bits/stdc++.h>
typedef long long ll; using ll = long long;
#define k 1000000007
 
using namespace std;
 
ll n,m;
vector<vector<int> >adj;
vector<ll> ans;
vector<bool> visited;
 
void dfs(ll v)
{
    visited[v]=true;
    if(v==n) {ans[v]=1; return; }
    for(ll to: adj[v])
    {
        if(!visited[to]) dfs(to);
        ans[v]+=ans[to]; ans[v]%=k;
    }
}
 
int main()
{
    cin>>n>>m;
    adj.resize(n+1); ans.assign(n+1,0); visited.assign(n+1,false);
    for(ll i=1;i<=m;i++)
    {
        ll a,b; cin>>a>>b;
        adj[a].push_back(b);
    }
    dfs(1);
    cout<<ans[1];
    return 0;
}
