// Problem Name: Path Queries
// Link to the Problem: https://cses.fi/problemset/task/1138/
// Link to the Solution: https://cses.fi/paste/be0ce7b5d3a764a69c66a9/

#include <iostream>
#include<bits/stdc++.h>
using ll = long long;
 
using namespace std;
 
ll n,m,cnt;
vector<vector<ll> > adj;
vector<ll> tin;
vector<ll> tout;
vector<ll> dp;
vector<ll> ve;
ll t[2000000];
 
 
void dfs(int v,int p)
{
    tin[v]=tout[v]=cnt++;
    dp[tin[v]]+=ve[v];
    for(int to:adj[v])
    {
        if(to==p) continue;
        dp[cnt]+=dp[tin[v]];
        dfs(to,v);
        tout[v]=max(tout[v],tout[to]);
    }
}
 
void change(int node,int tl,int tr,int l,int r,ll x)
{
    if(l>r) return;
    if(tl==l && tr==r)
    {
        t[node]+=x;
        return;
    }
    int tm=(tl+tr)/2;
    change(node*2,tl,tm,l,min(tm,r),x); change(node*2+1,tm+1,tr,max(tm+1,l),r,x);
}
 
ll query(int node,int tl,int tr,int i)
{
    if(tl==tr) return t[node];
    int tm=(tl+tr)/2;
    if(i<=tm) return t[node] + query(node*2,tl,tm,i);
    else return t[node] + query(node*2+1,tm+1,tr,i);
}
 
int main()
{
    cin>>n>>m; cnt=1;
    adj.resize(n+1); tin.resize(n+1); tout.resize(n+1); dp.assign(n+1,0); ve.resize(n+1);
    for(int i=1;i<=n;i++) cin>>ve[i];
    for(int i=1;i<n;i++)
    {
        int a,b; cin>>a>>b;
        adj[a].push_back(b); adj[b].push_back(a);
    }
 
 
    dp[0]=0; tin[0]=0; dfs(1,0);
    while(m--)
    {
        int k; cin>>k;
        if(k==1)
        {
            ll s,x; cin>>s>>x;
            change(1,1,n,tin[s],tout[s],x - ve[s]);
            ve[s]=x;
        }
        else
        {
            ll s; cin>>s;
            cout<<dp[tin[s]] + query(1,1,n,tin[s])<<"\n";
        }
    }
    return 0;
}
