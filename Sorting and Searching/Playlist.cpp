// Problem Name: Playlist
// Link to the Problem: https://cses.fi/problemset/task/1141
// Link to the Solution: https://cses.fi/paste/400b37b50a0a8e3b6137b2/

#include <iostream>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
 
using namespace std;
 
class sequence
{
public:
    queue<int>sor;
    set<int>elemek;
 
    void torol(int x)
    {
        while(sor.front()!=x)
        {
            elemek.erase(sor.front());
            sor.pop();
        }
        elemek.erase(sor.front());
        sor.pop();
    }
 
    void fuz(int x)
    {
        elemek.insert(x);
        sor.push(x);
    }
 
    bool megvan(int x)
    {
        return elemek.count(x);
    }
    int hossz()
    {
        return elemek.size();
    }
 
 
};
 
int main()
{
    int n,m=0;
    ios_base::sync_with_stdio(false);
    cin>>n;
    sequence e;
    while(n)
    {
        n--;
        int x;
        cin>>x;
        if(e.megvan(x))
        {
            e.torol(x);
            e.fuz(x);
        }
        else
        {
            e.fuz(x);
            m=max(m,e.hossz());
        }
 
    }
    cout<<m;
 
    return 0;
}
