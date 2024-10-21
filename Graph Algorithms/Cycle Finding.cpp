// Problem Name: Cycle Finding
// Link to the Problem: https://cses.fi/problemset/task/1197
// Link to the Solution: https://cses.fi/paste/19e58e2fb045d4b894915b/

#include <iostream>
#include<bits/stdc++.h>
typedef long long ll;
using ll = long long;
#define INF LONG_MAX/3
 
using namespace std;
 
struct Edge {ll from,to,weight;};
 
void BellmanFord(ll prime,ll n,vector<ll> &dist,vector<ll> &from,vector<Edge> &edges)
{
    dist.assign(n+1,INF);
    from.assign(n+1,-1);
    dist[prime]=0;
    for(ll i=1;i<n;i++)
    {
        for(Edge e:edges)
        {
            if(dist[e.to]>dist[e.from]+e.weight)
            {
                dist[e.to]=dist[e.from]+e.weight;
                from[e.to]=e.from;
            }
        }
    }
}
 
int main()
{
    ll n,m; cin>>n>>m;
    vector<Edge> edges(m);
    vector<ll> dist,from;
    for(ll i=1;i<=m;i++)
    {
        ll a,b,c; cin>>a>>b>>c;
        edges.push_back({a,b,c});
    }
    BellmanFord(1,n,dist,from,edges);
    ll c=-1;
    for(Edge e:edges) {if(dist[e.to]>dist[e.from]+e.weight) {c=e.to; dist[c]=dist[e.from] + e.weight; from[e.to] = e.from; break;} }
    if(c==-1)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<endl;
    for(int i=0;i<n;++i) c=from[c];
    vector<ll> ans = {c};
    ll akt = c;
    while(from[akt]!=c) {akt=from[akt]; ans.push_back(akt);}
    ans.push_back(c);
    reverse(ans.begin(),ans.end());
    for(ll node: ans) cout<<node<<" ";
    return 0;
}
