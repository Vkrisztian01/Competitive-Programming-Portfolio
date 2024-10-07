// Problem Name: Increasing Subsequence
// Link to the Problem: https://cses.fi/problemset/task/1145
// Link to the Solution: https://cses.fi/paste/bedfc8f65b0e2c76a132c6/

#include <iostream>
#include<bits/stdc++.h>
#define lsb(s) (s & -s)
 
using namespace std;
 
vector<int> t(2 * 1e5 + 1, 0);
 
int query(int i) {
 
    int ans = 0 ;
 
    while(i) {
 
        ans = max(ans , t[i]);
        i -= lsb(i);
 
    }
 
    return ans;
 
}
 
void update(int i , int x) {
 
    while(i <= 2 * 1e5) {
 
        t[i] = max(t[i] , x);
        i += lsb(i);
 
 
    }
 
 
 
 
}
 
int main()
{
    int n ;
    cin >> n;
 
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++ )
        cin>>a[i];
 
    vector<int> b = a;
    sort(b.begin(),b.end());
 
    map<int,int> m;
    int cnt = 1;
 
    for(int x : b)
        if(m[x] == 0)
            m[x] = cnt++;
 
    for(int i = 0 ; i < n ; i++ )
        a[i] = m[a[i] ];
 
    for(int x : a)
        update(x , query(x - 1) + 1 );
 
    cout << query(2 * 1e5);
 
    return 0;
}
