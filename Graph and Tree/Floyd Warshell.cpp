#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define im int main()
#define WeightedGraph for(ll i=0;i<e;i++) { ll u,v; cin>>u>>v; g[u].pb(v);}
using namespace std;
vector <ll> g[1000006];
im
{
    ll n,m;
    cin>>n>>m;
    ll a[n+1][n+1];
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            if(i==j) a[i][j]=0;
            else a[i][j]=INT_MAX;
        }
    }
    for(ll i=0;i<m;i++)
    {
        ll u,v,wt;
        cin>>u>>v>>wt;
        g[u].pb(v);
        a[u][v]=wt;
    }
   for(ll k=1;k<=n;k++)
    {
        for(ll i=1;i<=n;i++)
        {
            for(ll j=1;j<=n;j++)
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
        }
    }
    //cout<<a[1][1];
    // a[i][j] gives shortest distance between i and j
    for(ll i=1;i<=n;i++)
        {
            for(ll j=1;j<=n;j++)
                cout<<a[i][j]<<" ";
                cout<<endl;
        }
}
