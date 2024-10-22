// Name of the Problem: Ant colony
// Link to the Problem: https://codeforces.com/contest/474/problem/F
// Link to the Solution: https://codeforces.com/contest/474/submission/275403319

#include <iostream>
#include<bits/stdc++.h>
typedef long long ll; using ll = long long;
#define INF 1e9 +7

using namespace std;

int gcd(int a,int b)
{
    if(a<b) swap(a,b);
    while(b)
    {
        a%=b;
        swap(a,b);
    }
    return a;
}

class MinimumSegmentTree
{
private:
    vector<int> t;
    int n;
public:
    MinimumSegmentTree(vector<int> &v)
    {
        n=v.size()-1;
        t.resize(8*n);
        build(1,1,n,v);
    }

    void build(int node,int tl,int tr,vector<int> &v)
    {
        if(tl==tr)
        {
            t[node]=v[tl];
            return;
        }
        int tm=(tl+tr)/2;
        build(node*2,tl,tm,v);
        build(node*2+1,tm+1,tr,v);
        t[node]=min(t[node*2],t[node*2+1]);
    }

    int query(int node,int tl,int tr,int l,int r)
    {
        if(l>r) return INF;
        if(tl==l && tr==r) return t[node];
        int tm=(tl+tr)/2;
        return min(query(node*2,tl,tm,l,min(tm,r)),
                   query(node*2+1,tm+1,tr,max(l,tm+1),r));
    }
};
class GreatestCommonDivisorSegmentTree
{
private:
    vector<pair<int,int> > t;
    int n;
public:
    GreatestCommonDivisorSegmentTree(vector<int> &v)
    {
        n=v.size()-1;
        t.resize(8*n);
        build(1,1,n,v);
    }

    void build(int node,int tl,int tr,vector<int> &v)
    {
        if(tl==tr)
        {
            t[node]=make_pair(v[tl],1);
            return;
        }
        int tm=(tl+tr)/2;
        build(node*2,tl,tm,v);
        build(node*2+1,tm+1,tr,v);
        t[node]=make_pair(0,0);
        int d = gcd(t[node*2].first,t[node*2+1].first);
        t[node].first=d; if(t[node*2].first==d) t[node].second+=t[node*2].second; if(t[node*2+1].first==d) t[node].second+=t[node*2+1].second;
    }

    pair<int,int> query(int node,int tl,int tr,int l,int r)
    {
        pair<int,int> ans=make_pair(0,0);
        if(l>r) return ans;
        if(tl==l && tr==r) return t[node];
        int tm=(tl+tr)/2;
        pair<int,int> ln=query(node*2,tl,tm,l,min(tm,r)); pair<int,int> rn=query(node*2+1,tm+1,tr,max(tm+1,l),r);
        if(ln.first==0) return rn;
        if(rn.first==0) return ln;
        ans.first=gcd(ln.first,rn.first);
        if(ln.first==ans.first) ans.second+=ln.second;
        if(rn.first==ans.first) ans.second+=rn.second;
        return ans;
    }
};
int main()
{
    int n; cin>>n;
    vector<int> a(n+1); for(int i=1;i<=n;i++) cin>>a[i];
    MinimumSegmentTree mst(a); GreatestCommonDivisorSegmentTree gcdst(a);
    int q; cin>>q;
    while(q--)
    {
        int a,b; cin>>a>>b;
        pair<int,int> egyik=gcdst.query(1,1,n,a,b);
        int masik=mst.query(1,1,n,a,b);
        if(egyik.first==masik) cout<<b-a+1-egyik.second<<endl;
        else cout<<b-a+1<<endl;
    }
    return 0;
}
