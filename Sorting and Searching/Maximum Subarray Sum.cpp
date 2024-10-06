// Problem Name: Maximum Subarray Sum
// Link to the Problem: https://cses.fi/problemset/task/1643
// Link to the Solution: https://cses.fi/paste/720a83be11e80d18607f3f/

#include <iostream>
#include<vector>
#include<algorithm>
 
using namespace std;
 
int main()
{
    long long int n,k=0,maxk=-1000000009;
    cin>>n;
    while(n)
    {
        --n;
        long long int a;
        cin>>a;
        k+=a;
        maxk=max(maxk,k);
        if(k<0) k=0;
 
 
    }
    cout<<maxk;
    return 0;
}
