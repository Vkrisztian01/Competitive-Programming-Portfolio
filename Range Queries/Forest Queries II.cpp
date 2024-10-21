// Problem Name: Forest Queries II
// Link to the Problem: https://cses.fi/problemset/task/1739
// Link to the Solution: https://cses.fi/paste/62b25bd5f9ad8525918d47/

#include <iostream>
#include<bits/stdc++.h>
typedef long long ll;
using ll = long long;
#define LSOne(S) (S & (-S))
 
using namespace std;
 
class FenwickTree
{
private:
    vector<vector<int> > t;
public:
    FenwickTree() {t.assign(1001,vector<int>(1001,0));}
 
    int prefix(int y,int x)
    {
        int ans=0;
        int i=y;
        while(i)
        {
            int j=x;
            while(j)
            {
                ans+=t[i][j];
                j-=LSOne(j);
            }
            i-=LSOne(i);
        }
        return ans;
    }
 
    void adding(int y,int x,int v)
    {
        int i=y;
        while(i<=1000)
        {
            int j=x;
            while(j<=1000)
            {
                t[i][j]+=v;
                j+=LSOne(j);
            }
            i+=LSOne(i);
        }
    }
};
 
int main()
{
    int n,q;
    cin>>n>>q;
    vector<string> in(n);
    FenwickTree ft;
    for(int i=0;i<n;i++)
    {
        cin>>in[i];
        for(int j=0;j<n;j++)
        {
            if(in[i][j]=='*') ft.adding(i+1,j+1,1);
        }
    }
    while(q--)
    {
        int a,x1,x2,y1,y2;
        cin>>a;
        if(a==1)
        {
            cin>>y1>>x1;
            if(in[y1-1][x1-1]=='*')
            {
                in[y1-1][x1-1]='.';
                ft.adding(y1,x1,-1);
            }
            else
            {
                in[y1-1][x1-1]='*';
                ft.adding(y1,x1,1);
            }
        }
        else
        {
            cin>>y1>>x1>>y2>>x2;
            cout<<ft.prefix(y2,x2)-ft.prefix(y1-1,x2)-ft.prefix(y2,x1-1)+ft.prefix(y1-1,x1-1)<<endl;
        }
    }
    return 0;
}
