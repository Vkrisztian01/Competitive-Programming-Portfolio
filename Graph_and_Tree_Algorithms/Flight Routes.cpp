// Problem Name: Flight Routes
// Link to the Problem: https://cses.fi/problemset/task/1196
// Link to the Solution: https://cses.fi/paste/f2d29655155a058b5c7e11/

#include <iostream>
#include <vector>
#include <queue>
#include <functional>
 
using namespace std;
 
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<long int, int>>> G(n + 1);
    vector<int>jarte(n+1);
    for(int i=0;i<=n;i++) jarte[i]=0;
    for (int i = 1; i <= m; i++) {
        long int a, b, c;
        cin >> a >> b >> c;
        G[a].push_back(make_pair(c, b));
    }
    vector<long int> megoldasok;
 
    priority_queue<pair<long int, int>, vector<pair<long int, int>>, greater<pair<long int, int>>> seged;
    seged.push(make_pair(0, 1));
    while (megoldasok.size() != k)
        {
        int vertex = seged.top().second;
        long int cost = seged.top().first;
        seged.pop();
        if(jarte[vertex]<=k)
        {
        jarte[vertex]++;
 
 
        if (vertex == n)
        {
            megoldasok.push_back(cost);
 
        }
 
        for (auto x : G[vertex])
 
            {
                seged.push(make_pair(cost + x.first, x.second));
            }
 
 
        }
 
    }
    for (auto x : megoldasok) {
        cout << x << " ";
    }
 
    return 0;
}
