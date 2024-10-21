// Problem Name: Subordinates
// Link to the Problem: https://cses.fi/problemset/task/1674
// Link to the Solution: https://cses.fi/paste/adfc166eff2f87aa9c2e62/

#include <iostream>
#include<bits/stdc++.h>
 
using namespace std;
 
void dfs(int v,vector<vector<int> > &t, vector<int> &dp)
{
    dp[v]=0;
    for(int to:t[v])
    {
        dfs(to,t,dp);
        dp[v] += dp[to]+1;
    }
}
 
int main()
{
    int n; cin>>n;
    vector<vector<int> > t(n+1); vector<int> dp(n+1);
    for(int to=2;to<=n;to++)
    {
        int from; cin>>from;
        t[from].push_back(to);
    }
    dfs(1,t,dp);
    for(int i=1;i<=n;i++) cout<<dp[i]<<" ";
    return 0;
}
