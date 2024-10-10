// Problem Name: Nearest Smaller Values
// Link to the Problem: https://cses.fi/problemset/task/1645/
// Link to the Solution: https://cses.fi/paste/6c229ed497546b1b59e0d0/

#include <iostream>
#include<vector>
 
using namespace std;
 
int main()
{
    int n,minimum;
    cin>>n;
    vector<int>nums(n);
    vector<int>indexes(n);
    cin>>nums[0];
    indexes[0]=0;
    minimum=nums[0];
    for(int i=1;i<n;i++)
    {
        cin>>nums[i];
        if(nums[i]<=minimum)
        {
        minimum=nums[i];
        indexes[i]=0;
        }
        else
        {
            int j=i-1;
            while(j>0 && nums[j]>=nums[i])
            {
                j=indexes[j]-1;;
            }
            indexes[i]=j+1;
        }
 
    }
    for(int i=0;i<n;i++) cout<<indexes[i]<<" ";
    return 0;
}
