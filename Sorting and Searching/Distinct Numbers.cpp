// Problem Name: Distinct Numbers
// Link to The Problem: https://cses.fi/problemset/task/1621
// Link to the Solution: https://cses.fi/paste/d6d832d212a65b3f6059db/

#include <iostream>
#include<set>
 
using namespace std;
 
int main()
{
    set<long long int>nums;
    long long int n;
    cin>>n;
    while(n)
    {
        --n;
        long long int a;
        cin>>a;
        nums.insert(a);
    }
    cout<<nums.size();
    return 0;
}
