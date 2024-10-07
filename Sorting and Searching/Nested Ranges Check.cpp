// Problem Name: Nested Ranges Check
// Link to the Problem: https://cses.fi/problemset/task/2168
// Link to the Solution: https://cses.fi/paste/606199b5b50254a69d9154/

#include <iostream>
#include<bits/stdc++.h>
 
using namespace std;
 
bool f(pair<int,int> a,pair<int,int> b)
{
    if(a.first<b.first || (a.first==b.first && a.second>b.second)) return true;
    else return false;
}
 
int main()
{
    int n; cin>>n;
    vector<pair<int,int> > data(n);
    vector<pair<int,int> > v(n);
    set<pair<int,int> > ans1; set<pair<int,int> > ans2;
    for(int i=0;i<n;i++)
    {
        cin>>data[i].first>>data[i].second;
        v[i]=data[i];
    }
    sort(v.begin(),v.end(),f);
    int largest=0; int smallest=1e9 +7;
    for(auto x:v)
    {
        if(x.second<=largest) ans2.insert(x);
        else largest=x.second;
    }
    reverse(v.begin(),v.end());
    for(auto x:v)
    {
        if(x.second>=smallest) ans1.insert(x);
        else smallest=x.second;
    }
    for(auto x:data)
    {
        cout<<ans1.count(x)<<" ";
    }
 
 
 
 
    cout<<"\n";
    for(auto x:data)
    {
        cout<<ans2.count(x)<<" ";
    }
    return 0;
}
