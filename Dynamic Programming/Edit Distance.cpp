// Problem Name: Edit Distance
// Link to the Problem: https://cses.fi/problemset/task/1639
// Link to the Solution: https://cses.fi/paste/2b66c0c096788014705102/

#include <iostream>
#include<vector>
#include<algorithm>
 
using namespace std;
 
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int n,m;
    n=s1.size();
    m=s2.size();
    vector<vector<int> > dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;i++) dp[i][0]=i;
    for(int i=0;i<=m;i++) dp[0][i]=i;
    s1="a"+s1;
    s2="a"+s2;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i]==s2[j])
            {
                dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j]+1,dp[i][j-1]+1));
            }
            else
            {
                dp[i][j]=min(dp[i-1][j-1]+1,min(dp[i-1][j]+1,dp[i][j-1]+1));
            }
        }
    }
    cout<<dp[n][m];
    return 0;
}
