// Name of the Problem: Point Location Test
// Link to the Problem: https://cses.fi/problemset/task/2189
// Link to the Solution: https://cses.fi/paste/e670b77ea249f0b39e0c5a/

#include <iostream>
#include<bits/stdc++.h>
typedef long long ll; using ll = long long;
 
using namespace std;
 
struct p {ll y; ll x; };
 
int turn(p p1,p p2,p q)
{
    p v1 = {p2.y-p1.y,p2.x-p1.x};
    p v2 = {q.y-p1.y,q.x-p1.x};
    ll s = v2.y * v1.x - v2.x * v1.y;
    if(s>0) return 1;
    if(s==0) return 0;
    if(s<0) return -1;
}
 
int main()
{
    int t; cin>>t;
    while(t--)
    {
        p p1; cin>>p1.x>>p1.y;
        p p2; cin>>p2.x>>p2.y;
        p p3; cin>>p3.x>>p3.y;
        ll s = turn(p1,p2,p3);
        if(s==1) cout<<"LEFT"<<"\n";
        if(s==0) cout<<"TOUCH"<<"\n";
        if(s==-1) cout<<"RIGHT"<<"\n";
    }
    return 0;
}
