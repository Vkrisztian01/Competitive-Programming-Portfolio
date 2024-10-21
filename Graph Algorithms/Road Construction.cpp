// Problem Name: Road Construction
// Link to the Problem: https://cses.fi/problemset/task/1676
// Link to the Solution: https://cses.fi/paste/1528b1fd0e59a20494fd6a/

#include <iostream>
#include<bits/stdc++.h>
typedef long long ll; using ll = long long;
 
using namespace std;
 
class UnionFind
{
private:
 
    ll n,maxsize,cnt;
    vector<ll> head;
    vector<ll> d;
    vector<ll> s;
 
public:
 
    UnionFind(ll size)
    {
        n=size; maxsize=1; cnt=size;
        head.resize(n+1); for(ll i=1;i<=n;i++) head[i]=i;
        d.assign(n+1,1); s.assign(n+1,1);
    }
 
    int find(int v)
    {
        if(head[v]==v) return v;
        else return find(head[v]);
    }
 
    void unite(ll v1,ll v2)
    {
        int head1,head2; head1=find(v1); head2=find(v2);
        if(head1==head2) return;
        if(d[head1]<d[head2]) {swap(head1,head2); swap(v1,v2);}
        d[head1]=max(d[head1],d[head2]+1);
        s[head1]+=s[head2];
        maxsize=max(maxsize,s[head1]);
        head[head2]=head1;
        cnt--;
    }
 
    ll b() {return maxsize;}
 
    ll noc() {return cnt;}
 
};
 
int main()
{
    ll n,m; cin>>n>>m;
    UnionFind uf(n);
    vector<pair<int,int> > edges(m); for(int i=0;i<m;i++) cin>>edges[i].first>>edges[i].second;
    for(auto e:edges)
    {
        uf.unite(e.first,e.second);
        cout<<uf.noc()<<" "<<uf.b()<<"\n";
    }
    return 0;
}
