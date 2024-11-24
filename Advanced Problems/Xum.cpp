// Problem Name: Xum
// Link to the Problem: https://codeforces.com/contest/1427/problem/E

#include <iostream>
#include<bits/stdc++.h>
#include<sstream>
#define lsb(s) (s & -s)
typedef long long ll ;

using namespace std;

ll b[64] ;

int main()
{
    b[0] = 1 ;
    for(int i = 1 ; i < 61 ; i++)
        b[i] = 2 * b[i - 1] ;

    ios_base::sync_with_stdio(false) ;
    cin.tie() ;
    cout.tie() ;

    vector<string> ans ;

    ll n , m , h ;
    cin >> n ; h = n ; m = n ;

    while((n & m) != lsb(n))
    {
        stringstream st ;
        st << n << " + " << n ;
        ans.push_back(st.str()) ;
        n *= 2 ;
    }

    stringstream st_ ;
    st_ << n << " ^ " << h ;
    ans.push_back(st_.str()) ;
    m = n ^ h ;
    n = h ;

     ll l ;
    for(l = 1 ; l <= 2 * n ; l += 2)
    {
        if(l * m % n == 1)
            break ;
    }

    ll k = (l * m - 1) / n ;


    for(int i = 1 ; b[i] <= l ; i++)
    {
        stringstream st ;
        st << m * b[i - 1] << " + " << m * b[i - 1] ;
        ans.push_back(st.str()) ;
    }

    for(int i = 1 ; b[i] <= k ; i++)
    {
        stringstream st ;
        st << (n * b[i - 1]) << " + " << (n * b[i - 1]) ;
        ans.push_back(st.str()) ;
    }


    ll m0 = m ;
    for(int i = 1 ; b[i] <= l ; i++)
    {
        if(l & b[i])
        {
          stringstream st ;
        st << m << " + " << b[i] * m0 ;
        ans.push_back(st.str()) ;
        m += b[i] * m0 ;
        }
    }
    ll n0 = n ;
    bool a = false ;
    for(int i = 0 ; b[i] <= k ; i++)
    {
        if(k & b[i])
        {
            if(!a)
            {
                a = true ;
                n = n0 * b[i] ;
            }
            else
            {
                stringstream st ;
                st << n << " + " << n0 * b[i] ;
                ans.push_back(st.str()) ;
                n += b[i] * n0 ;
            }
        }
    }

    stringstream st ;
    st << n << " ^ " << m ;
    ans.push_back(st.str()) ;

    cout << ans.size() << "\n" ;
    for(string s : ans)
            cout << s << "\n" ;

    return 0;
}
