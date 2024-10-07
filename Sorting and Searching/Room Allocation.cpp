// Problem Name: Room Allocation
// Link to the Problem: https://cses.fi/problemset/task/1164
// Link to the Solution: https://cses.fi/paste/1be3e42cb29790019dbd5e/

#include <iostream>
#include<bits/stdc++.h>
 
using namespace std;
 
struct element
{
    int time,status,index;
};
 
bool order(element a,element b)
{
    return (a.time<b.time || (a.time==b.time && a.status==0 && b.status==1));
}
 
int main()
{
    int n; cin>>n;
    int cnt=0; queue<int> q;
    vector<element> v(2*n);
    vector<int> ans(n);
    for(int i=0;i<n;i++)
    {
        int a,b; cin>>a>>b;
        v[2*i]={a,0,i};
        v[2*i+1]={b,1,i};
    }
    sort(v.begin(),v.end(),order);
    for(element x:v)
    {
        if(x.status==1) {q.push(ans[x.index]);}
        else
        {
            if(q.empty()) q.push(++cnt);
            ans[x.index]=q.front();
            q.pop();
        }
    }
    cout<<cnt<<"\n";
    for(int x:ans) cout<<x<<" ";
    return 0;
}
