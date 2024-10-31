// Problem Name: Polygon Area
// Link to the Problem: https://cses.fi/problemset/task/2191
// Link to the Solution: https://cses.fi/paste/af175e4bf18493dda85605/

#include <iostream>
#include<bits/stdc++.h>
typedef long long ll ;
 
using namespace std;
 
struct Point
{
    ll x , y ;
 
    Point() {x = 0 ; y = 0 ;}
 
    Point(int x_ , int y_) {x = x_ ; y = y_ ;}
 
};
 
class Polygon
{
private:
 
    int n ;
    vector<Point> t ;
 
public:
 
    Polygon(int n_ , vector<Point> &v)
    {
        n = n_ ;
        t.resize(n + 1) ;
 
        for(int i = 0 ; i < n ; i++)
            t[i] = v[i] ;
 
        t[n] = t[0] ;
 
    }
 
    ll area()
    {
        ll ans = 0 ;
        for(int i = 0 ; i < n ; i++)
            ans += t[i].x * t[i + 1].y ;
 
        for(int i = 0 ; i < n ; i++)
            ans -= t[i].y * t[i + 1].x ;
 
        return abs(ans) ;
 
    }
 
 
};
 
int main()
{
    int n ;
    cin >> n ;
 
    vector<Point> v(n) ;
 
    for(int i = 0 ; i < n ; i++)
    {
        ll x , y ;
        cin >> x >> y ;
 
        v[i] = {x , y} ;
    }
 
    Polygon p(n , v) ;
 
    cout << p.area() ;
 
    return 0;
}
