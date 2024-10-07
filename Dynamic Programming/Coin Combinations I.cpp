// Problem Name: Coin Combinations I
// Link to the Problem: https://cses.fi/problemset/task/1635
// Link to the Solution: https://cses.fi/paste/f3207fec4bc7de1e6ff28f/

#include <iostream>
#include<vector>
 
using namespace std;
 
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    long long int* arr=new long long int[1000001];
    for(int i=0;i<=1000000;i++) arr[i]=0;
    arr[0]=1;
    for(int i=0;i<=k;i++)
    {
        for(auto x:nums)
        {
            if(i>=x)
            {
                arr[i]+=arr[i-x];
                if(arr[i]>=1000000007) arr[i]-=1000000007;
            }
        }
    }
    cout<<arr[k];
    return 0;
}
