// Problem Name: Minimizing Coins
// Link to the Problem: https://cses.fi/problemset/task/1634
// Link to the Solution: https://cses.fi/paste/75348d2b973a91df6ff1e3/

#include <iostream>
#include<map>
#include<queue>
 
using namespace std;
 
vector<long long int> nums;
int n;
long long int k;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    cin>>n>>k;
    nums.resize(n);
    for(int i=0;i<n;i++) cin>>nums[i];
     int * arr=new  int[1000001];
    for(int i=0;i<=1000000;i++) arr[i]=99999999;
    arr[0]=0;
    for(int i=1;i<=k;i++)
    {
        for(auto x:nums)
        {
            if(i>=x) arr[i]=min(arr[i],arr[i-x]+1);
        }
    }
    if(arr[k]==99999999) cout<<-1;
    else cout<<arr[k];
    return 0;
}
