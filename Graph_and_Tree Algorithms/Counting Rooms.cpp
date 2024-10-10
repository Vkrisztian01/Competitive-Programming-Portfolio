// Problem Name: Counting Rooms
// Link to the Problem: https://cses.fi/problemset/task/1192
// Link to the Solution: https://cses.fi/paste/629f26c41c504e7893e641/

// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
 
int n,m,cnt;
vector<string> grid;
 
void dfs(int i,int j)
{
	if(i<0 || n<=i || j<0 || m<=j || grid[i][j]=='#') return;
	grid[i][j]='#';
	dfs(i-1,j); dfs(i+1,j);
	dfs(i,j-1); dfs(i,j+1);
}
 
int main() {
	cin>>n>>m; grid.resize(n); cnt = 0;
	for(int i=0;i<n;i++) cin>>grid[i];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(grid[i][j]!='.') continue;
			++cnt;
			dfs(i,j);
		}
	}
	cout<<cnt;
}
