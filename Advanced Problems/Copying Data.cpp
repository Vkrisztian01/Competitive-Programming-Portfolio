// Name of the Problem: Copying Data
// Link to the Problem: https://codeforces.com/contest/292/problem/E
// Link to the Solution: https://codeforces.com/contest/292/submission/275411905

#include <iostream>
#include<bits/stdc++.h>
typedef long long ll; using ll = long long;

using namespace std;

class SegmentTree
{
private:
    int n;
    vector<pair<int,int> > t;
public:
    SegmentTree(int size) {n=size; t.assign(8*n,make_pair(0,0)); }

    void change(int node,int tl,int tr,int l,int r,pair<int,int> data)
    {
        if(l>r) return;
        if(tl!=tr && t[node].first!=0)
        {
            t[node*2]=t[node];
            t[node*2+1]=t[node];
            t[node]=make_pair(0,0);
        }
        if(tl==l && tr==r)
        {
            t[node]=data;
            return;
        }

        int tm=(tl+tr)/2;
        change(node*2,tl,tm,l,min(tm,r),data); change(node*2+1,tm+1,tr,max(l,tm+1),r,data);
    }
    pair<int,int> query(int node,int tl,int tr,int index)
    {
        if(t[node].first) return t[node];
        if(tl==tr) return t[node];
        int tm=(tl+tr)/2;
        if(index<=tm) return query(node*2,tl,tm,index);
        else return query(node*2+1,tm+1,tr,index);
    }
};

int main()
{
    int n,m; cin>>n>>m;
    int a[n+1]; int b[n+1];
    for(int i=1;i<=n;i++) cin>>a[i]; for(int i=1;i<=n;i++) cin>>b[i];
    SegmentTree st(n);
    for(int i=1;i<=m;i++)
    {
        int t; cin>>t;
        if(t==1)
        {
            int x,y,k; cin>>x>>y>>k;
            st.change(1,1,n,y,min(y+k-1,n),make_pair(x,y));
        }
        else
        {
            int pos; cin>>pos;
            pair<int,int> data=st.query(1,1,n,pos);
            if(data.first==0) cout<<b[pos]<<endl;
            else cout<<a[data.first+pos-data.second]<<endl;
        }

    }
    return 0;
}
