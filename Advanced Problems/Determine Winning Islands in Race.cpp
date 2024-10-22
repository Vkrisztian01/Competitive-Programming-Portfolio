// Name of the Problem: Determine Winning Islands in Race
// Link to the Problem: https://codeforces.com/problemset/problem/1998/D
// Link to the Solution: https://codeforces.com/contest/1998/submission/275617189

#include <iostream>
#include<bits/stdc++.h>

using namespace std;

bool t[1600001];
int n,m;

void change(int node,int tl,int tr,int l,int r)
{
    if(l>r) return;
    if(tl==l && tr==r)
    {
        t[node]=true;
        return;
    }
    int tm=(tl+tr)/2;
    change(node*2,tl,tm,l,min(tm,r));
    change(node*2+1,tm+1,tr,max(tm+1,l),r);
}

void ki(int node,int tl,int tr)
{
    if(tl==tr)
    {
        if(t[node]) cout<<0;
        else cout<<1;
        return;
    }
    if(t[node])
    {
        for(int i=tl;i<=tr;i++) cout<<0;
        return;
    }
    int tm=(tl+tr)/2;
    ki(node*2,tl,tm);
    ki(node*2+1,tm+1,tr);
}

void solve()
{
    cin>>n>>m;
    vector<vector<int> > adj(n+1);
    vector<int> d(n+1,n+1);
    for(int i=1;i<=m;i++)
    {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
    }
    d[1]=0;
    queue<int> q; q.push(1);
    while(!q.empty())
    {
        int v=q.front();
        q.pop();
        for(int to:adj[v])
        {
            if(d[to]==n+1)
            {
                d[to]=d[v]+1;
                q.push(to);
            }
        }
        if(v!=n)
        {
            if(d[v+1]==n+1)
            {
                d[v+1]=d[v]+1;
                q.push(v+1);
            }
        }
    }
    for(int i=1;i<=8*n;i++) t[i]=false;
    for(int i=1;i<n;i++)
    {
        int legmesszebb=0;
        for(int to:adj[i]) legmesszebb=max(legmesszebb,to);
        if(legmesszebb-d[i]-2>=i+1) change(1,1,n-1,i+1,legmesszebb-d[i]-2);
    }
    ki(1,1,n-1);
    cout<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin>>T;
    while(T--) solve();
    return 0;
}
