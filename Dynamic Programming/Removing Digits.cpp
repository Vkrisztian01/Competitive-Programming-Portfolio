// Problem Name: Removing Digits
// Link to the Problem: https://cses.fi/problemset/task/1637
// Link to the Solution: https://cses.fi/paste/535d714255db44236ff440/

#include <iostream>
#include<algorithm>
 
using namespace std;
 
bool joe(int szam,int jegy)
{
    while(szam!=0)
    {
        if(szam%10==jegy) return true;
        szam/=10;
    }
    return false;
}
 
int main()
{
    int n;
    cin>>n;
    long long int * dp=new long long int[n+15];
    for(int i=0;i<n+15;i++) dp[i]=9999999;
    dp[n]=0;
    for(int i=n-1;i>=0;--i)
    {
        for(int j=1;j<=9;j++)
        {
            if(joe(i+j,j)) dp[i]=min(dp[i],dp[i+j]+1);
        }
    }
    if(dp[0]>=9999999) cout<<-1;
    else cout<<dp[0];
 
 
    return 0;
}
