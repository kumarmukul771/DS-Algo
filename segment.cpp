#include<bits/stdc++.h>
using namespace std;
#define ll           long long
#define rep(i,j,n)   for(ll i=j;i<n;i++)
#define scn(a)       scanf("%lld",&a)
#define nl	     printf("\n")
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
#define maxx         100005
#define inf          LLONG_MAX
#define zer          LLONG_MIN
ll mod=1e9+7,n,a[maxx];
vec v1[maxx],vis;
map<ll,ll>m1;

im{
    tc{
        scn(n);

        rep(i,0,n){
            ll l,r;
            scns(l,r);
            m1[l]++;
            m1[r]--;   // here r is not included in question itself
        }
        ll counts=0,ans=0;

        for(auto it:m1){
            counts+=it.s;
            ans=max(ans,counts);
        }
        print(ans);
        m1.clear();
        nl;
    }
}
