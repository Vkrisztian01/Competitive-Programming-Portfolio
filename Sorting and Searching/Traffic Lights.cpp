// Problem Name: Traffic Lights
// Link to the Problem: https://cses.fi/problemset/task/1163
// Link to the Solution: https://cses.fi/paste/7317929b4db0e67e9d7a9c/

#include <iostream>
#include<bits/stdc++.h>
typedef long long ll; using ll = long long;
 
using namespace std;
 
int main()
{
    int x,n; cin>>x>>n;
    set<int> h1; h1.insert(0); h1.insert(x);
    set<int> h2; h2.insert(0); h2.insert(-1*x);
    set<pair<int,pair<int,int> > > s; s.insert(make_pair(-1*x,make_pair(0,x)));
    vector<int> ans;
    while(n--)
    {
        int p; cin>>p;
        if(!h1.count(p))
        {
            auto a=h1.lower_bound(p);
            auto b=h2.lower_bound(-1*p);
            int e=*a; int f=-1*(*b);
            s.erase(make_pair(-1*(e-f),make_pair(f,e)));
            s.insert(make_pair(-1*(p-f),make_pair(f,p)));
            s.insert(make_pair(-1*(e-p),make_pair(p,e)));
            h1.insert(p); h2.insert(-1*p);
        }
        ans.push_back(-1*s.begin()->first);
    }
    for(int x:ans) cout<<x<<" ";
    return 0;
