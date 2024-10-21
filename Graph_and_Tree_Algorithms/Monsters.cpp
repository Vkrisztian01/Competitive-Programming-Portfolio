// Problem Name: Monsters
// Link to the Problem: https://cses.fi/problemset/task/1194
// Link to the Solution: https://cses.fi/paste/9db494c12a78089c93faac/

#include <iostream>
#include<bits/stdc++.h>
#define INF 1000000007
 
using namespace std;
 
void bfs2(queue<pair<int,pair<int,int> > > &q,vector<string> &grid,vector<vector<int> > &cost,int n,int m)
{
    while(!q.empty())
    {
        int i,j,c; c=q.front().first; i=q.front().second.first; j=q.front().second.second; q.pop();
        if(i<0 || n<=i || j<0 || m<=j || grid[i][j]=='#' || cost[i][j]!=INF) continue;
        cost[i][j]=c;
        q.push(make_pair(c+1,make_pair(i-1,j)));
        q.push(make_pair(c+1,make_pair(i+1,j)));
        q.push(make_pair(c+1,make_pair(i,j-1)));
        q.push(make_pair(c+1,make_pair(i,j+1)));
    }
}
 
void bfs1(queue<pair<pair<int,char>,pair<int,int> > > &q,vector<string> &grid,vector<vector<int> > &cost,int n,int m)
{
    while(!q.empty())
    {
 
        int c,i,j; char how; c=q.front().first.first; how=q.front().first.second; i=q.front().second.first; j=q.front().second.second; q.pop();
        if(i<0 || n<=i || j<0 || m<=j || grid[i][j]=='#' || cost[i][j]!=INF) continue;
        cost[i][j]=c;
        grid[i][j]=how;
        q.push(make_pair(make_pair(c+1,'U'),make_pair(i-1,j)));
        q.push(make_pair(make_pair(c+1,'D'),make_pair(i+1,j)));
        q.push(make_pair(make_pair(c+1,'L'),make_pair(i,j-1)));
        q.push(make_pair(make_pair(c+1,'R'),make_pair(i,j+1)));
    }
}
 
void solve(vector<string> grid,int i,int j)
{
    cout<<"YES"<<"\n";
    string ans="";
    while(grid[i][j]!='*')
    {
        char e = grid[i][j];
        ans+=e;
        if(e=='U') i++;
        if(e=='D') i--;
        if(e=='L') j++;
        if(e=='R') j--;
    }
   // if(ans.empty()) return;
    reverse(ans.begin(),ans.end());
    cout<<ans.size()<<"\n";
    cout<<ans;
}
 
int main()
{
    int n,m; cin>>n>>m;
    vector<string> grid1(n);vector<string>grid2(n);
    vector<vector<int> > cost1(n,vector<int>(m,INF)); vector<vector<int> > cost2(n,vector<int>(m,INF));
    queue<pair<int,pair<int,int> > >q2; queue<pair<pair<int,char>,pair<int,int> > > q1;
    for(int i=0;i<n;i++)
    {
       cin>> grid1[i]; grid2[i]=grid1[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid1[i][j]=='A') q1.push(make_pair(make_pair(0,'*'),make_pair(i,j)));
            if(grid1[i][j]=='M') q2.push(make_pair(0,make_pair(i,j)));
        }
    }
    bfs2(q2,grid2,cost2,n,m);
    bfs1(q1,grid1,cost1,n,m);
    for(int i=0;i<n;i++)
    {
        if(cost1[i][0]<cost2[i][0])
        {
            solve(grid1,i,0);
            return 0;
        }
        if(cost1[i][m-1]<cost2[i][m-1])
        {
            solve(grid1,i,m-1);
            return 0;
        }
    }
    for(int i=0;i<m;i++)
    {
        if(cost1[0][i]<cost2[0][i])
        {
            solve(grid1,0,i);
            return 0;
        }
         if(cost1[n-1][i]<cost2[n-1][i])
        {
            solve(grid1,n-1,i);
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}
