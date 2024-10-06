// Problem Name: Sum of Two Values
// Link to the Problem: https://cses.fi/problemset/task/1640
// Link to the Solution: https://cses.fi/paste/c1d9ab30eb28c35b607e8d/

#include <iostream>
#include<map>
#include<vector>
#include<algorithm>
 
using namespace std;
 
 
 
int main()
{
    int n,x;
    cin>>n>>x;
    vector<pair<long long int,int> > nums(n);
    for(int i=0;i<n;i++)
    {
        long long int a;
        cin>>a;
        nums[i]=make_pair(a,i);
    }
    sort(nums.begin(),nums.begin()+n);
    int eleje=0,vege=n-1;
    while(eleje!=vege && nums[eleje].first+nums[vege].first!=x)
    {
        if(nums[eleje].first+nums[vege].first<x) eleje++;
        else vege--;
    }
    if(eleje!=vege) cout<<nums[eleje].second+1<<" "<<nums[vege].second+1;
    else cout<<"IMPOSSIBLE";
    return 0;
}
