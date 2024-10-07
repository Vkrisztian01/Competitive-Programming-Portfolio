// Problem Name: Money Sums
// Link to the Problem: https://cses.fi/problemset/task/1745
// Link to the Solution: https://cses.fi/paste/9ef77bc48c9b58617051e5/

#include <iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<algorithm>
#include<set>
 
using namespace std;
 
int main()
{
    int n,s=0,db=0;
    cin>>n;
    vector<int>nums(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>nums[i];
        s+=nums[i];
    }
    vector<vector<bool> > dp(n+1,vector<bool>(s+1,false));
    dp[0][0]=true;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=s;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(nums[i]<=j) dp[i][j]=(dp[i][j] || dp[i-1][j-nums[i]]);
            if(i==n && dp[i][j]) db++;
        }
    }
    cout<<--db<<"\n";
    for(int i=1;i<=s;i++) if(dp[n][i]) cout<<i<<" ";
 
 
    return 0;
}
