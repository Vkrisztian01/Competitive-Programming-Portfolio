// Problem Name: Planets Cycles
// Link to the Problem: https://cses.fi/problemset/task/1751
// Link to the Solution: https://cses.fi/paste/8d67f6c2f81c866b94fb1a/

#include <iostream>
#include<bits/stdc++.h>
typedef long long ll; using ll = long long;
 
using namespace std;
 
int n,cnt;
vector<int> adj;
vector<vector<int> > rev;
vector<int> c;
vector<int> cs;
vector<int> d;
vector<int> depth;
vector<int> h;
 
void dfs1(int v)
{
    --d[v];
    if(d[v]) return;
    c[v]=0;
    dfs1(adj[v]);
}
 
void dfs2(int v,int de,int e)
{
    h[v]=e;
    depth[v]=de;
    for(int from:rev[v]) dfs2(from,de+1,e);
}
 
void dfs3(int v)
{
    if(c[v]!=-1) return;
    c[v]=cnt;
    cs.back()++;
    dfs3(adj[v]);
}
 
int main()
{
    cin>>n; cnt=0;
    adj.resize(n+1);rev.resize(n+1);c.assign(n+1,-1); d.assign(n+1,0); cs={0}; depth.resize(n+1); h.resize(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>adj[i];
        d[adj[i]]++; rev[adj[i]].push_back(i);
    }
    for(int v=1;v<=n;v++)
    {
        if(d[v]==0 && c[v]==-1)
        {
            d[v]=1; dfs1(v);
        }
    }
    for(int v=1;v<=n;v++) if(c[v]==0 && c[adj[v]]==-1) dfs2(v,1,adj[v]);
    for(int v=1;v<=n;v++)
    {
        if(c[v]==-1)
        {
            cnt++;
            cs.push_back(0);
            dfs3(v);
        }
    }
    for(int v=1;v<=n;v++)
    {
        if(c[v]!=0) cout<<cs[c[v]]<<" ";
        else cout<<depth[v] + cs[c[h[v]]]<<" ";
    }
    return 0;
}
