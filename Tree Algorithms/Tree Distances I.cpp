// Problem Name: Tree Distances I
// Link to the Problem: https://cses.fi/problemset/task/1132
// Link to the Solution: https://cses.fi/paste/5086551de7e50f0c9c3d00/

#include <iostream>
#include<bits/stdc++.h>
 
using namespace std;
 
void dfs(int v,int p,vector<vector<int> > &adj,vector<int> &dp)
{
    for(int to:adj[v])
    {
        if(to==p) continue;
        dp[to]=dp[v]+1;
        dfs(to,v,adj,dp);
    }
}
 
int main()
{
    int n; cin>>n;
    vector<vector<int> > adj(n+1);
    vector<int> dp1(n+1);
    vector<int> dp2(n+1);
    for(int i=1;i<n;i++)
    {
        int a,b; cin>>a>>b;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    int first=1,second=1;
    dp1[1]=0; dfs(1,-1,adj,dp1); for(int i=1;i<=n;i++) if(dp1[i]>dp1[first]) first=i;
    dp1[first]=0; dfs(first,-1,adj,dp1); for(int i=1;i<=n;i++) if(dp1[i]>dp1[second]) second=i;
    dp2[second]=0; dfs(second,-1,adj,dp2);
    for(int i=1;i<=n;i++) cout<<max(dp1[i],dp2[i])<<" ";
    return 0;
}
