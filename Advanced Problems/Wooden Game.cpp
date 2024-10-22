// Name of the Problem: Wooden Game
// Link to the Problem: https://codeforces.com/problemset/problem/1994/E
// Link to the Solution: https://codeforces.com/contest/1994/submission/278754127

#include <iostream>
#include<bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve()
{
    ll ans = 0;
    int k; cin>>k;
    vector<ll> t(k);
    for(int i=0;i<k;i++)
    {
        cin>>t[i];
        ll p;
        for(ll j=1;j<t[i];j++) cin>>p;
        for(ll j=31;j>=0;j--)
        {
            if((t[i] & (1ll<<j)) == 0) continue;
            if((ans & (1ll<<j)) == 0) {ans += (1<<j); continue; }
            ans = ans | ((1ll<<j) - 1 );
            break;
        }
    }
    cout<<ans<<"\n";
}

int main()
{
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
