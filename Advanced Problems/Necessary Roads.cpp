// Name of the Problem: Necessary Roads
// Link to the Problem: https://cses.fi/problemset/task/2076
// Link to the Solution: https://cses.fi/paste/c18601ed3c5c80f08038aa/

#include <iostream>
#include<vector>
#include<algorithm>
#include<set>
 
using namespace std;
 
int n,m,a,b,t;
vector<vector<int> > g;
vector<int>visited;
vector<int>tin;
vector<int>low;
set<pair<int,int> > bridges;
 
void dfs(int vertex,int parent)
{
    visited[vertex]=true;
    tin[vertex]=t++;
    low[vertex]=t;
    int db=0;
    for(auto ba:g[vertex])
    {
        if(ba==parent) continue;
        if(visited[ba])
        {
            low[vertex]=min(low[vertex],tin[ba]);
            continue;
        }
        ++db;
        dfs(ba,vertex);
        low[vertex]=min(low[vertex],low[ba]);
        if(tin[vertex]<low[ba]) bridges.insert(make_pair(vertex,ba));
    }
    if(!parent && db>1)
    {
        for(auto ba:g[vertex]) bridges.insert(make_pair(vertex,ba));
    }
}
 
void find_bridges()
{
    t=0;
    visited.assign(n+1,false);
    tin.assign(n+1,-1);
    low.assign(n+1,-1);
    for(int i=1;i<=n;i++)
    {
        if(visited[i]) continue;
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
    find_bridges();
    cout<<bridges.size()<<endl;
    for(auto x:bridges) cout<<x.first<<" "<<x.second<<"\n";
    return 0;
}
