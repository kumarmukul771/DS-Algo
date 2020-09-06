#include<bits/stdc++.h>
using namespace std;
#define ll           long long
#define rep(i,j,n)   for(ll i=j;i<n;i++)
#define scn(a)       scanf("%lld",&a)
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
#define nl           printf("\n")
#define maxx         500005
#define inf          INT_MAX
int main()
{
    ll n;
    cin>>n;

    map <ll,ll> m;
    ll seq[]={4,8,15,16,23,42};

    ll a[n];

    ll mod[n];
    rep(i,0,n)
    {
        scn(a[i]);
        m[a[i]]++;
    }
    ll minim=m[4];

    rep(i,1,6)
    minim=min(minim,m[a[i]]);

    // ll req[minim+1][6];
    // mem(req,0);
    // rep(i,0,6)
    // req[0][i]=seq[i];

    ll del[n];
    mem(del,0);

    ll ans=0;
    map <ll,ll> srch;
    ll c=0;

    rep(i,0,n)
    {
        if(srch[a[i]])
        {
            srch[a[i]]--;
            if(a[i]==8) srch[15]++;
            else if(a[i]==15) srch[16]++;
            else if(a[i]==23) srch[42]++;
            else c++;
        }
        else if(a[i]==4) srch[8]++;
        else del[i]=-1;
    }

    cout<<c++;
}
