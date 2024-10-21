// Problem Name: Hotel Queries
// Link to the Problem: https://cses.fi/problemset/task/1143
// Link to the Solution: https://cses.fi/paste/471554d9ab3176248ec257/

#include <iostream>
#include<bits/stdc++.h>
typedef long long ll;
using ll = long long;
 
using namespace std;
 
ll n,m,a,b,c;
ll h[200001];
ll r[200001];
 
class SegmentTree
{
private:
    vector<ll>T;
public:
    SegmentTree(ll n)
    {
        T.assign(n*8+1,0);
        for(ll i=1;i<=n;i++)
        {
            update(1,1,n,i,h[i]);
        }
    }
 
    void update(ll node,ll tl,ll tr,ll i,ll v)
    {
        if(tl==tr)
        {
            T[node]=v;
            return;
        }
        ll tm=(tl+tr)/2;
        if(i<=tm) update(node*2,tl,tm,i,v);
        else update(node*2+1,tm+1,tr,i,v);
        T[node]=max(T[node*2],T[node*2+1]);
    }
 
    ll rmq(ll node,ll tl,ll tr,ll l,ll r)
    {
        if(l>r) return 0;
        if(tl==l && tr==r) return T[node];
        ll tm=(tl+tr)/2;
        return max(rmq(node*2,tl,tm,l,min(tm,r)), rmq(node*2+1,tm+1,tr,max(l,tm+1),r));
    }
};
 
ll bs(SegmentTree &st,ll tl,ll tr,ll v)
{
    if(tl==tr)
    {
        if(st.rmq(1,1,n,1,tl)>=v) return tl;
        return 0;
    }
    ll tm=(tl+tr)/2;
    if(st.rmq(1,1,n,1,tm)>=v) return bs(st,tl,tm,v);
    else return bs(st,tm+1,tr,v);
}
 
 
 
int main()
{
    cin>>n>>m;
    for(ll i=1;i<=n;i++) cin>>h[i];
    for(ll i=1;i<=m;i++) cin>>r[i];
    SegmentTree st(n);
    for(ll i=1;i<=m;i++)
    {
 
        ll j=bs(st,1,n,r[i]);
        cout<<j<<" ";
        if(j)
        {
            h[j]-=r[i];
            st.update(1,1,n,j,h[j]);
        }
 
 
    }
    return 0;
}
