// Problem Name: Company Queries II
// Link to the Problem: https://cses.fi/problemset/task/1688
// Link to the Solution: https://cses.fi/paste/8ff8e0b5982c41a19c3fca/

#include <iostream>
#include<bits/stdc++.h>
 
using namespace std;
 
void dfs(int v,int p,vector<vector<int> > &adj,vector<int> &d)
{
    for(int to:adj[v])
    {
        if(to==p) continue;
        d[to]=d[v]+1;
        dfs(to,v,adj,d);
    }
}
 
int main()
{
    int n,q; cin>>n>>q;
    vector<vector<int> > adj(n+1); vector<int> d(n+1,0);
    int h[20][n+1]; h[0][0]=0; h[0][1]=0; for(int i=2;i<=n;i++) {cin>>h[0][i]; adj[h[0][i]].push_back(i); }
    for(int i=1;i<=19;i++) for(int j=0;j<=n;j++) h[i][j]=h[i-1][h[i-1][j]];
    dfs(1,-1,adj,d);
    while(q--)
    {
        int a,b; cin>>a>>b;
        if(d[a]>d[b]) swap(a,b);
        int k=d[b]-d[a];
        for(int i=19;i>=0;i--)
        {
            if((k & (1<<i))) b=h[i][b];
        }
        if(a==b) {cout<<a<<"\n"; continue;}
        for(int i=19;i>=0;i--)
        {
            if(h[i][a]!=h[i][b])
            {
                a=h[i][a]; b=h[i][b];
            }
        }
        a=h[0][a]; b=h[0][b];
        cout<<a<<"\n";
    }
    return 0;
}
