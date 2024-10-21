// Problem Name: Shortest Routes II
// Link to the Problem: https://cses.fi/problemset/task/1672
// Link to the Solution: https://cses.fi/paste/2207a700c0cb6d4693fb2c/

#include <iostream>
#include<bits/stdc++.h>
typedef long long ll; using ll = long long;
#define INF LONG_MAX/3
 
using namespace std;
 
int main()
{
    ll n,m,q; cin>>n>>m>>q;
    vector<vector<ll> > d(n+1,vector<ll>(n+1,INF));
    for(int i=1;i<=n;i++) d[i][i]=0;
    for(int i=1;i<=m;i++)
    {
        ll a,b,c; cin>>a>>b>>c;
        d[a][b]=min(d[a][b],c); d[b][a]=min(d[b][a],c);
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                d[j][i]=d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    while(q--)
    {
        int a,b; cin>>a>>b;
        if(d[a][b]==INF) cout<<-1<<"\n";
        else cout<<d[a][b]<<"\n";
    }
    return 0;
}
