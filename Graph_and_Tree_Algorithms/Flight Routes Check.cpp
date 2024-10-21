// Problem Name: Flight Routes Check
// Link to the Problem: https://cses.fi/problemset/task/1682
// Link to the Solution: https://cses.fi/paste/0a503b2b11ef61c0950540/

#include <iostream>
#include<bits/stdc++.h>
typedef long long ll; using ll = long long;
 
using namespace std;
 
void dfs1(vector<vector<int> > &adj,vector<bool> &visited,stack<int> &order, int v)
{
    visited[v]=true;
    for(int to:adj[v]) if(!visited[to]) dfs1(adj,visited,order,to);
    order.push(v);
}
 
void dfs2(vector<vector<int> > &revadj,vector<bool> &visited,vector<int> &scc,int cnt,int v)
{
    visited[v]=true;
    scc[v]=cnt;
    for(int from:revadj[v])
    {
        if(!visited[from]) dfs2(revadj,visited,scc,cnt,from);
    }
}
 
int main()
{
    int n,m; cin>>n>>m; int cnt=0;
    vector<vector<int> > adj(n+1);vector<vector<int> > revadj(n+1); vector<bool> visited(n+1,false);stack<int> order; vector<int> scc(n+1); vector<int> ans;
    for(int i=1;i<=m;i++)
    {
        int a,b; cin>>a>>b;
        adj[a].push_back(b); revadj[b].push_back(a);
    }
    for(int v=1;v<=n;v++) {if(!visited[v]) dfs1(adj,visited,order,v);}
    visited.assign(n+1,false);
    while(!order.empty())
    {
        int v=order.top(); order.pop();
        if(visited[v]) continue;
        else
        {
            ans.push_back(v);
            dfs2(revadj,visited,scc,cnt,v);
            cnt++;
        }
    }
    if(cnt==1)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO"<<endl;
        cout<<ans[1]<<" "<<ans[0];
    }
    return 0;
}
