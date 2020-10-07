#include<bits/stdc++.h>
using namespace std;
#define ll           long long
#define rep(i,j,n)   for(ll i=j;i<n;i++)
#define scn(a)       scanf("%lld",&a)
#define scns(a,b)    scanf("%lld %lld",&a,&b)
#define print(a)     printf("%lld",a)
#define tc           ll t; scn(t); while(t--)
#define inp          scn(n); rep(i,0,n) scn(a[i])
#define vec          vector<ll>
#define pb           push_back
#define pairs        pair<ll,ll>
#define f            first
#define s            second
#define all(v)       v.begin(),v.end()
#define srt(v)       sort(v.rbegin(),v.rend())
#define mem(a,b)     memset(a,b,sizeof(a))
#define im           int main()
#define maxx         500005
#define inf          LLONG_MAX
#define zer          LLONG_MIN
ll mod=1e9+7,n,m,a[maxx];
vec v1[maxx],vis;
ll up[maxx][30],in[maxx],out[maxx];
ll lim,query,tim=1;

void dfs(ll u,ll par){
	up[u][0]=par;
	in[u]=tim++;
	rep(i,1,lim+1){
		up[u][i]=up[up[u][i-1]][i-1];
	}
	for(auto it:v1[u])
		if(it!=par)
			dfs(it,u);
	out[u]=tim++;
}
bool isancestor(ll u,ll v)
{
	return (in[u]<in[v] && out[u]>out[v]);
}
ll lca(ll u,ll v){
	if(isancestor(u,v))
		return u;
	if(isancestor(v,u))
		return v;
	if(u==v)
		return u;
	for(ll i=lim;i>=0;i--){
		if(!isancestor(up[u][i],v))
			u=up[u][i];
	}
	return up[u][0];
}
im{
	scns(n,m);
	while(m--)
        {
		ll a,b;
		scns(a,b);
		v1[a].pb(b);  v1[a].pb(b);
	}
	lim=ceil(log2(n)*1.0);
	dfs(1,1);

	scn(query);
	while(query--){
		ll a,b;
		scns(a,b);
		print(lca(a,b));
		printf("\n");
	}
}
