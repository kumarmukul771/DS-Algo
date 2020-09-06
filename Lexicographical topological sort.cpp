#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
vector <ll>  graph[1000006];
set <ll> s;
ll in_degree[1000006];
void topological_sort(ll N)
{
    ll cnt=0;
    for(ll i=1;i<=N;i++)
    {
        if(in_degree[i]==0)
            s.insert(i);
    }
    vector <ll> top_order;
    while(!s.empty())
    {
        ll u=*s.begin();
        s.erase(s.begin());
        top_order.pb(u);
        for(ll i=0;i<graph[u].size();i++)
            if(--in_degree[graph[u][i]]==0) s.insert(graph[u][i]);

    cnt++;
    }
    //Cycle found in graph
    if(cnt!=N) {cout<<-1;
    return;}
    for(ll i=0;i<top_order.size();i++) cout<<top_order[i]<<" ";

}
int main()
{
    ll m,n;
    cin>>n>>m;
    for(ll i=0;i<m;i++)
    {
        ll u,v;
        cin>>u>>v;
        graph[u].pb(v);
        in_degree[v]++;
    }
    topological_sort(n);
}


