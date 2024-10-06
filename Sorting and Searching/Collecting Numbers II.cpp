// Problem Name: Collecting Numbers II
// Link to the Problem: https://cses.fi/problemset/task/2217
// Link to the Solution: https://cses.fi/paste/43004f15049756be6136ea/

#include <iostream>
#include<vector>
#include<set>
#include<map>
#include<cmath>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    int n,m,db=0;
    cin>>n>>m;
    vector<int>indexek(200001,0);
    vector<int>nums(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>nums[i];
        if(indexek[nums[i]-1]==0) db++;
        indexek[nums[i]]=i;
    }
    vector<int>solutions(m);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        a=nums[a];
        b=nums[b];
        int k=0;
        if(indexek[a]<indexek[a-1]) k++;
        if(indexek[a]>indexek[a+1]) k++;
        if(indexek[b]<indexek[b-1] && b-1!=a) k++;
        if(indexek[b]>indexek[b+1] && b+1!=a) k++;
        int seged=indexek[a];
        indexek[a]=indexek[b];
        indexek[b]=seged;
        nums[indexek[a]]=a;
        nums[indexek[b]]=b;
        if(indexek[a]<indexek[a-1]) k--;
        if(indexek[a]>indexek[a+1]) k--;
        if(indexek[b]<indexek[b-1] && b-1!=a) k--;
        if(indexek[b]>indexek[b+1] && b+1!=a) k--;
        db-=k;
        solutions[i]=db;
    }
    for(auto x:solutions) cout<<x<<"\n";
    return 0;
}
