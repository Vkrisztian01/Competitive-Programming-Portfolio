// Problem Name: Projects
// Link to the Problem: https://cses.fi/problemset/task/1140
// Link to the Solution: https://cses.fi/paste/8400954fe22d7d159f4104/

#include <iostream>
#include<bits/stdc++.h>
typedef long long ll;
 
using namespace std;
 
struct project
{
    int low,high,price;
};
 
bool order(project a,project b) {return a.high >= b.high; }
 
int main()
{
    int n; cin>>n;
    vector<project> a(n);
    vector<int> b(2*n);
    for(int i=0;i<n;i++)
    {
        int x,y,z;  cin>>x>>y>>z;
        a[i] = {x,y,z};
        b[2*i] = x;
        b[2*i + 1] = y;
    }
    sort(b.begin(),b.end());
    int cnt = 1;
    map<int,int> m;
    for(int x:b)
        if(!m.count(x)) m[x] = cnt++;
    for(int i=0;i<n;i++)
    {
        a[i].low = m[a[i].low];
        a[i].high = m[a[i].high];
    }
    sort(a.begin(),a.end(),order);
    vector<ll> dp(400001); dp[0] = 0;
    for(int i=1;i<=400001;i++)
    {
        dp[i] = dp[i-1];
        while(!a.empty() && a.back().high == i)
        {
            dp[i] = max(dp[i],a.back().price + dp[a.back().low-1]);
            a.pop_back();
        }
    }
    cout<<dp[400000];
    return 0;
}
