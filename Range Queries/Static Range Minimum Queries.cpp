// Problem Name: Static Range Minimum Queries
// Link to the Problem: https://cses.fi/problemset/task/1647
// Link to the Solution: https://cses.fi/paste/987ae9da36c2bea69ea3b4/

#include <iostream>
#include<bits/stdc++.h>
typedef long long ll;
 
using namespace std;
 
class SparseTable
{
private:
    int n;
    vector<vector<int> > t;
public:
    SparseTable(int s)
    {
        n = s;
        t.resize(20,vector<int>(n+1));
    }
 
    void build(vector<int> &v)
    {
        for(int i=1;i<=n;i++) t[0][i] = v[i];
        for(int i=1;i<20;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if((j + (1<<i-1) ) > n) {t[i][j] = t[i-1][j]; continue; }
                t[i][j] = min(t[i-1][j],t[i-1][j+(1<<i-1)]);
            }
        }
    }
 
    int query(int a,int b)
    {
        int ans = INT_MAX;
        int k = b - a + 1;
        for(int i=19;i>=0;i--)
        {
            if((k & (1<<i)))
            {
                ans = min(ans,t[i][a]);
                a += (1<<i);
            }
        }
        return ans;
    }
};
 
int main()
{
    int n,q; cin>>n>>q;
    vector<int> v(n+1); for(int i=1;i<=n;i++) cin>>v[i];
    SparseTable st(n); st.build(v);
    while(q--)
    {
        int a,b; cin>>a>>b;
        cout<<st.query(a,b)<<"\n";
    }
    return 0;
}
