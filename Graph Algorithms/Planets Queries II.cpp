// Problem Name: Planets Queries II
// Link to the Problem: https://cses.fi/problemset/task/1160
// Link to the Solution: https://cses.fi/paste/af00b6ab530960c694e88b/

#include <iostream>
#include <vector>
using namespace std;
 
int n, q, cnt, a, b;
vector<int> adj;
vector<vector<int> > rev;
vector<vector<int> > bl;
vector<int> kor;
vector<int> depth;
vector<int> d;
vector<int> seged;
vector<int> korsize;
 
void dfs1(int v)
{
    --d[v];
    if(d[v]) return;
    kor[v]=0;
    dfs1(adj[v]);
}
 
void dfs2(int v, int c, int x)
{
    depth[v] = c;
    seged[v] = x;
    for(int to : rev[v]) dfs2(to, c+1, x);
}
 
void dfs3(int v, int c)
{
    if(depth[v]) return;
    korsize[cnt]++;
    depth[v] = c;
    kor[v] = cnt;
    dfs3(adj[v], c+1);
}
 
int tav(int a, int b)
{
    if(kor[a] != 0 && kor[a] != kor[b]) return -1;
    if(kor[a] == kor[b] && kor[a] != 0)
    {
        if(depth[a] <= depth[b]) return depth[b] - depth[a];
        return korsize[kor[a]] - depth[a] + depth[b];
    }
    if(kor[b] != 0 && kor[seged[a]] == kor[b]) return depth[a] + tav(seged[a], b);
    if(depth[a] < depth[b]) return -1;
    int ans = depth[a] - depth[b];
    for(int i = 19; i >= 0; i--) if(depth[a] - (1 << i) >= depth[b]) a = bl[i][a];
    if(a == b) return ans;
    return -1;
}
 
int main()
{
    cin >> n >> q;
    adj.resize(n+1);
    rev.resize(n+1);
    bl.resize(20, vector<int>(n+1));
    kor.assign(n+1, -1);
    depth.assign(n+1, 0);
    d.assign(n+1, 0);
    seged.resize(n+1);
    korsize = {0};
 
    for(int i = 1; i <= n; i++)
    {
        cin >> adj[i];
        d[adj[i]]++;
        rev[adj[i]].push_back(i);
        bl[0][i] = adj[i];
    }
 
    for(int i = 1; i <= n; i++)
    {
        if(d[i] == 0 && kor[i]==-1)
        {
            d[i] = 1;
            dfs1(i);
        }
    }
 
    for(int i = 1; i < 20; i++)
    {
        for(int v = 1; v <= n; v++)
        {
            if(kor[v] == -1 || kor[bl[i-1][v]] == -1) bl[i][v] = bl[i-1][v];
            else bl[i][v] = bl[i-1][bl[i-1][v]];
        }
    }
 
 
for(int i = 1; i <= n; i++)
    {
        if(kor[i] == 0 && kor[adj[i]] !=0 ) dfs2(i, 1, adj[i]);
    }
 
 
    cnt = 1;
    for(int i = 1; i <= n; i++)
    {
        if(kor[i] == -1)
        {
            korsize.push_back(0);
            dfs3(i, 1);
            cnt++;
        }
    }
 
 
 
    while(q--)
    {
        cin >> a >> b;
        cout << tav(a, b) << endl;
    }
 
    return 0;
}
