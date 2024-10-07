// Problem Name: Josephus Problem I
// Link to the Problem: https://cses.fi/problemset/task/2162
// Link to the Solution: https://cses.fi/paste/05f6abd3dfbd9d349d7b50/

#include <iostream>
#include<bits/stdc++.h>
typedef long long ll;
using ll = long long;
 
using namespace std;
 
int main()
{
    int n; cin>>n; int akt=1; int db=n;
    vector<pair<int,int> > a(n);
    for(int i=0;i<n;i++)
    {
        a[i]=make_pair(i-1,i+1);
        if(a[i].first==-1) a[i].first=n-1;
        if(a[i].second==n) a[i].second=0;
    }
    if(n==1) {cout<<1; return 0; }
    while(db--)
    {
        cout<<(akt+1)<<" ";
        a[a[akt].first].second=a[akt].second;
        a[a[akt].second].first=a[akt].first;
        akt=a[akt].second;
        akt=a[akt].second;
    }
    return 0;
}
