// Problem Name: Prefix Sum Queries
// Link to the Problem: https://cses.fi/problemset/task/2166
// Link to the Solution: https://cses.fi/paste/cffd5051ebd1b78b8f351d/

#include <iostream>
#include<bits/stdc++.h>
typedef long long ll;
using ll = long long;
 
using namespace std;
#define MIN -1* 1e14
 
ll n,q,elso,masodik,harmadik,d=0;
ll a[200001];
ll p[200001];
ll t[800001];
ll lazy[800001];
 
void build(ll node,ll tl,ll tr)
{
    if(tl==tr)
    {
        t[node]=p[tl];
    }
    else
    {
        ll tm=(tl+tr)/2;
        build(node*2,tl,tm);
        build(node*2+1,tm+1,tr);
        t[node]=max(t[node*2],t[node*2+1]);
    }
}
 
void push(ll node)
{
    lazy[node*2]+=lazy[node];
    lazy[node*2+1]+=lazy[node];
    t[node*2]+=lazy[node];
    t[node*2+1]+=lazy[node];
    lazy[node]=0;
}
 
void update(ll node,ll tl,ll tr,ll l,ll r,ll u)
{
    if(l>r) return;
    if(tl==l && tr==r)
    {
        t[node]+=u;
        lazy[node]+=u;
    }
    else
    {
        push(node);
        ll tm =(tl+tr)/2;
        update(node*2,tl,tm,l,min(tm,r),u);
        update(node*2+1,tm+1,tr,max(tm+1,l),r,u);
        t[node]=max(t[node*2+1],t[node*2]);
    }
}
 
ll query(ll node,ll tl,ll tr,ll l,ll r)
{
    if(l==0 && r==0) return 0;
    if(l>r) return MIN;
    if(tl==l && tr==r)
    {
        return t[node];
    }
    else
    {
        push(node);
        ll tm=(tl+tr)/2;
        return max( query(node*2,tl,tm,l,min(r,tm)),
                   query(node*2+1,tm+1,tr,max(l,tm+1),r));
    }
}
 
 
int main()
{
    cin>>n>>q;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        p[i]=a[i]+p[i-1];
    }
    build(1,1,n);
    while(q--)
    {
        cin>>elso>>masodik>>harmadik;
        if(elso==2) cout<<max(query(1,1,n,masodik,harmadik)-query(1,1,n,masodik-1,masodik-1),d)<<"\n";
        else
        {
            update(1,1,n,masodik,n,harmadik-a[masodik]);
            a[masodik]=harmadik;
        }
    }
    return 0;
}
