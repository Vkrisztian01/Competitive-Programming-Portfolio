// Problem Name: Josephus Problem II
// Link to the Problem: https://cses.fi/problemset/task/2163
// Link to the Solution: https://cses.fi/paste/ca6e919b4db51cda9d7e77/

#include <iostream>
#include <bits/stdc++.h>
#define LSB(S) (S & (-S))
typedef long long ll;
 
using namespace std;
 
int t[200001];
ll n, k, act, cnt;
 
void picked(ll i) {
    while (i <= n) {
        t[i]--;
        i += LSB(i);
    }
}
 
int presum(ll i) {
    int ans = 0;
    while (i) {
        ans += t[i];
        i -= LSB(i);
    }
    return ans;
}
 
int rangesum(ll a, ll b) {
    return presum(b) - presum(a - 1);
}
 
int bs(int r) {
    int tl = act;
    int tr = n;
    while (tl < tr) {
        int tm = (tl + tr) / 2;
        int a = rangesum(act, tm);
        if (a < r) {
            tl = tm + 1;
        } else {
            tr = tm;
        }
    }
    return tl;
}
 
int main() {
    for (int i = 1; i <= 200000; i++) t[i] = LSB(i);
    cin >> n >> k;
    cnt = n;
    act = 1;
    while (cnt) {
        int r = k % cnt;
        r++;
        int s = rangesum(act, n);
        if (r > s) {
            r -= s;
            act = 1;
        }
        act = bs(r);
        cout << act << " ";
        picked(act);
        cnt--;
    }
    return 0;
}
