// Problem Name: Counting Paths
// Link to the Problem: https://cses.fi/problemset/task/1136
// Link to the Solution: https://cses.fi/paste/db1ffbe70a6fac5d9c45e5/

#include <iostream>
#include<bits/stdc++.h>
 
using namespace std;
 
void dfs(int v,int p,vector<vector<int> > &adj,vector<vector<int> > &h,vector<int> &d)
{
    for(int to:adj[v])
    {
        if(to==p) continue;
        h[0][to]=v;
        d[to]=d[v]+1;
        dfs(to,v,adj,h,d);
    }
}
 
int lca(int a,int b,vector<vector<int> > &h,vector<int> &d)
{
    int k=d[b]-d[a];
    for(int i=19;i>=0;i--)
    {
        if((k & (1<<i))) b=h[i][b];
    }
    if(a==b) return a;
    for(int i=19;i>=0;i--)
    {
        if(h[i][a]!=h[i][b])
        {
            a=h[i][a];
            b=h[i][b];
        }
    }
    return h[0][a];
}
 
void dfs2(int v,vector<vector<int> > &adj,vector<int> &l,vector<int> &active,vector<int> &ending,vector<int> &dp)
{
    l[v]--;
    if(l[v]>1 || v==1) return;
    l[v]=0;
    dp[v]+=active[v];
    active[v]-=ending[v];
    for(int to:adj[v])
    {
        if(l[to])
        {
            active[to]+=active[v];
            dfs2(to,adj,l,active,ending,dp);
            break;
        }
    }
 
}
 
int main()
{
    int n,m; cin>>n>>m;
    vector<vector<int> > adj(n+1); vector<vector<int> > h(20,vector<int>(n+1,0)); vector<int> dp(n+1,0);
    vector<int> d(n+1,0); vector<int> l(n+1,0); vector<int> active(n+1,0); vector<int> ending(n+1,0);
 
    h[0][0]=0; h[0][1]=0;
    for(int i=1;i<n;i++)
    {
        int u,v; cin>>u>>v;
        adj[u].push_back(v); adj[v].push_back(u);
        l[u]++; l[v]++;
    }
    dfs(1,0,adj,h,d);
    for(int i=1;i<=19;i++)
    {
        for(int j=0;j<=n;j++)
        {
            h[i][j]=h[i-1][h[i-1][j]];
        }
    }
    while(m--)
    {
        int a,b; cin>>a>>b;
        if(d[a]>d[b]) swap(a,b);
        int c=lca(a,b,h,d);
        if(a==c) {active[b]++; ending[a]++; continue; }
        active[a]++; active[b]++; ending[c]+=2; dp[c]--;
    }
    if(n==1)
    {
        cout<<active[1];
        return 0;
    }
    for(int i=2;i<=n;i++)
    {
        if(l[i]==1) dfs2(i,adj,l,active,ending,dp);
    }
    dp[1]+=active[1];
    for(int i=1;i<=n;i++) cout<<dp[i]<<" ";
    return 0;
}
