// Problem Name: Bracket Sequences II
// Link to the Problem: https://cses.fi/problemset/task/2187
// Link to the Solution: https://cses.fi/paste/aad64e2177f1ed6fa6a57a/

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
 
ll comb(ll a ,ll b)
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
    for(int i = 1 ; i <= 2 * 1e6 ; i++)
        fakt[i] = (i * fakt[i - 1]) % MOD ;
 
    ll n ;
    cin >> n ;
 
    string s ;
    cin >> s ;
 
    ll cnt1 = 0 ;
    ll cnt2 = 0 ;
 
    for(char letter : s)
    {
        if(letter == '(') cnt1 ++ ;
        else cnt2 ++ ;
 
        if(cnt2 > cnt1)
        {
            cout << 0 ;
            return 0 ;
        }
    }
 
 
    if(n % 2 || cnt2 > cnt1 || cnt1 > n / 2)
    {
        cout << 0 ;
        return 0 ;
    }
 
    n /= 2 ;
 
    cnt1 = n - cnt1 ;
    cnt2 = n - cnt2 ;
 
    if(cnt1 == 0)
    {
        cout << 1 ;
        return 0 ;
    }
 
    ll ans = comb(cnt1 + cnt2 , cnt2) - comb(cnt1 + cnt2 , cnt2 + 1) ;
 
    if(ans < 0) ans += MOD ;
 
    cout << ans ;
 
    return 0;
}
