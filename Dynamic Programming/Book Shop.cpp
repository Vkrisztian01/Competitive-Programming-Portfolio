// Problem Name: Book Shop
// Link to the Problem: https://cses.fi/problemset/task/1158
// Link to the Solution: https://cses.fi/paste/d0d1e9618bfc547b5f8847/

#include <iostream>
#include<vector>
#include<algorithm>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    vector<pair<int,int> > books(n);
    for(int i=0;i<n;i++) cin>>books[i].first;
    for(int i=0;i<n;i++) cin>>books[i].second;
    vector<vector<int> > matrix(n+1, vector<int>(k+1,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            matrix[i+1][j]=matrix[i][j];
            if(j>=books[i].first)
            {
                matrix[i+1][j]=max(matrix[i+1][j],matrix[i][j-books[i].first]+books[i].second);
            }
 
        }
    }
   cout<<matrix[n][k];
 
 
 
 
    return 0;
}
