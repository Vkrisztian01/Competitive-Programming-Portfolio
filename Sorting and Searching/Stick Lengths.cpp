// Problem Name: Stick Lengths
// Link to the Problem: https://cses.fi/problemset/task/1074
// Link to the Solution: https://cses.fi/paste/e86fa6b16e6f67af60bfef/

#include <iostream>
#include<vector>
#include<cmath>
#include<algorithm>
 
using namespace std;
 
int main()
{
    int_fast64_t s=0,n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
        s+=nums[i];
    }
    sort(nums.begin(),nums.begin()+n);
    int_fast64_t j1=(n-1)/2-1;
    int_fast64_t j2=(n-1)/2;
    int_fast64_t j3=(n-1)/2+1;
    int_fast16_t cost1=0,cost2=0,cost3=0;
    if(n==1) cout<<0;
    else if(n==2) cout<<nums[2]-nums[1];
    else
        {
            for(auto x:nums)
            {
                cost1+=abs(nums[j1]-x);
                cost2+=abs(nums[j2]-x);
                cost3+=abs(nums[j3]-x);
            }
            cout<<min(cost1,min(cost2,cost3));
        }
 
    return 0;
}
