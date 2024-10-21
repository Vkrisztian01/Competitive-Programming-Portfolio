// Problem Name: Counting Divisors
// Link to the Problem: https://cses.fi/problemset/task/1713
// Link to the Solution: https://cses.fi/paste/7f0664a2255a9705a53243/

#include <iostream>
#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    vector<vector<int> > pf(1e6 + 1) ;
 
    for(int i = 2 ; i <= 1e6 ; i++ )
        if(pf[i].empty())
            for(int j = i ; j <= 1e6 ; j += i)
                pf[j].push_back(i) ;
 
    int n ;
    cin >> n ;
 
    while(n--)
    {
        int x ;
        cin >> x ;
 
        int y = x ;
 
        int ans = 1 ;
 
        for(int d : pf[x])
        {
            int cnt = 1 ;
 
            while(y % d == 0)
            {
                y /= d ;
                cnt++ ;
            }
 
            ans *= cnt ;
 
        }
 
        cout << ans << "\n" ;
 
    }
 
 
    return 0;
}
