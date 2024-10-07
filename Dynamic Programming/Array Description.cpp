// Problem Name: Array Description
// Link to the Problem: https://cses.fi/problemset/task/1746
// Link to the Solution: https://cses.fi/paste/9839a897670ed16f7048b7/

#include <iostream>
#include<vector>
 
using namespace std;
 
int main()
{
    int n,m,x;
    cin>>n>>m;
    vector<vector<long long int> > dp(m+2,vector<long long int>(n+1,0));
    cin>>x;
    if(x) dp[x][1]=1;
    else for(int i=1;i<=m;i++) dp[i][1]=1;
    for(int i=2;i<=n;i++)
    {
        cin>>x;
        if(x)
        {
            dp[x][i]=dp[x-1][i-1]+dp[x+1][i-1]+dp[x][i-1];
            dp[x][i]%=1000000007;
        }
        else
        {
            for(int j=1;j<=m;j++)
            {
            dp[j][i]=dp[j-1][i-1]+dp[j+1][i-1]+dp[j][i-1];
            dp[j][i]%=1000000007;
            }
        }
    }
    long long int sum=0;
    for(int i=1;i<=m;i++)
    {
        sum+=dp[i][n];
        sum%=1000000007;
    }
    /*for(int i=0;i<=m+1;i++)
    {
        for(auto x:dp[i]) cout<<x<<" ";
        cout<<endl;
    }*/
    cout<<sum;
    return 0;
}
