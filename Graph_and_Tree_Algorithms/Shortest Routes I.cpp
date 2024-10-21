// Problem Name: Shortest Routes I
// Link to the Problem: https://cses.fi/problemset/task/1671
// Link to the Solution: https://cses.fi/paste/39a1fa72dc3df48c93fafc/

#include <iostream>
#include<bits/stdc++.h>
#define INF 1000000007
typedef long long ll; using ll = long long;
 
using namespace std;
 
void Dijkstra(vector<vector<pair<ll,ll> > > &g, vector<ll> &d, priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > &pq)
{
    while(!pq.empty())
    {
        ll cost,vertex; cost=pq.top().first; vertex=pq.top().second; pq.pop();
        if(d[vertex]!=INF) continue;
        d[vertex]=cost;
        for(auto to:g[vertex])
        {
            pq.push(make_pair(cost+to.second,to.first));
        }
    }
}
 
int main()
{
    ll n,m; cin>>n>>m;
    vector<vector<pair<ll,ll> > > g(n); vector<ll> d(n,INF);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > pq; pq.push(make_pair(0,0));
    for(int i=0;i<m;i++)
    {
        ll a,b,c; cin>>a>>b>>c; --a; --b;
        g[a].push_back(make_pair(b,c));
    }
    Dijkstra(g,d,pq);
    for(ll x:d) cout<<x<<" ";
    return 0;
}
