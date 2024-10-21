// Problem Name: Christmas Party
// Link to the Problem: https://cses.fi/problemset/task/1717
// Link to the Solution: https://cses.fi/paste/0933c9006ac98851a69624/

#include <iostream>
#include<bits/stdc++.h>
typedef long long ll ;
const ll MOD = 1e9 + 7 ;
 
 
using namespace std;
 
ll fakt[1000001] ;
 
ll exp(ll a , ll b)
{
    ll bits[31] ;
    bits[0] = a ;
    for(int i = 1 ; i <= 30 ; i++)
        bits[i] = (bits[i - 1] * bits[i - 1]) % MOD ;
 
    ll ans = 1 ;
    for(int i = 0 ; i <= 30 ; i++)
        if(b & (1 << i))
            ans = (ans * bits[i]) % MOD ;
 
    return ans ;
}
 
ll comb(ll a , ll b)
{
    ll ans ;
    ans = fakt[a] ;
 
    ans = (ans * exp(fakt[b] , MOD - 2)) % MOD ;
 
    ans = (ans * exp(fakt[a - b] , MOD - 2)) % MOD ;
 
    return ans ;
}
 
int main()
{
    fakt[0] = 1 ;
    for(int i = 1 ; i <= 1e6 ; i++)
        fakt[i] = (fakt[i - 1] * i) % MOD ;
 
 
    ll n ;
    cin >> n ;
 
    ll ans ;
    ans = fakt[n] ;
 
    for(int i = 1 ; i <= n ; i++)
        if(i % 2)
        {
            ll k ;
            k = (comb(n , i) * fakt[n - i]) % MOD ;
 
            ans -= k ;
            if(ans < 0)
                ans += MOD ;
        }
        else
        {
            ll k ;
            k = (comb(n , i) * fakt[n - i]) % MOD ;
 
            ans += k ;
 
            ans %= MOD ;
        }
 
    cout << ans ;
 
    return 0;
}
