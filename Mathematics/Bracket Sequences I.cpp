// Problem Name: Bracket Sequences I
// Link to the Problem: https://cses.fi/problemset/task/2064
// Link to the Solution: https://cses.fi/paste/e8072aff9b5f73cba6985e/

#include <iostream>
#include<bits/stdc++.h>
typedef long long ll ;
const ll MOD = 1e9 + 7 ;
 
using namespace std;
 
ll fakt[2000001] ;
 
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
 
    ans =  (ans * exp(fakt[b] , MOD - 2)) % MOD ;
 
    ans = (ans * exp(fakt[a - b] , MOD - 2)) % MOD ;
 
    return ans ;
}
 
int main()
{
    fakt[0] = 1 ;
    for(int i = 1 ; i <= 2 * 1e6 ; i++)
        fakt[i] = (fakt[i - 1] * i) % MOD ;
 
    ll n ;
    cin >> n ;
 
    if(n % 2)
    {
        cout << 0 ;
        return 0 ;
    }
 
    n /= 2 ;
 
    cout << (comb(2 * n , n) * exp(n + 1 , MOD - 2) ) % MOD ;
 
 
    return 0;
}
