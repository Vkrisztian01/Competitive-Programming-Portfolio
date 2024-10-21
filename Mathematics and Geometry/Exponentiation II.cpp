// Problem Name: Exponentiation II
// Link to the Problem: https://cses.fi/problemset/task/1712
// Link to the Solution: https://cses.fi/paste/d09fa74e831a79ee8fd6b4/

#include <iostream>
#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
using ll = long long;
#define M 1000000007
 
ll fact[1000001];
ll q,a,b,c;
 
void f()
{
    fact[0]=1;
    for(int i=1;i<=1000001;i++) fact[i]=(i*fact[i-1])%M;
}
 
ll exp(ll a,ll b)
{
    ll bits[31];
    bits[0]=a;
    for(int i=1;i<=30;i++) bits[i]=(bits[i-1]*bits[i-1])%M;
    ll ans=1;
    for(int i=0;i<=30;i++)
    {
        if((b & (1<<i))!=0) ans=(ans*bits[i])%M;
    }
    return ans;
}
 
ll exp2(ll a,ll b)
{
    ll bits[31];
    bits[0]=a;
    for(int i=1;i<=30;i++) bits[i]=(bits[i-1]*bits[i-1])%(M-1);
    ll ans=1;
    for(int i=0;i<=30;i++)
    {
        if((b & (1<<i))!=0) ans=(ans*bits[i])%(M-1);
    }
    return ans;
}
 
int main()
{
    f();
    cin>>q;
    while(q--)
    {
        cin>>a>>b>>c;
        cout<<exp(a,exp2(b,c))<<"\n";
    }
    return 0;
}
