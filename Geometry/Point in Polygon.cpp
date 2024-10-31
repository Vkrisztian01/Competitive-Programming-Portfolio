// Problem Name: Point in Polygon
// Link to the Problem: https://cses.fi/problemset/task/2192
// Link to the Solution: https://cses.fi/paste/62e8e371ca58fe0fa86624/

#include <iostream>
#include<bits/stdc++.h>
typedef long long ll ;
 
using namespace std;
 
struct Point
{
    ll x , y ;
};
 
int turn(Point a , Point b , Point c)
{
    Point v1 = {b.x - a.x , b.y - a.y} ;
    Point v2 = {c.x - a.x , c.y - a.y} ;
 
    ll ans = v1.x * v2.y - v2.x * v1.y ;
 
    if(ans < 0) return -1 ;
    if(ans == 0) return 0 ;
    if(ans > 0) return 1 ;
}
 
bool between(Point a , Point b , Point c)
{
    return (min(a.x , b.x) <= c.x && c.x <= max(a.x , b.x) && min(a.y , b.y) <= c.y && c.y <= max(a.y , b.y)) ;
}
 
bool intersect(Point a1 , Point b1 , Point a2 , Point b2)
{
    if(turn(a1 , b1 , a2) == 0 && between(a1 , b1 , a2))
        return true ;
    if(turn(a1 , b1 , b2) == 0 && between(a1 , b1 , b2))
        return true ;
    if(turn(a2 , b2 , a1) == 0 && between(a2 , b2 , a1))
        return true ;
    if(turn(a2 , b2 , b1) == 0 && between(a2 , b2 , b1))
        return true ;
 
    if(turn(a1 , b1 , a2) != turn(a1 , b1 , b2) && turn(a2 , b2 , a1) != turn(a2 , b2 , b1))
        return true ;
 
    return false ;
}
 
int main()
{
    int n , m ;
    cin >> n >> m;
 
    vector<Point> polygon(n) ;
    for(int i = 0 ; i < n ; i++)
    {
        ll x , y ;
        cin >> x >> y ;
 
        polygon[i] = {x , y} ;
    }
 
    while(m--)
    {
        ll x , y ;
        cin >> x >> y ;
 
        Point a1 = {x , y} ;
        Point b1 = {0 , 1000000007} ;
 
        Point a2 , b2 ;
 
        int cnt = 0 ;
 
        for(int i = 0 ; i < n ; i++)
        {
            a2 = polygon[i] ;
            b2 = polygon[(i + 1) % n] ;
 
            if(between(a2 , b2 , a1) && !turn(a2 , b2 , a1))
            {
                cout << "BOUNDARY" << "\n" ;
 
                cnt = -10 ;
                break ;
            }
 
            if(intersect(a1 , b1 , a2 , b2))
                cnt++ ;
        }
 
        if(cnt >=0)
            cout << ((cnt % 2)? "INSIDE" : "OUTSIDE") << "\n" ;
    }
 
 
 
    return 0;
}
