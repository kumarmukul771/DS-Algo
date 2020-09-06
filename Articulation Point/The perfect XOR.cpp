#include<bits/stdc++.h>
using namespace std;
#define ll           long long
#define rep(i,j,n)   for(ll i=j;i<n;i++)
#define scn(a)       scanf("%lld",&a)
#define scns(a,b)    scanf("%lld %lld",&a,&b)
#define print(a)     printf("%lld\n",a)
#define tc           ll t; scn(t); while(t--)
#define vec          vector<ll>
#define pb           push_back
#define pairs        pair<ll,ll>
#define f            first
#define s            second
#define all(v)       v.begin(),v.end()
#define mem(a,b)     memset(a,b,sizeof(a))
#define maxx         500005
#define inf          INT_MAX
const int N=300005;
ll n,m,q,a[N];
vector <int> v[N];
ll dis[N],low[N],times=1,par[N],vis[N],ap[N],w[N],ans=-1,sum[N],tot;


void dfs(ll x, ll p)
{
    vis[x]=1;
    dis[x]=times;
    low[x]=times;
    times++;
    sum[x]=w[x];
    ll child=0;
    ll temp=0;
    ll mi=0;
    for(auto y: v[x])
    {
        if(y==x)
        continue;

        if(!vis[y])
        {
            dfs(y, x);
            sum[x]+=sum[y];
            child++;

            if(low[y]>=dis[x] )
            {
                mi+=sum[y];
                ap[x]=1;
                temp^=sum[y];
            }
            else low[x]=min(low[x], low[y]);
        }

        else low[x]=min(low[x], dis[y]);


    }
     if((ap[x]==1 && p!=-1 )|| (child>1 && p==-1) )
        {
            mi=tot-mi-w[x];
            if(mi!=0)
            temp^=mi;
            ans=max(ans, temp);
        }
}
int main()
{
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
    {
        scn(w[i]);
        tot+=w[i];
    }

    for(ll i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }

    // bridges(3);
    dfs(1,-1);

    cout<<ans;
}
