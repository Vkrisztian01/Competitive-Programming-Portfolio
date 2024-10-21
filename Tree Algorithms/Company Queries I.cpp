// Problem Name: Company Queries I
// Link to the Problem: https://cses.fi/problemset/task/1687
// Link to the Solution: https://cses.fi/paste/bc5fde0fb291c9fd9c3f5e/

#include <iostream>
#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n,q; cin>>n>>q;
    int h[20][n+1]; h[0][0]=0;h[0][1]=0; for(int i=2;i<=n;i++) cin>>h[0][i];
    for(int i=1;i<=19;i++)
    {
        for(int j=0;j<=n;j++)
        {
            h[i][j]=h[i-1][h[i-1][j]];
        }
    }
    while(q--)
    {
        int x,k; cin>>x>>k;
        for(int i=19;i>=0;i--)
        {
            if((k & (1<<i))) x=h[i][x];
        }
        if(x) cout<<x<<"\n";
        else cout<<-1<<"\n";
    }
    return 0;
}
