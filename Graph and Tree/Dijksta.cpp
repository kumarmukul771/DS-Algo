#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
vector < pair<ll,ll> > graph[1000006];
vector <ll> Dist(1000006,INT_MAX);
void Dijkstra(ll src)
{
   typedef pair <ll,ll> ipair;
    priority_queue <ipair , vector <ipair> , greater <ipair> > pq;
    pq.push(make_pair(0,src));
    while(!pq.empty())
    {
        ll u=pq.top().second;
        pq.pop();
        for(ll i=0;i<graph[u].size();i++)
        {
            ll v=graph[u][i].first;
            ll wgt=graph[u][i].second;
            if(Dist[v]>Dist[u]+wgt)
            {
                Dist[v]=Dist[u]+wgt;
                pq.push(make_pair(Dist[v],v));
            }
        }
    }
}
int main()
{
    ll n,m;
    //n=no. of vertices m=no. of edges
    cin>>n>>m;
    for(ll i=0;i<m;i++)
    {
        ll u,v,wt;
        cin>>u>>v>>wt;
        graph[u].pb(make_pair(v,wt));
        graph[v].pb(make_pair(u,wt));
    }
    ll x;
    cin>>x;
    Dist[x]=0;
    //distance of other vertices from x
    Dijkstra(x);
    for(ll i=1;i<=n;i++)
        cout<<Dist[i]<<" ";
}
