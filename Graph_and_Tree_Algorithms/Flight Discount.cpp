// Problem Name: Flight Discount
// Link to the Problem: https://cses.fi/problemset/task/1195
// Link to the Solution: https://cses.fi/paste/ff68305fae5a919b940987/

#include <iostream>
#include<bits/stdc++.h>
typedef long long ll; using ll = long long;
#define INF LONG_MAX/2
 
struct Edge {ll to,weight;};
 
using namespace std;
 
void Dijkstra1(vector<vector<Edge> > &g,vector<ll> &cost,priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > &pq1,priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > &pq2)
{
    while(!pq1.empty())
    {
        ll d,vertex; d=pq1.top().first; vertex=pq1.top().second; pq1.pop();
        if(cost[vertex]!=INF) continue;
        cost[vertex]=d;
        for(Edge e:g[vertex])
        {
            pq1.push(make_pair(d+e.weight,e.to));
            pq2.push(make_pair(d+e.weight/2,e.to));
        }
    }
}
 
void Dijkstra2(vector<vector<Edge> > &g,vector<ll> &cost,priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > &pq)
{
    while(!pq.empty())
    {
        ll d,vertex; d=pq.top().first; vertex=pq.top().second; pq.pop();
        if(cost[vertex]!=INF) continue;
        cost[vertex]=d;
        for(Edge e:g[vertex])
        {
            pq.push(make_pair(d+e.weight,e.to));
        }
    }
}
 
int main()
{
    ll n,m; cin>>n>>m;
    vector<vector<Edge> > g(n); vector<ll> cost1(n,INF); vector<ll>cost2(n,INF);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > pq1; priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > pq2;
    for(int i=0;i<m;i++)
    {
        ll a,b,c; cin>>a>>b>>c;
        g[a-1].push_back({b-1,c});
    }
    pq1.push(make_pair(0,0));
    Dijkstra1(g,cost1,pq1,pq2);
    Dijkstra2(g,cost2,pq2);
    cout<<min(cost1[n-1],cost2[n-1]);
    return 0;
}
