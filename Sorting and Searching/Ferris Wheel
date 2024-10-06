// Problem Name: Ferris Wheel
// Link to the Problem: https://cses.fi/problemset/task/1090
// Link to the Solution: https://cses.fi/paste/3b44cd361df4eef4606514/

#include <iostream>
#include<vector>
#include<algorithm>
#include<deque>
 
using namespace std;
 
int main()
{
    long long int n,k,db=0;
    cin>>n>>k;
    deque<long long int>nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    sort(nums.begin(),nums.begin()+nums.size());
 
    while(!nums.empty())
    {
        db++;
        if( nums.size()>=2 && nums.front()+nums.back()<=k)
        {
            nums.pop_back();
            nums.pop_front();
        }
        else
        {
            nums.pop_back();
        }
    }
 
    cout<<db;
 
    return 0;
}
