// Problem Name: Planets Queries I
// Link to the Problem: https://cses.fi/problemset/task/1750
// Link to the Solution: https://cses.fi/paste/c352de3ca3b04bfa949c88/

#include <iostream>
#include<bits/stdc++.h>
typedef long long ll; using ll = long long;
 
using namespace std;
 
int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n,q; cin>>n>>q;
    int curr,k,cnt;
    vector<vector<int> > bl(n+1,vector<int>(30));
    for(int i=1;i<=n;i++) cin>>bl[i][0];
    for(int i=1;i<=29;i++)
    {
        for(int j=1;j<=n;j++)
        {
            bl[j][i]=bl[bl[j][i-1]][i-1];
        }
    }
    while(q--)
    {
        cin>> curr >> k; cnt=0;
        while(k)
        {
            if(k%2) curr=bl[curr][cnt];
            k/=2; cnt++;
        }
        cout<<curr<<"\n";
    }
    return 0;
}
