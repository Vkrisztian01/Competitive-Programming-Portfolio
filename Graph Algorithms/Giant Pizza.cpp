// Problem Name: Giant Pizza
// Link to the Problem: https://cses.fi/problemset/task/1684
// Link to the Solution: https://cses.fi/paste/9fc965c4147e6427950c45/

#include <iostream>0
#include<bits/stdc++.h>
typedef long long ll; using ll = long long;
 
using namespace std;
 
struct edge {int to;bool w;};
 
int n,m;
bool fail;
vector<bool> state;
vector<bool> visited;
vector<vector<edge> > adj1;
vector<vector<edge> > adj2;
set<pair<int,int> > edges;
 
void dfs(int v,bool s)
{
    if(visited[v])
    {
        if(state[v]!=s) fail=true;
        return;
    }
    visited[v]=true;
    state[v]=s;
    if(s) for(edge e:adj1[v]) dfs(e.to,e.w);
    else for(edge e:adj2[v]) dfs(e.to,e.w);
}
 
int main()
{
    cin>>n>>m; fail=false;
    state.resize(m+1); visited.assign(m+1,false); adj1.resize(m+1); adj2.resize(m+1);
    for(int i=1;i<=n;i++)
    {
        char a,b; int x,y; cin>>a>>x>>b>>y;
        if(a=='+' && b=='+') {adj2[x].push_back({y,true}); adj2[y].push_back({x,true}); edges.insert(make_pair(x,y));}
        if(a=='+' && b=='-') {adj2[x].push_back({y,false}); adj1[y].push_back({x,true});edges.insert(make_pair(x,-y));}
        if(a=='-' && b=='+') {adj1[x].push_back({y,true}); adj2[y].push_back({x,false});edges.insert(make_pair(-x,y));}
        if(a=='-' && b=='-') {adj1[x].push_back({y,false}); adj1[y].push_back({x,false});edges.insert(make_pair(-x,-y));}
    }
    pair<int,int> p2=make_pair(0,0);
    for(pair<int,int> p1:edges)
    {
        if(p2.first==0) p2=p1;
        else
        {
            if(p2.first==p1.first)
            {
                if(p2.first<0) dfs(p2.first*-1,false);
                else dfs(p2.first,true);
            }
            p2=p1;
        }
 
    }
 
 
 
 
 
    for(int v=1;v<=m;v++)
    {
        if(!visited[v]) dfs(v,true);
    }
    if(fail) cout<<"IMPOSSIBLE";
    else
    {
        for(int i=1;i<=m;i++)
        {
            if(state[i]) cout<<"+ ";
            else cout<<"- ";
        }
    }
    return 0;
}
