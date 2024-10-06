// Problem Name: Concert Tickets
// Link to the Problem: https://cses.fi/problemset/task/1091
// Link to the Solution: https://cses.fi/paste/b4416e6739a8ed5ea40875/

#include <iostream>
#include <set>
 
using namespace std;
 
int main() {
    int N, M;
    cin >> N >> M;
    multiset<int> prices;
 
    for (int i = 0; i < N; i++) {
        int h;
        cin >> h;
        prices.insert(-h);
    }
 
    for (int i = 0; i < M; i++) {
        int t;
        cin >> t;
        auto it = prices.lower_bound(-t);
        if (it == prices.end()) {
            cout << "-1" << endl;
        } else {
            cout << -(*it) << endl;
            prices.erase(it);
        }
    }
    return 0;
}
