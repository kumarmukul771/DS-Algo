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
im
{
    tc
    {
        ll n,k;
        scns(n,k);
        ll a[n];
        rep(i,0,n) scn(a[i]);
        ll List[n];
        rep(i,0,n) List[i]=a[i];
        ll maxim[n];
        maxim[0]=a[0];
        rep(i,1,n)
        {
            if((i-(k+1))>=0 && maxim[i-(k+1)]>0) List[i]+=maxim[i-(k+1)];
            maxim[i]=max(maxim[i-1],List[i]);
        }
        ll maxim2=List[0];
        rep(i,1,n) maxim2=max(List[i],maxim2);
        if(maxim2<0)
            cout<<0<<endl;
        else
        cout<<maxim2<<endl;
    }
}
