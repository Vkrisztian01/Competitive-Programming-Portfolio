// Problem Name: List Removals
// Link to the Problem: https://cses.fi/problemset/task/1749
// Link to the Solution: https://cses.fi/paste/c803a48a2030b14f8ec3de/

#include <iostream>
#include<bits/stdc++.h>
typedef long long ll;
using ll = long long;
 
using namespace std;
 
ll n,q,a,b;
ll v[200001];
 
class SegmentTree
{
private:
 
    vector<ll> T;
 
public:
 
    SegmentTree(ll n)
    {
        T.assign(n*8+1,0);
        for(ll i=1;i<=n;i++) update(1,1,n,i,1);
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
        T[node]=T[node*2]+T[node*2+1];
    }
 
    ll rsq(ll node,ll tl,ll tr,ll l,ll r)
    {
        if(l>r) return 0;
        if(tl==l && tr==r) return T[node];
        ll tm=(tl+tr)/2;
        return rsq(node*2,tl,tm,l,min(r,tm))+rsq(node*2+1,tm+1,tr,max(l,tm+1),r);
    }
 
};
 
ll bs(SegmentTree & st,ll tl,ll tr,ll v)
{
    if(tl==tr) return tl;
    ll tm=(tl+tr)/2;
    if(st.rsq(1,1,n,1,tm)>=v) return bs(st,tl,tm,v);
    return bs(st,tm+1,tr,v);
}
 
int main()
{
    cin>>n;
    for(ll i=1;i<=n;i++) cin>>v[i];
    SegmentTree st(n);
    for(ll i=1;i<=n;i++)
    {
        cin>>q;
        ll j=bs(st,1,n,q);
        cout<<v[j]<<" ";
        st.update(1,1,n,j,0);
    }
    return 0;
}
