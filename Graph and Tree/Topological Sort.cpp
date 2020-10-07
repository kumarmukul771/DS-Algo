#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
vector <ll> graph[1000006];
vector <ll> vis;
stack <ll> st;
set <ll> s;
void dfs(ll x)
{
    if(!vis[x]){
        vis[x]=1;
    for(auto t:graph[x])
        dfs(t);
    st.push(x);}
    }
int main()
{
    ll n;
    cin>>n;
    vis.assign(1000006,0);
    for(ll i=0;i<n;i++)
    {
        ll u,v;
        cin>>u>>v;
        s.insert(u);
        s.insert(v);
        graph[u].pb(v);
    }
   // cout<<graph[7][0]<<" "<<graph[7][1];
    ll x;
    cin>>x;
    dfs(x);
    set <ll> ::iterator itr;
   // for(itr=s.begin();itr!=s.end();itr++) cout<<*itr<<" ";    cout<<endl;

        for(itr=s.begin();itr!=s.end();itr++)
    {
        if(!vis[*itr])
            dfs(*itr);
    }
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}

