// Problem Name: Distance Queries
// Link to the Problem: https://cses.fi/problemset/task/1135
// Link to the Solution: https://cses.fi/paste/939450db7c47fd9e9c41d8/

#include <iostream>
#include<bits/stdc++.h>
 
using namespace std;
 
void dfs(int v,int p,vector<vector<int> > &adj,vector<int> &d,vector<vector<int> > &h)
{
    h[0][v]=p;
    for(int to:adj[v])
    {
        if(to==p) continue;
        d[to]=d[v]+1;
        dfs(to,v,adj,d,h);
    }
}
 
int main()
{
    int n,q; cin>>n>>q;
    vector<vector<int> > adj(n+1); vector<int> d(n+1,0); vector<vector<int> > h(20,vector<int>(n+1,0));
    for(int i=1;i<n;i++)
    {
        int u,v; cin>>u>>v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    dfs(1,0,adj,d,h);
    for(int i=1;i<=19;i++)
    {
        for(int j=0;j<=n;j++)
        {
            h[i][j]=h[i-1][h[i-1][j]];
        }
    }
    while(q--)
    {
        int a,b; cin>>a>>b;
        if(d[a]>d[b]) swap(a,b);
        int e=a; int f=b;
        int k=d[b]-d[a];
        for(int i=19;i>=0;i--)
        {
            if((k &(1<<i))) b=h[i][b];
        }
        if(b==a) {cout<<d[f]-d[e]<<"\n"; continue; }
        for(int i=19;i>=0;i--)
        {
            if(h[i][a]!=h[i][b])
            {
                a=h[i][a]; b=h[i][b];
            }
        }
        a=h[0][a]; b=h[0][b];
        cout<<d[e]-d[a] + d[f]-d[a]<<"\n";
    }
    return 0;
}
