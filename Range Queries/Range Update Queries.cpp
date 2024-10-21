// Problem Name: Range Update Queries
// Link to the Problem: https://cses.fi/problemset/task/1651/
// Link to the Solution: https://cses.fi/paste/597cd4544eb18fd78ebd45/

#include <iostream>
#include<bits/stdc++.h>
#define LSB (S & (-S))
typedef long long ll;
using ll = long long;
 
using namespace std;
 
ll n,q,a,b,c,d;
ll v[200001];
 
class SegmentTree
{
private:
    vector<ll>T;
public:
    SegmentTree(ll n)  {T.assign(n*8+1,0); }
 
    void ruq(ll node,ll tl,ll tr,ll l,ll r,ll u)
    {
        if(l>r) return;
        if(tl==l && tr==r)
        {
            T[node]+=u;
            return;
        }
        ll tm=(tl+tr)/2;
        ruq(node*2,tl,tm,l,min(r,tm),u);
        ruq(node*2+1,tm+1,tr,max(l,tm+1),r,u);
    }
 
    ll riq(ll node,ll tl,ll tr,ll i)
    {
        if(tl==tr) return T[node];
        ll tm=(tl+tr)/2;
        if(i<=tm) return T[node]+riq(node*2,tl,tm,i);
        return T[node]+riq(node*2+1,tm+1,tr,i);
    }
};
 
 
int main()
{
    cin>>n>>q;
    for(ll i=1;i<=n;i++) cin>>v[i];
    SegmentTree st(n);
    while(q--)
    {
        cin>>a;
        if(a==1)
        {
            cin>>b>>c>>d;
            st.ruq(1,1,n,b,c,d);
        }
        else
        {
            cin>>b;
            cout<<v[b]+st.riq(1,1,n,b)<<"\n";
        }
    }
    return 0;
}
