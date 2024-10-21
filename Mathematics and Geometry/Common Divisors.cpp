// Problem Name: Common Divisors
// Link to the Problem: https://cses.fi/problemset/task/1081
// Link to the Solution: https://cses.fi/paste/5a8c725bd109bf93a536f0/

#include <iostream>
#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    vector<int> cnt(1e6 + 1 , 0) ;
 
    int n ;
    cin >> n ;
 
    while(n--)
    {
        int x ;
        cin >> x ;
 
        cnt[x]++ ;
 
    }
 
    for(int i = 1e6 ; i >= 1 ; i--)
    {
        int s = 0 ;
 
        for(int cd = i ; cd <= 1e6 ; cd += i)
            s+=cnt[cd] ;
 
        if(s >= 2)
        {
            cout << i ;
            return 0 ;
        }
 
 
    }
 
    return 0;
}
