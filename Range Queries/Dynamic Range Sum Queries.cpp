// Problem Name: Dynamic Range Sum Queries
// Link to the Problem: https://cses.fi/problemset/task/1648
// Link to the Solution: https://cses.fi/paste/8c4b090f2404125b8eacbf/

#include <iostream>
#include<vector>
#include<algorithm>
typedef long long ll;
using ll = long long;
 
using namespace std;
 
ll n,q,a,b,c;
vector<ll> v;
 
class SegmentTree
{
 
private:
 
    class vector<ll>T;
 
public:
 
    SegmentTree(vector<ll>&v)
    {
        T.assign(v.size()*8+1,0);
        for(ll i=1;i<v.size();i++)
        {
            update(1,1,n,i,v[i]);
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
        T[node]=T[node*2]+T[node*2+1];
    }
 
    ll rsq(ll node,ll tl,ll tr,ll l,ll r)
    {
        if(l>r) return 0;
        if(tl==l && tr==r) return T[node];
        ll tm=(tl+tr)/2;
        return rsq(node*2,tl,tm,l,min(tm,r)) + rsq(node*2+1,tm+1,tr,max(l,tm+1),r);
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
        cin>>a>>b>>c;
        if(a==1) st.update(1,1,n,b,c);
        else cout<<st.rsq(1,1,n,b,c)<<"\n";
    }
    return 0;
}
