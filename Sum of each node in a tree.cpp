#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
vector <ll> tree[1000006];
ll sum[1000006];
void dfs(ll x,ll par)
{

  if(tree[x].size()==1) sum[x]=x;
  else
  {
      sum[x]=x;
      for(auto t:tree[x])
      {
          if(t!=par){         dfs(t,x);
          sum[x]+=sum[t];
      }
  }
}}
int main()
{
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        ll u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    ll root;
    cin>>root;
    dfs(root,-1);
    ll x;
    cin>>x;
    cout<<sum[x];
}

