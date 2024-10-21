// Problem Name: Finding a Centroid
// Link to the Problem: https://cses.fi/problemset/task/2079
// Link to the Solution: https://cses.fi/paste/17b57ee03e798fe6808261/

#include <iostream>
#include<vector>
 
using namespace std;
 
int n,a,b,ki;
vector<vector<int> > g;
vector<int> reszfa;
 
void dfs(int vertex,int parent)
{
    bool joe=true;
    for(auto to:g[vertex])
    {
        if(to==parent) continue;
        dfs(to,vertex);
        if(reszfa[to]>n/2) joe=false;
        reszfa[vertex]+=reszfa[to];
    }
    if(joe && n-reszfa[vertex]<=n/2) ki=vertex;
}
 
int main()
{
    cin>>n;
    g.resize(n+1);
    reszfa.assign(n+1,1);
    for(int i=1;i<n;i++)
    {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0);
    cout<<ki;
    return 0;
}
