// Name of the Problem: Vasiliy's Multiset
// Link to the Problem: https://codeforces.com/contest/706/problem/D
// Link to the Solution: https://codeforces.com/contest/706/submission/257951604

#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
typedef long long ll;
using ll = long long;

using namespace std;

ll n=1;
ll trie[10000000][2];
ll darab[10000000];
ll kettohatany[31];

string binaryform(ll number)
{
    string ki="";
    for(ll i=30;i>=0;i--)
    {
        if(number>=kettohatany[i])
        {
            number-=kettohatany[i];
            ki+='1';
        }
        else ki+='0';
    }
    return ki;
}

ll decimalform(string s)
{
    ll ki=0;
    for(ll i=0;i<=30;i++)
    {
        if(s[i]=='1')
        {
            ki+=kettohatany[30-i];
        }

    }
    return ki;
}

void insert(ll number)
{
    string s=binaryform(number);
    ll v=1;
    ll seged;
    for(auto szamjegy: s)
    {
        seged=darab[trie[v][szamjegy-'0']];
        if(!seged)
        {
            ++n;
            trie[v][szamjegy-'0']=n;
        }
        v=trie[v][szamjegy-'0'];
        darab[v]++;
    }
}

void torol(ll number)
{
    string s=binaryform(number);
    ll akt=1;
    for(auto szamjegy:s)
    {
        akt=trie[akt][szamjegy-'0'];
        darab[akt]--;
    }
}

ll szamit(ll number)
{
    string beszam=binaryform(number);
    string kiszam="";
    ll seged;
    ll masik;
    ll v=1;
    for(auto szamjegy:beszam)
    {
        seged=szamjegy-'0';
        masik=darab[trie[v][1-seged]];
        if(masik)
        {
            kiszam+="1";
            v=trie[v][1-seged];
            continue;
        }
        kiszam+="0";
        v=trie[v][seged];
    }
    cout << decimalform(kiszam)<<"\n";
}



int main()
{
    kettohatany[0]=1;
    for(ll i=1;i<=30;i++)
    {
        kettohatany[i]=2*kettohatany[i-1];
    }
    insert(0);
    ll q;
    string be1;
    ll be2;
    cin>>q;
    while(q--)
    {
        cin>>be1>>be2;
        if(be1=="+")
        {
            insert(be2);
            continue;
        }
        if(be1=="-")
        {
            torol(be2);
            continue;
        }
        szamit(be2);
    }
    return 0;
}
