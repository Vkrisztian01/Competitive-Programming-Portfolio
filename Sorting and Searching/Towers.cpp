// Problem Name: Towers
// Link to the Problem: https://cses.fi/problemset/task/1073/
// Link to the Solution: https://cses.fi/paste/f57aacdc0e9d4e03a01067/

#include <iostream>
#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n;
    cin>>n;
 
    int cnt = 0;
    map<int,int> m;
    set<int> s;
 
    while(n--)
    {
        int k;
        cin>>k;
        auto p = s.upper_bound(k);
        if(p == s.end())
        {
            cnt++;
            s.insert(k);
            m[k]++;
        }
        else
        {
            m[*p]--;
            m[k]++;
            s.insert(k);
            if(m[*p] == 0) s.erase(p);
        }
    }
 
    cout<<cnt;
    return 0;
