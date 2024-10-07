// Problem Name: Rectangle Cutting
// Link to the Problem: https://cses.fi/problemset/task/1744
// Link to the Solution: https://cses.fi/paste/5279f3f657ddc82a7065e9/

#include <iostream>
#include<algorithm>
 
using namespace std;
 
int main()
{
    int dp[501][501];
    dp[0][0]=0;
    for(int i=1;i<=500;i++)
    {
        dp[i][0]=i-1;
        dp[0][i]=i-1;
    }
    for(int i=1;i<=500;i++)
    {
        for(int j=1;j<=500;j++)
        {
            if(i==j) dp[i][j]=0;
            else
            {
                dp[i][j]=9999999;
                for(int h=1;h<=i/2;h++) dp[i][j]=min(dp[i][j],dp[h][j]+dp[i-h][j]+1);
                for(int h=1;h<=j/2;h++) dp[i][j]=min(dp[i][j],dp[i][h]+dp[i][j-h]+1);
            }
        }
    }
    int a,b;
    cin>>a>>b;
    cout<<dp[a][b];
    return 0;
}
