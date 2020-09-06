#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define im int main()
#define WeightedGraph for(ll i=0;i<e;i++){ ll x,y,wt; cin>>x>>y>>wt; g[x].pb(make_pair(y,wt)); }
using namespace std;
vector < pair<ll,ll> > g[1000006];
vector <ll> dist(1000006,INT_MAX);
ll negativeWeightCycle=0;
void BellmanFord(ll v,ll e)
{
   for(ll i=0;i<v-1;i++)
    {
        for(ll j=1;j<=v;j++)
            {
                for(ll k=0;k<g[j].size();k++)
                {
                    ll u=g[j][k].first;
                    ll wt=g[j][k].second;
                    if(dist[u]>dist[j]+wt)
                        dist[u]=dist[j]+wt;
                }
            }
    }
    for(ll j=1;j<=v;j++)
    {
        for(ll k=0;k<g[j].size();k++)
            {
                    ll u=g[j][k].first;
                    ll wt=g[j][k].second;
                    if(dist[u]!=INT_MAX&&dist[u]>dist[j]+wt)
                    {
                        negativeWeightCycle=1;
                        return;
                    }

                }
    }
}
im
{
    ll v,e;
    cin>>v>>e;
    WeightedGraph
    ll src;
    cin>>src;
    dist[src]=0;
    BellmanFord(v,e);
    if(negativeWeightCycle==0)
    {
        for(ll i=1;i<=v;i++)
        cout<<i<<" "<<dist[i]<<endl;
    }
    else
         cout<<"\nGraph has -ve weight cycle";
}
