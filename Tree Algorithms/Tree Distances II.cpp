// Problem Name: Tree Distances II
// Link to the Problem: https://cses.fi/problemset/task/1133
// Link to the Solution: https://cses.fi/paste/a7c26d4c739ca3229c3f1c/

#include <iostream>
#include<bits/stdc++.h>
typedef long long ll; using ll = long long;
 
using namespace std;
 
void dfs1(int v,int p,vector<vector<int> > &adj,vector<ll> &dsum,vector<ll> &cnt)
{
    for(int to:adj[v])
    {
        if(to==p) continue;
        dfs1(to,v,adj,dsum,cnt);
        cnt[v]+=cnt[to];
        dsum[v]+=dsum[to]+cnt[to];
    }
}
 
void dfs2(int v,int p,int n,vector<vector<int> > &adj,vector<ll> &cnt,vector<ll> &ans)
{
    ans[v]=ans[p]-cnt[v];
    ans[v]+=n-cnt[v];
    for(int to:adj[v])
    {
        if(to==p) continue;
        dfs2(to,v,n,adj,cnt,ans);
    }
}
 
int main()
{
    int n; cin>>n;
    vector<vector<int> > adj(n+1);
    vector<ll> dsum(n+1,0);
    vector<ll> cnt(n+1,1);
    vector<ll> ans(n+1,0);
    for(int i=1;i<n;i++)
    {
        int a,b; cin>>a>>b;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    dfs1(1,-1,adj,dsum,cnt);
    ans[1]=dsum[1];
    for(int to:adj[1]) dfs2(to,1,n,adj,cnt,ans);
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    return 0;
}
