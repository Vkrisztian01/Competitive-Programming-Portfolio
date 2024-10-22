// Name of the Problem: Enemy is weak
// Link to the Problem: https://codeforces.com/contest/61/problem/E
// Link to the Solution: https://codeforces.com/contest/61/submission/275374720

#include <iostream>
#include<bits/stdc++.h>
typedef long long ll;
using ll = long long;

using namespace std;

int LSB(int x) {return (x & -x); }

class FenwickTree
{
private:
    vector<ll> t;
    int n;
public:
    FenwickTree(int size) {t.assign(size+1,0); n=size;}
    ll ps(int i)
    {
        ll ans=0;
        while(i)
        {
            ans+=t[i];
            i-=LSB(i);
        }
        return ans;
    }
    void add(int i,ll v)
    {
        while(i<=n)
        {
            t[i]+=v;
            i+=LSB(i);
        }
    }
};

int main()
{
    int n; cin>>n;
    vector<ll> a(n+1); vector<ll> b(n+1); map<ll,ll> h; for(int i=1;i<=n;i++) {cin>>a[i]; b[i]=a[i]; }
    sort(b.begin()+1,b.end());
    b[0]=0; for(int i=1;i<=n;i++) if(b[i]!=b[i-1]) h[b[i]]=h[b[i-1]]+1; for(int i=1;i<=n;i++) a[i]=h[a[i]];
    FenwickTree ft1(n); FenwickTree ft2(n); ll ans=0;
    for(int i=n;i>=1;i--)
    {
        ans+=ft2.ps(a[i]-1);
        ft2.add(a[i],ft1.ps(a[i]-1));
        ft1.add(a[i],1);
    }
    cout<<ans;
    return 0;
}
