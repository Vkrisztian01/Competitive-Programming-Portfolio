// Name of the Problem: Missile Silos
// Link to the Problem: https://codeforces.com/contest/144/problem/D
// Link to the Solution: https://codeforces.com/contest/144/submission/209611073

#include <iostream>
#include<vector>
#include<set>

    using namespace std;

    int main()
    {
        int n,m,l,s,db=0;
        cin>>n>>m>>s;
        vector<vector<pair<int,int> > >   G(n+1);
        vector<int>cost(n+1);
        for(int i=0;i<=n;i++) cost[i]=-1;
        while(m)
        {
            --m;
            int a,b,c;
            cin>>a>>b>>c;
            G[a].push_back(make_pair(c,b));
            G[b].push_back(make_pair(c,a));

        }
        cin>>l;
        //johet a dijstra
        set<pair<int,int> > seged;
        seged.insert(make_pair(0,s));
        while(!seged.empty())
        {
            int vertex=seged.begin()->second;
            int price=seged.begin()->first;
            seged.erase(seged.begin());
            if(cost[vertex]==-1)
            {
                cost[vertex]=price;
                for(auto x:G[vertex]) seged.insert(make_pair(price+x.first,x.second));
            }
        }
        set<pair<pair<int,int>,int> > points;
        for(int i=1;i<=n;i++)
        {
            if(cost[i]==l) db++;
            else
            {
                if(cost[i]<l)
                {
                    for(auto x:G[i])
                    {
                        if(cost[i]+x.first>l && cost[x.second]+x.first-l+cost[i]>=l)
                        {
                            if(i<x.second)
                            {
                                points.insert(make_pair(make_pair(i,x.second),l-cost[i]));
                            }
                            else
                            {
                                points.insert(make_pair(make_pair(x.second,i),x.first-l+cost[i]));
                            }
                        }
                    }
                }
            }
        }
        db+=points.size();
        cout<<db;
        return 0;
    }
