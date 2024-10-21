// Problem Name: Range Xor Queries
// Link to the Problem: https://cses.fi/problemset/task/1650/
// Link to the Solution: https://cses.fi/paste/0c607a5ea06703e68eaefb/

#include <iostream>
#include<vector>
#include<algorithm>
#define XOR ^
typedef long long ll;
using ll = long long;
 
using namespace std;
 
ll n,q,a,b,c;
vector<ll> v;
 
class SegmentTree
{
private:
 
    vector<ll> T;
 
public:
 
    SegmentTree(vector<ll> &v)
    {
        T.assign(v.size()*8,0);
        for(ll i=1;i<=n;i++) update(1,1,n,i,v[i]);
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
        T[node] = T[node*2] XOR T[node*2+1];
    }
 
    ll rxq(ll node,ll tl,ll tr,ll l,ll r)
    {
        if(l>r) return 0;
        if(tl==l && tr==r) return T[node];
        ll tm=(tl+tr)/2;
        return rxq(node*2,tl,tm,l,min(r,tm)) XOR rxq(node*2+1,tm+1,tr,max(l,tm+1),r);
    }
};
 
int main()
{
    cin>>n>>q;
    v.resize(n+1);
    for(ll i=1;i<=n;i++) cin>>v[i];
    SegmentTree st(v);
    while(q--)
    {
        cin>>a>>b;
        cout<<st.rxq(1,1,n,a,b)<<"\n";
    }
    return 0;
}
