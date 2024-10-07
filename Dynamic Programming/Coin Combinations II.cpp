// Problem Name: Coin Combinations II
// Link to the Problem: https://cses.fi/problemset/task/1636
// Link to the Solution: https://cses.fi/paste/24050ed4d019ba4f6ff3f9/

#include <iostream>
#include<vector>
 
using namespace std;
 
int main()
{
    int n,k;
    cin>>n>>k;
    long long int nums[n];
    for(int i=0;i<n;i++) cin>>nums[i];
    long long int *dp = new long long int[1000001];
    for(int i=1;i<=1000000;i++) dp[i]=0;
    dp[0]=1;
    for(auto x:nums)
    {
        for(int i=0;i<=k;i++)
        {
            if(i>=x) dp[i]+=dp[i-x];
            dp[i]%=1000000007;
        }
    }
    cout<<dp[k];
    return 0;
}
