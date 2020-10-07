#include<bits/stdc++.h>
using namespace std;
#define ll           long long
#define rep(i,j,n)   for(ll i=j;i<n;i++)
#define scn(a)       scanf("%lld",&a)
#define nl         printf("\n")
#define scns(a,b)    scanf("%lld %lld",&a,&b)
#define print(a)     printf("%lld",a)
#define tc           ll t; scn(t); while(t--)
#define vec          vector<ll>
#define pb           push_back
#define pairs        pair<ll,ll>
#define f            first
#define s            second
#define all(v)       v.begin(),v.end()
#define srt(v)       sort(v.rbegin(),v.rend())
#define mem(a,b)     memset(a,b,sizeof(a))
#define im           int main()
#define maxx         5000005
#define inf          LLONG_MAX
#define zer          LLONG_MIN
const ll N = 1000006;
vector<ll> graph[N];
vector<ll> cycles[N];
ll cyclenumber;
ll color[N];
ll par[N];
// mark with unique numbers
ll mark[N];
// Function to mark the vertex with
// different colors for different cycles
void dfs_cycle(ll u, ll p)
{

	// already (completely) visited vertex.
	if (color[u] == 2) {
		return;
	}

	// seen vertex, but was not completely visited -> cycle detected.
	// backtrack based on parents to find the complete cycle.
	if (color[u] == 1) {

		cyclenumber++;
		ll cur = p;
		mark[cur] = cyclenumber;

		// backtrack the vertex which are
		// in the current cycle thats found
		while (cur != u) {
			cur = par[cur];
			mark[cur] = cyclenumber;
		}
		return;
	}
	par[u] = p;

	// partially visited.
	color[u] = 1;

	// simple dfs on graph
	for (ll v : graph[u]) {

		// if it has not been visited previously
		if (v == par[u]) {
			continue;
		}
		dfs_cycle(v, u);
	}

	// completely visited.
	color[u] = 2;
}
// Function to print the cycles
void printCycles(ll edges)
{

	// push the edges that into the
	// cycle adjacency list


	// print all the vertex with same cycle
	for (ll i = 1; i <= cyclenumber; i++) {
		// Print the i-th cycle
		cout << "Cycle Number " << i << ": ";
		for (ll x : cycles[i])
			cout << x << " ";
		cout << endl;
	}
}

// Driver Code
int main()
{

	ll n,m;
	scns(n,m);
	rep(i,0,m)
	{
	    ll u,v;
	    scns(u,v);
	    graph[u].pb(v);
	    graph[v].pb(u);
	}
	dfs_cycle(1, 0);
	for (ll i = 1; i <= m; i++) {
		if (mark[i] != 0)
			cycles[mark[i]].pb(i);
	}
    // function to print the cycles
	printCycles(m);
}

