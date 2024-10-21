// Problem Name: Binomial Coefficients
// Link to the Problem: https: https://cses.fi/problemset/task/1079/
// Link to the Solution: https: //cses.fi/paste/8772ac9965ea2322a694dc/

#include <iostream>
#include<bits/stdc++.h>
using ll = long long ;
ll const MOD = 1e9 + 7 ;
 
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
        if(b & (1<<i))
            ans = (ans * bits[i]) % MOD ;
 
    return ans ;
 
}
 
ll comb(ll a , ll b)
{
    ll ans = 1 ;
    ans = fakt[a] ;
 
    ans *= exp(fakt[b] , MOD - 2) ;
    ans %= MOD ;
 
    ans *= exp(fakt[a - b] , MOD - 2) ;
    ans %= MOD ;
 
    return ans ;
 
}
 
 
int main()
{
    fakt[0] = 1 ;
    for(int i = 1 ; i <= 1e6 ; i++)
        fakt[i] = (i * fakt[i - 1]) % MOD ;
 
    int q ;
    cin >> q ;
 
    while(q--)
    {
        ll a , b ;
        cin >> a >> b ;
 
        cout << comb(a , b) << "\n" ;
    }
 
 
    return 0;
}
