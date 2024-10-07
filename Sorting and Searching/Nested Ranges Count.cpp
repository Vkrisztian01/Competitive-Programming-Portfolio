// Problem Name: Nested Ranges Count
// Link to the Problem: https://cses.fi/problemset/task/2169
// Link to the Solution: https://cses.fi/paste/06e7869002527f0d9d9595/

#include <iostream>
#include <bits/stdc++.h>
#define LSB(S) (S & (-S))
 
using namespace std;
 
class FenwickTree {
private:
    vector<int> t;
 
public:
    void initiate(int n) { t.assign(n + 1, 0); }
 
    void add(int i) {
        while (i < t.size()) {
            t[i]++;
            i += LSB(i);
        }
    }
 
    int prefixsum(int i) {
        int ans = 0;
        while (i > 0) {
            ans += t[i];
            i -= LSB(i);
        }
        return ans;
    }
 
    int rangesum(int a, int b) {
        if (a > b) return 0;
        return prefixsum(b) - prefixsum(a - 1);
    }
};
 
bool f2(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }
bool f3(pair<int, int> a, pair<int, int> b) {
    if (a.first < b.first || (a.first == b.first && a.second > b.second))
        return true;
    return false;
}
 
int main() {
    int n;
    cin >> n;
 
    if (n == 0) return 0; // Handle empty input case
 
    vector<int> ans1(n), ans2(n);
    vector<pair<int, int>> v(n);
    map<pair<int, int>, int> intervals;
    vector<int> ends;
 
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        intervals[v[i]] = i;
        ends.push_back(v[i].second); // Collect end points for compression
    }
 
    // Coordinate compression of the second element (end points)
    sort(ends.begin(), ends.end());
    ends.erase(unique(ends.begin(), ends.end()), ends.end());
 
    // Map end points to compressed indices
    map<int, int> compressed;
    for (int i = 0; i < ends.size(); i++) {
        compressed[ends[i]] = i + 1;
    }
 
    // Sorting by second element
    sort(v.begin(), v.end(), f2);
    map<int, int> trs;
    int largest = 1;
    for (int i = 0; i < n; i++) {
        if (v[i].second > v[largest - 1].second) largest = i + 1;
        trs[v[i].second] = largest;
    }
 
    // Sorting by custom comparator (f3)
    sort(v.begin(), v.end(), f3);
    FenwickTree ft;
    ft.initiate(ends.size());
 
    // Calculate "contained by" using ft2
    for (auto x : v) {
        ans2[intervals[x]] = ft.rangesum(compressed[x.second], ends.size());
        ft.add(compressed[x.second]);
    }
 
    ft.initiate(ends.size());
    // Calculate "contains" using ft1 in reverse order
    reverse(v.begin(), v.end());
    for (auto x : v) {
        ans1[intervals[x]] = ft.rangesum(1, compressed[x.second]);
        ft.add(compressed[x.second]);
    }
 
    // Output the results
    for (auto x : ans1) cout << x << " ";
    cout << "\n";
    for (auto x : ans2) cout << x << " ";
    return 0;
}
