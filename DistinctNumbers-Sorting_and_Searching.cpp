//Name: Distinct Numbers
//Category: Sorting and Searching
//Link: https://cses.fi/problemset/task/1621


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
