#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> v1[100005],vis;
void BFS2(ll u)
{
    queue <ll> q;
    q.push(u);
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        if(!vis[u])
        {
            vis[u]=1;
            cout<<u<<" ";
        }
        for(auto t:v1[u])
        {
            if(!vis[t])
            {
                cout<<t<<" ";
                vis[t]=1;
                q.push(t);
            }
        }
    }
}

int main()
{
    ll n;
    cin>>n;
    vis.assign(n+1,0);
    ll u,v;
    for(ll i=0;i<n;i++)
    {
        cin>>u>>v;
        v1[v].push_back(u);
        v1[u].push_back(v);
    }

        BFS2(0);
}
