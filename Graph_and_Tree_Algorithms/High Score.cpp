// Problem Name: High Score
// Link to the Problem: https://cses.fi/problemset/task/1673
// Link to the Solution: https://cses.fi/paste/101707a37c5fc7ca93fb94/

#include <iostream>
#include<bits/stdc++.h>
typedef long long ll; using ll = long long;
#define INF LONG_MIN/2
using namespace std;
 
struct Edge {ll a,b,weight;};
 
void dfs(int vertex,vector<ll> &depth,vector<vector<ll> > &g)
{
    if(depth[vertex]==LONG_MAX) return;
    depth[vertex]=LONG_MAX;
    for(ll to:g[vertex]) dfs(to,depth,g);
}
 
int main()
{
    ll n,m; cin>>n>>m;
    vector<Edge> edges(m); vector<ll> depth(n+1,INF); depth[1]=0; vector<vector<ll> > g(n+1);
    for(int i=0;i<m;i++) {cin>>edges[i].a>>edges[i].b>>edges[i].weight; g[edges[i].a].push_back(edges[i].b); }
    for(int i=1;i<n;i++)
    {
        for(Edge e:edges)
        {
            if(depth[e.a]!=INF) depth[e.b]=max(depth[e.b],depth[e.a]+e.weight);
        }
    }
    vector<int>wn = {};
    for(Edge e:edges)
    {
        if(depth[e.a]!=INF && depth[e.b]<depth[e.a]+e.weight)
        {
            wn.push_back(e.b);
        }
    }
    for(int vertex:wn) dfs(vertex,depth,g);
    if(depth[n]==LONG_MAX) cout<<-1;
    else cout<<depth[n];
    return 0;
}
