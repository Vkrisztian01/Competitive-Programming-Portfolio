// Name of the Problem: Necessary Cities
// Link to the Problem: https://cses.fi/problemset/task/2077
// Link to the Solution: https://cses.fi/paste/1fc83022e24bf2bc80393d/

#include <iostream>
#include<vector>
#include<algorithm>
#include<set>
 
using namespace std;
 
 
int n,m,a,b,t;
vector<vector<int> > g;
vector<bool>jarte;
vector<int>tin;
vector<int>low;
set<int>nodes;
 
void dfs(int vertex,int parent)
{
    jarte[vertex]=true;
    tin[vertex]=low[vertex]=t++;
    int db=0;
    for(auto to:g[vertex])
    {
        if(to==parent) continue;
        if(jarte[to])
        {
            low[vertex]=min(low[vertex],tin[to]);
            continue;
        }
        ++db;
        dfs(to,vertex);
        low[vertex]=min(low[vertex],low[to]);
        if(parent && low[to]>=tin[vertex])
        {
            nodes.insert(vertex);
        }
    }
    if(!parent && db>1)
    {
        nodes.insert(vertex);
    }
}
 
void get_points()
{
    jarte.assign(n+1,false);
    tin.assign(n+1,-1);
    low.assign(n+1,-1);
    t=0;
    for(int i=1;i<=n;i++)
    {
        if(jarte[i]) continue;
        dfs(i,0);
    }
}
 
int main()
{
    cin>>n>>m;
    g.resize(n+1);
    while(m--)
    {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    get_points();
    cout<<nodes.size()<<endl;
    for(auto x:nodes) cout<<x<<" ";
    return 0;
}
