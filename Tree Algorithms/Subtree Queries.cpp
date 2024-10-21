// Problem Name: Subtree Queries
// Link to the Problem: https://cses.fi/problemset/task/1137
// Link to the Solution: https://cses.fi/paste/ba09690f32c178919c4b37/

#include <iostream>
#include<bits/stdc++.h>
typedef long long ll; using ll = long long;
 
using namespace std;
 
class SegmentTree
{
private:
    int size;
    vector<ll> t;
public:
    SegmentTree(int k)
    {
        size=k;
        t.assign(8*size,0);
    }
 
    void build(int node,int tl,int tr,vector<ll> &v)
    {
        if(tl==tr)
        {
            t[node]=v[tl];
            return;
        }
        int tm=(tl+tr)/2;
        build(node*2,tl,tm,v); build(node*2+1,tm+1,tr,v);
        t[node]=t[node*2] + t[node*2+1];
    }
 
    void change(int node,int tl,int tr,int i,ll v)
    {
        if(tl==tr)
        {
            t[node]=v;
            return;
        }
        int tm=(tl+tr)/2;
        if(i<=tm) change(node*2,tl,tm,i,v);
        else change(node*2+1,tm+1,tr,i,v);
        t[node]=t[node*2] + t[node*2+1];
    }
 
    ll sum(int node,int tl,int tr,int l,int r)
    {
        if(l>r) return 0;
        if(tl==l && tr==r) return t[node];
        int tm=(tl+tr)/2;
        return sum(node*2,tl,tm,l,min(tm,r)) + sum(node*2+1,tm+1,tr,max(l,tm+1),r);
    }
};
 
int n,m,cnt;
vector<vector<int> > adj;
vector<ll> l;
vector<ll> r;
vector<ll> v;
 
void dfs(int v,int p)
{
    l[v]=r[v]=cnt++;
    for(int to:adj[v])
    {
        if(to==p) continue;
        dfs(to,v);
        r[v]=max(r[v],r[to]);
    }
}
 
int main()
{
    cin>>n>>m; cnt=1;
    adj.resize(n+1); l.resize(n+1); r.resize(n+1); v.resize(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];
    for(int i=1;i<n;i++)
    {
        int a,b; cin>>a>>b;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    dfs(1,0);
    SegmentTree st(n);
    for(int i=1;i<=n;i++) st.change(1,1,n,l[i],v[i]);
    while(m--)
    {
        int k; cin>>k;
        if(k==1)
        {
            ll a,b; cin>>a>>b;
            st.change(1,1,n,l[a],b);
        }
        else
        {
            ll a; cin>>a;
            cout<<st.sum(1,1,n,l[a],r[a])<<"\n";
        }
    }
    return 0;
}
