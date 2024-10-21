// Problem Name: Tree Matching
// Link to the Problem: https://cses.fi/problemset/task/1130
// Link to the Solution: https://cses.fi/paste/1bc9a54b705f8dc79c3c81/

#include <iostream>
#include<bits/stdc++.h>
 
using namespace std;
 
void dfs(int v,int p,vector<vector<int> > &adj,vector<int> &dp1,vector<int> &dp2)
{
    if(adj[v].size()==1) return;
    dp2[v]=-200000;
    for(int to:adj[v])
    {
        if(to==p) continue;
        dfs(to,v,adj,dp1,dp2);
        dp1[v] += max(dp1[to],dp2[to]);
        dp2[v]=max(dp2[v],dp1[to]-dp2[to]);
    }
    dp2[v]+=dp1[v]+1;
}
 
int main()
{
   int n; cin>>n;
   int important=1;
   vector<vector<int> > adj(n+1); vector<int> dp1(n+1,0); vector<int> dp2(n+1,0);
   for(int i=1;i<n;i++)
   {
       int u,v; cin>>u>>v;
       adj[u].push_back(v); adj[v].push_back(u);
   }
   if(n==1) {cout<<0; return 0;}
   if(n==2) {cout<<1; return 0;}
 
   for(int i=1;i<=n;i++)
   {
       if(adj[i].size()>=2)
       {
           important=i;
           dfs(i,-1,adj,dp1,dp2);
           break;
       }
   }
   cout<<max(dp1[important],dp2[important]);
    return 0;
}
