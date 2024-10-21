// Problem Name: Static Range Sum Queries
// Link to the Problem: https://cses.fi/problemset/task/1646
// Link to the Solution: https://cses.fi/paste/1436b75e057a032e9ea327/

#include <iostream>
#include<bits/stdc++.h>
typedef long long ll;
 
using namespace std;
 
int main()
{
    int n,q; cin>>n>>q;
    ll dp[n+1]; dp[0] = 0;
    for(int i=1;i<=n;i++)
    {cin>>dp[i]; dp[i] += dp[i-1]; }
    while(q--)
    {
        int a,b; cin>>a>>b;
        cout<<dp[b] - dp[a - 1]<<"\n";
    }
 
    return 0;
}
