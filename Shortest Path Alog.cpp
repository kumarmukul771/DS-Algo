#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
vector <ll> graph[1000006];
ll Distance[1000006];
void path(ll s)
{
    memset(Distance,-1,sizeof(Distance));
    Distance[s]=0;
    queue <ll> q;
    q.insert(s);
    while(!q.empty())
    {
        ll v=q.
    }
}
int main()
{
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        ll u,v;
        cin>>u>>v;
        graph[u].pb(v);
    }
    ll s;
    cin>>s;
    path(s);
}
