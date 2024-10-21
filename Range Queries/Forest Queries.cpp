// Problem Name: Forest Queries
// Link to the Problem: https://cses.fi/problemset/task/1652
// Link to the Solution: https://cses.fi/paste/b9f8ce7f1a83c6508ec075/

#include <iostream>
#include<bits/stdc++.h>
typedef long long ll;
using ll = long long;
 
using namespace std;
 
ll n,m,q;
ll D[4][1002][1002];
string s;
 
 
int main()
{
    cin>>n>>q;
    m=0;
    for(ll i=1;i<=n;i++)
    {
        cin>>s;
        for(ll j=0;j<n;j++)
        {
            if(s[j]=='*')
            {
                ++m;
                D[0][i][j+1]=1;
                D[1][i][j+1]=1;
                D[2][i][j+1]=1;
                D[3][i][j+1]=1;
            }
        }
    }
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            D[0][i][j]+=D[0][i-1][j]+D[0][i][j-1]-D[0][i-1][j-1];
            D[1][i][n+1-j]+=D[1][i-1][n+1-j]+D[1][i][n+2-j]-D[1][i-1][n+2-j];
            D[2][n+1-i][n+1-j]+=D[2][n+2-i][n+1-j]+D[2][n+1-i][n+2-j]-D[2][n+2-i][n+2-j];
            D[3][n+1-i][j]+=D[3][n+2-i][j]+D[3][n+1-i][j-1]-D[3][n+2-i][j-1];
        }
    }
 
 
 
 
 
    ll y1,y2,x1,x2;
    while(q--)
    {
        cin>>y1>>x1>>y2>>x2;
        cout<<m-D[0][y2][x1-1]-D[1][y1-1][x1]-D[2][y1][x2+1]-D[3][y2+1][x2]<<endl;
    }
    return 0;
}
