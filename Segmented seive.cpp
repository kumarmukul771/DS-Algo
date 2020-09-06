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
#define mp           make_pair
void segmented_sieve(ll l,ll r,ll prime[],ll n){
    if(l==1) prime[0]=0;
    for(ll i=2;i*i<=r;i++){
        ll s=(l/i)*i;
        if(s<l) s+=i;
        if(s==i) s+=i;
        for(ll j=s;j<=r;j+=i)
            prime[j-l]=0;
    }
}
im
{
    ll l,r;
    scns(l,r);
    ll n=r-l+1;
    ll prime[n];
    mem(prime,-1);
    segmented_sieve(l,r,prime,n);
    rep(i,0,n)
    cout<<i+l<<" "<<prime[i]<<endl;
}

