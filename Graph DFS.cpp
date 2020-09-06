#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> v[100005],vis;
ll ans=0;
ll dfs(ll node,ll par)
{
    ll maxi=0,max2=0;
    for(ll x:v[node])
    {
        if(x!=par)
        {
            ll val=dfs(x,node);
            if(val>=maxi)
            {
                max2=maxi;
                maxi=val;
            }
            else if(val>max2) max2=val;
        }
    }
   if(maxi+max2>ans) ans=maxi+max2;return maxi+1;
}

int main()
{
    ll n;
    cin>>n;
    vis.assign(n+1,0);
    ll u,v1;
    for(ll i=0;i<n;i++)
    {
        cin>>u>>v1;

        v[u].push_back(v1);
    }
   cout<< dfs(1,1);

}


