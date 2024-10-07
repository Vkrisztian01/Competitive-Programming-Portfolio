// Problem Name: Counting Towers
// Link to the Problem: https://cses.fi/problemset/task/2413
// Link to the Solution: https://cses.fi/paste/d79b084ed1e6fa4a70654e/

#include <iostream>
#include<vector>
 
using namespace std;
 
int main()
{
    int n;
    long long int *dp1=new long long int[1000001];
    long long int *dp2=new long long int[1000001];
    dp1[1]=1;
    dp2[1]=1;
    for(int i=2;i<=1000000;i++)
    {
        dp1[i]=(dp1[i-1]*2+dp2[i-1])%1000000007;
        dp2[i]=(dp2[i-1]*4+dp1[i-1])%1000000007;
    }
    cin>>n;
    int k[n];
    for(int i=0;i<n;i++) cin>>k[i];
    for(int i=0;i<n;i++)
    {
        cout<<(dp1[k[i]]+dp2[k[i]])%1000000007<<"\n";
    }
    return 0;
}
