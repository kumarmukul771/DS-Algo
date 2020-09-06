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
#define mp make_pair
im
{
    ll n,k;
    scns(n,k);
    ll j=1;
    ll maxim=-1;
    ll ans=0;
    rep(h,1,n+1){
        cout<<"? ";
    rep(i,1,k+2)
        if(i!=j)
            cout<<i<<" ";
            cout<<endl;
           ll pos,a;
           scns(pos,a);
           ll res=maxim;
           if(a>maxim){
                maxim=a;ans=1;}
                else if(a==maxim) ans++;

    }

    cout<<"! "<<ans<<endl;
}
