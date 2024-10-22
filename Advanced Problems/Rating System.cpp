// Name of the Problem: Rating System
// Link to the Problem: https://codeforces.com/problemset/problem/1845/D
// Link to the Solution: https://codeforces.com/contest/1845/submission/239066608

#include <iostream>
#include<set>

using namespace std;

const long long int j=-1*(1e18);
int n;
long long int nums[300001];
long long int elorol[300001];
long long int hatulrol[300002];
long long int k;
set<pair<int,long long int> > seged;

void solve()
{
    cin>>n;
    elorol[0]=0;
    hatulrol[n+1]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>nums[i];
        elorol[i]=nums[i]+elorol[i-1];
    }
    seged.clear();
    seged.insert(make_pair(n+1,0));
    long long int maxos=0;
    for(int i=n;i>=0;i--)
    {
        hatulrol[i]=nums[i]+hatulrol[i+1];
        if(hatulrol[i]>maxos)
        {
            maxos=hatulrol[i];
            seged.insert(make_pair(i,maxos));
        }
    }
    k=0;
    maxos=0;
    for(int i=0;i<=n;i++)
    {
        auto it=seged.upper_bound(make_pair(i,-1*j));
        if(maxos<elorol[i]+it->second)
        {
            maxos=elorol[i]+it->second;
            k=elorol[i];
        }
       // cout<<i<<": "<<elorol[i]<<", "<<it->second<<endl;
    }
   // for(auto x:seged) cout<<x.first<<","<<x.second<<";--------;";
   cout<<k<<"\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}
