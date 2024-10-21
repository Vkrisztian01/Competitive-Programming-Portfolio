// Problem Name: Road Reparation
// Link to the Problem: https://cses.fi/problemset/task/1675
// Link to the Solution: https://cses.fi/paste/27b262b701d5a60994fca0/

#include <iostream>
#include<bits/stdc++.h>
typedef long long ll ; using ll = long long;
 
using namespace std;
 
class UnionFind
{
private:
    ll n,c,s;
    vector<ll> d;
    vector<ll> head;
public:
    UnionFind(ll input)
    {
        n=input; c=0; s=n;
        d.assign(n+1,1);
        head.resize(n+1); for(ll i=1;i<=n;i++) head[i]=i;
    }
 
    ll find(ll v)
    {
        if(head[v]==v) return v;
        else return find(head[v]);
    }
 
    bool connected(ll v1,ll v2) {return (find(v1)==find(v2))? true : false;}
 
    void unite(ll v1,ll v2,ll adding)
    {
        c+=adding; s--;
        ll head1,head2; head1=find(v1); head2=find(v2);
        if(d[head1]<d[head2]) {swap(head1,head2); swap(v1,v2);}
        d[head1]=max(d[head1],d[head2]+1);
        head[head2]=head1;
    }
 
    bool complete() {return (s==1)? true:false;}
 
    ll cost() {return c;}
};
 
int main()
{
    ll n,m; cin>>n>>m;
    UnionFind uf(n);
    vector<pair<ll,pair<ll,ll> > > edges(m);
    for(ll i=0;i<m;i++)
    {
        ll u,v,w; cin>>u>>v>>w;
        edges[i]=make_pair(w,make_pair(u,v));
    }
    sort(edges.begin(),edges.end());
    for(pair<ll,pair<ll,ll> > e:edges)
    {
        if(uf.connected(e.second.first,e.second.second)) continue;
        uf.unite(e.second.first,e.second.second,e.first);
    }
    if(!uf.complete()) cout<<"IMPOSSIBLE";
    else cout<<uf.cost();
    return 0;
}
