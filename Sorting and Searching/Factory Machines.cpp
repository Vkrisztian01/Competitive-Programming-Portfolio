// Problem Name: Factory Machines
// Link to the Problem: https://cses.fi/problemset/task/1620
// Link to the Solution: https://cses.fi/paste/eca2fedf14c2ff049dbe68/

#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
vector<ll> k;
 
bool check(ll mid, ll n, ll t)
{
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (mid / k[i]);
        if (sum >= t)
            return true;
    }
    return false;
}
 
ll solve(ll n, ll t)
{
    ll low = 1, high = (*max_element(k.begin(), k.end())) * t;
    ll ans;
 
    while (low <= high) {
        ll mid = (low + high) / 2;
 
        if (check(mid, n, t)) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}
 
int main()
{
    ll n,t; cin>>n>>t;
    k.resize(n); for(int i=0;i<n;i++) cin>>k[i];
 
    cout << solve(n, t);
}
