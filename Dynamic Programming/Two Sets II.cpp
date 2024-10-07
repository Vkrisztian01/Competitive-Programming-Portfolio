// Problem Name: Two Sets II
// Link to the Problem: https://cses.fi/problemset/task/1093
// Link to the Solution: https://cses.fi/paste/7096716bb39d175f9f3ab8/

#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
const ll mod = 1e9 + 7;
 
int main() {
    vector<vector<ll>> dp(501, vector<ll>(125002, 0));
    dp[0][0] = 1;
 
    for (int i = 1; i <= 500; i++) {
        ll k = min(((ll) i * (i + 1)) / 2, 125000LL);
        for (int j = 0; j <= k; j++) {
            dp[i][j] = dp[i-1][j];
            if (j >= i) dp[i][j] = (dp[i][j] + dp[i-1][j-i]) % mod;
        }
    }
 
    int n;
    cin >> n;
    if ((n * (n + 1)) % 4 != 0) {
        cout << 0;
    } else {
        ll result = dp[n][n * (n + 1) / 4];
        cout << result * 500000004 % mod;
    }
 
    return 0;
}
