// Problem Name: Salary Queries
// Link to the Problem: https://cses.fi/problemset/task/1144
// Link to the Solution: https://cses.fi/paste/04d9389dd2021b209ea88b/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
 
typedef long long ll;
#define lsb(S) (S & (-S))
 
using namespace std;
 
class FenwickTree {
private:
    int n;
    vector<int> t;
public:
    FenwickTree(int s) {
        n = s;
        t.assign(n + 1, 0);
    }
 
    void add(int i, int x) {
        while (i <= n) {
            t[i] += x;
            i += lsb(i);
        }
    }
 
    int ps(int i) {
        int ans = 0;
        while (i) {
            ans += t[i];
            i -= lsb(i);
        }
        return ans;
    }
 
    int query(int a, int b) {
        return ps(b) - ps(a - 1);
    }
};
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, t, cnt;
    cin >> n >> t;
    cnt = 1;
 
    unordered_map<int, int> m;
    vector<int> nums;
    vector<int> p(n + 1);
    vector<vector<int>> q(t + 1, vector<int>(3));
 
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        nums.push_back(p[i]);
    }
 
    for (int i = 1; i <= t; i++) {
        char a;
        int b, c;
        cin >> a >> b >> c;
        nums.push_back(b);
        nums.push_back(c);
        q[i] = (a == '!') ? vector<int>{0, b, c} : vector<int>{1, b, c};
    }
 
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    for (int x : nums) {
        if (!m.count(x)) m[x] = cnt++;
    }
 
    FenwickTree ft(cnt + 5);
 
    for (int i = 1; i <= n; i++) {
        p[i] = m[p[i]];
        ft.add(p[i], 1);
    }
 
    for (int i = 1; i <= t; i++) {
        if (q[i][0] == 0) {
            q[i][2] = m[q[i][2]];
            ft.add(p[q[i][1]], -1);
            p[q[i][1]] = q[i][2];
            ft.add(p[q[i][1]], 1);
        } else {
            q[i][2] = m[q[i][2]];
            q[i][1] = m[q[i][1]];
            cout << ft.query(q[i][1], q[i][2]) << "\n";
        }
    }
 
    return 0;
}
