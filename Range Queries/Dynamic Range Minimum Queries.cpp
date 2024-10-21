// Problem Name: Dynamic Range Minimum Queries
// Link to the Problem: https://cses.fi/problemset/task/1649
// Link to the Solution: https://cses.fi/paste/4dbb98eacfbaf2158ead17/

#include <iostream>
#include<vector>
#include<algorithm>
typedef long long ll;
using ll = long long;
# define INF  90000000000
 
using namespace std;
 
ll n,q,a,b,c;
vector<ll>v;
 
class SegmentTree
{
private:
 
    vector<ll>T;
 
public:
 
    SegmentTree(vector<ll> &v)
    {
        T.assign(v.size()*8+1,INF);
        for(ll i=1;i<v.size();i++) update(1,1,n,i,v[i]);
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
        T[node]=min(T[node*2],T[node*2+1]);
    }
 
    ll rmq(ll node,ll tl,ll tr,ll l,ll r)
    {
        if(l>r) return INF;
        if(tl==l && tr==r) return T[node];
        ll tm=(tl+tr)/2;
        return min(rmq(node*2,tl,tm,l,min(tm,r)),rmq(node*2+1,tm+1,tr,max(l,tm+1),r));
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
        else cout<<st.rmq(1,1,n,b,c)<<"\n";
    }
    return 0;
}
