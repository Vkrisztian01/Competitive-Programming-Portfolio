// Problem Name: Josephus Queries
// Link to the Problem: https://cses.fi/problemset/task/2164
// Link to the Solution: https://cses.fi/paste/3954debabcae7325a531cb/

#include <iostream>
#include<bits/stdc++.h>
 
using namespace std;
 
int query(int n , int k)
{
    if(k * 2 <= n) return 2 * k ;
    if(k * 2 == n + 1) return 1 ;
 
    int x=query(n - (n + 1) / 2 , k - (n + 1) / 2) ;
    if(n % 2 == 1) return 2 * x + 1 ;
 
    return 2 * x - 1 ;
 
}
 
int main()
{
    int t ;
    cin >> t ;
 
    while(t--)
    {
        int n , k ;
        cin >> n >> k ;
 
        cout << query(n , k) << "\n" ;
 
    }
 
    return 0;
}
