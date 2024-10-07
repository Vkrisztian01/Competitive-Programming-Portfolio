// Problem Name: Grid Paths
// Link to the Problem: https://cses.fi/problemset/task/1638
// Link to the Solution: https://cses.fi/paste/55e2eca641690a146ff4cd/

#include <iostream>
#include<vector>
 
using namespace std;
 
int main()
{
    string s;
    int n;
    cin>>n;
    vector<vector<long long int> > dp(n,vector<long long int>(n,1));
    for(int i=0;i<n;i++)
    {
        cin>>s;
        for(int j=0;j<n;j++)
        {
            if(s[j]=='*') dp[i][j]=0;
        }
    }
    for(int i=1;i<n;i++)
    {
        if(dp[0][i])dp[0][i]=dp[0][i-1];
        if(dp[i][0]) dp[i][0]=dp[i-1][0];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(dp[i][j])
            {
             dp[i][j]=dp[i-1][j]+dp[i][j-1];
            dp[i][j]%=1000000007;
            }
 
        }
    }
    cout<<dp[n-1][n-1];
 
    return 0;
}
