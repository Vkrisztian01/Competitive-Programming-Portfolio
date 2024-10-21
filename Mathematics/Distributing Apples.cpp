// Problem Name: Distributing Apples
// Link to the Problem: https://cses.fi/problemset/task/1716
// Link to the Solution: https://cses.fi/paste/9a53b6fda2e0d078a695a8/

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
 
    ans = (ans * exp(fakt[b] , MOD - 2) ) % MOD ;
 
    ans = (ans * exp(fakt[a - b] , MOD - 2) ) % MOD ;
 
    return ans ;
}
 
int main()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
 
    fakt[0] = 1 ;
    for(int i = 1 ; i <= 2 * 1e6 ; i++)
        fakt[i] = (i * fakt[i - 1]) % MOD ;
 
    ll n , m ;
    cin >> n >> m ;
 
    cout << comb(n + m - 1 , n - 1) ;
 
 
    return 0;
}
