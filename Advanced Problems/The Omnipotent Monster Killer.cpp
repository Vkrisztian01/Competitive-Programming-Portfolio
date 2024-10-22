// Name of the Problem: The Omnipotent Monster Killer
// Link to the Problem: https://codeforces.com/problemset/problem/1988/D
// Link to the Solution: https://codeforces.com/contest/1988/submission/270866877

#include <iostream>
#include<bits/stdc++.h>
typedef long long ll; using ll = long long;

using namespace std;

int n;
vector<vector<int> > adj;
vector<ll> a;
vector<vector<ll> > dp;
vector<bool> visited;
vector<vector<ll> > dpfront;
vector<vector<ll> > dpback;

void dfs(int v)
{
    visited[v]=true;
    for(int i=1;i<=19;i++) dp[i][v]=i*a[v];
    for(int to:adj[v])
    {
        if(visited[to]) continue;
        dfs(to);
        for(int i=1;i<=19;i++) dpfront[i][to]=min(dpfront[i-1][to],dp[i][to]);
        for(int i=19;i>=1;i--) dpback[i][to]=min(dpback[i+1][to],dp[i][to]);
        for(int i=1;i<=19;i++) dp[i][v]+=min(dpfront[i-1][to],dpback[i+1][to]);
    }
}

void solve()
{
    int n; cin>>n;
    adj.clear(); adj.resize(n); a.resize(n); dp.assign(20,vector<ll>(n,0)); visited.assign(n,false);
    dpfront.assign(21,vector<ll>(n,1e18)); dpback.assign(21,vector<ll>(n,1e18));
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=1;i<n;i++)
    {
        int a,b; cin>>a>>b; --a; --b;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    dfs(0);
    ll ans=1e18;
    for(int i=1;i<=19;i++) ans=min(ans,dp[i][0]);
    cout<<ans<<"\n";
}

int main()
{
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
