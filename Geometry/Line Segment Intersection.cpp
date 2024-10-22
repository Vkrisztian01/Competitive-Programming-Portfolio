// Name of the Problem: Line Segment Intersection
// Link to the Problem: https://cses.fi/problemset/task/2190
// Link to the Solution: https://cses.fi/paste/87bdcdf5e0b806c09e0d05/

#include <iostream>
#include<bits/stdc++.h>
typedef long long ll;
 
using namespace std;
 
struct v {ll y; ll x; };
 
int turn(v p1,v p2,v p3)
{
    v v1 = {p2.y-p1.y,p2.x-p1.x};
    v v2 = {p3.y-p1.y,p3.x-p1.x};
    ll s = v1.x * v2.y - v1.y * v2.x;
    if(s<0) return -1;
    if(s==0) return 0;
    if(s>0) return 1;
}
 
bool between(v p1,v p2, v q) {return (min(p1.x,p2.x) <= q.x && q.x <=max(p1.x,p2.x) && min(p1.y,p2.y) <= q.y && q.y <= max(p1.y,p2.y)    ); }
 
int main()
{
    int t; cin>>t;
    while(t--)
    {
        v p1, p2, p3, p4;
        cin>>p1.x>>p1.y; cin>>p2.x>>p2.y; cin>>p3.x>>p3.y; cin>>p4.x>>p4.y;
        if((turn(p1,p2,p3) == 0 && between(p1,p2,p3)) || (turn(p1,p2,p4)==0 && between(p1,p2,p4)) ) {cout<<"YES"<<"\n"; continue; }
        if((turn(p3,p4,p1) == 0 && between(p3,p4,p1)) || (turn(p3,p4,p2)==0 && between(p3,p4,p2)) ) {cout<<"YES"<<"\n"; continue; }
        if(turn(p1,p2,p3) != turn(p1,p2,p4) && turn(p3,p4,p1) != turn(p3,p4,p2) ) { cout<<"YES"<<"\n"; continue; }
        cout<<"NO"<<"\n";
    }
    return 0;
}
