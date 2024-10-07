// Problem Name: Removal Game
// Link to the Problem: https://cses.fi/problemset/task/1097
// Link to the Solution: https://cses.fi/paste/9bc194a5875d74b171f0bb/

#include <iostream>
#include<vector>
#include<algorithm>
 
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    long long int nums[n];
    for(int i=0;i<n;i++) cin>>nums[i];
    vector<vector<long long int> > dp(n,vector<long long int>(n,0));
    for(int i=0;i<n;i++)
    {
        if(n%2==1) dp[i][i]=nums[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j+i<n)
            {
                if((n-i)%2==1)
                {
                    dp[j][j+i]=max(nums[j]+dp[j+1][j+i],nums[j+i]+dp[j][j+i-1]);
                }
                else
                {
                    dp[j][j+i]=min(dp[j+1][j+i],dp[j][j+i-1]);
                }
            }
        }
    }
    /*for(int i=0;i<n;i++)
    {
        cout<<endl;
        for(auto x:dp[i]) cout<<x<<", ";
    }*/
    cout<<dp[0][n-1];
    return 0;
}
