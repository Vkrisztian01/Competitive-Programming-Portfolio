// Problem Name: Creating Strings II
// Link to the Problem: https://cses.fi/problemset/task/1715
// Link to the Solution: https://cses.fi/paste/c2a8af6f34c45185a6953f/

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
    ios_base::sync_with_stdio(NULL) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
 
    fakt[0] = 1 ;
    for(int i = 1 ; i <= 1e6 ; i++)
        fakt[i] = (i * fakt[i - 1]) % MOD ;
 
    vector<int> cnt(26) ;
    int n ;
 
    string s ;
    cin >> s ;
 
    n = s.size() ;
    for(char letter : s)
        cnt[letter - 'a']++ ;
 
    ll ans ;
    ans = fakt[n] ;
 
    for(int i = 0 ; i < 26 ; i++)
    {
        ans *= exp(fakt[cnt[i] ] , MOD - 2) ;
        ans %= MOD ;
    }
 
    cout << ans ;
 
    return 0;
}
