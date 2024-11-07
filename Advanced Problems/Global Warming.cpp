// Link to the Problem: https://oj.uz/problem/view/CEOI18_glo
// Origin of the Problem: CEOI 2018

#include <iostream>
#include <bits/stdc++.h>
#define lsb(s) (s & -s)
typedef long long ll;
const int maxn = 5 * 1e5;

using namespace std;

class SegmentTree
{
private:
    vector<int> t;

public:
    SegmentTree()
    {
        t.assign(4 * maxn, 0);
    }

    int query(int node, int tl, int tr, int l, int r)
    {
        if (l > r) return 0;
        if (tl == l && tr == r) return t[node];

        int tm = (tl + tr) / 2;

        return max(query(node * 2, tl, tm, l, min(r, tm)),
                   query(node * 2 + 1, tm + 1, tr, max(tm + 1, l), r));
    }

    void change(int node, int tl, int tr, int i, int k)
    {
        if (tl == tr) t[node] = max(t[node], k);
        else
        {
            int tm = (tl + tr) / 2;

            if (i <= tm) change(node * 2, tl, tm, i, k);
            else change(node * 2 + 1, tm + 1, tr, i, k);

            t[node] = max(t[node * 2], t[node * 2 + 1]);
        }
    }
};

int main()
{
    int n, x;
    cin >> n >> x;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<ll> b;
    for (int i = 0; i < n; i++)
    {
        b.push_back(a[i]);
        b.push_back(a[i] - x);
    }

    sort(b.begin(), b.end());
    int cnt = 0;
    map<ll, ll> s;
    for (auto value : b)
        if (s[value] == 0)
            s[value] = ++cnt;

    SegmentTree st1;
    SegmentTree st2;

    for(int v : a)
    {
        int k = s[v] ;
        int l = st1.query(1 , 1 , maxn , 1 , k - 1) ;
        st1.change(1 , 1 , maxn , k , l + 1) ;

        int k2 = s[v - x] ;
        int l2 = st2.query(1 , 1 , maxn , 1 , k - 1) ;
        st2.change(1 , 1 , maxn , k , l2 + 1) ;
        st2.change(1 , 1 , maxn , k2 , l + 1) ;

    }

    int ans = max( st1.query(1 , 1 , maxn , 1 , maxn) ,
                  st2.query(1 , 1 , maxn , 1 , maxn) ) ;

    cout << ans ;

    return 0;
}
