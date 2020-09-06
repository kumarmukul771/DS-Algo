#include<bits/stdc++.h>
using namespace std;
#define ll           long long
#define rep(i,j,n)   for(ll i=j;i<n;i++)
#define scn(a)       scanf("%lld",&a)
#define scns(a,b)    scanf("%lld %lld",&a,&b)
#define scnss(a,b,c)    scanf("%lld %lld %lld",&a,&b,&c)
#define print(a)     printf("%lld",a)
#define tc           ll t; scn(t); while(t--)
#define vec          vector<ll>
#define pb          push_back
#define pairs        pair<ll,ll>
#define flag            first
#define s            second
#define all(v)       v.begin(),v.end()
#define srt(v)       sort(v.rbegin(),v.rend())
#define mem(a,b)     memset(a,b,sizeof(a))
#define nl           printf("\n")
#define maxx         500005
#define inf          100000000
#define zer          INT_MIN
ll power(ll a,ll b)
{
    if(b==0)
        return 1;
    else if(b%2==0)
        return power((a*a),(b)/2);
    else
        return (a*power((a*a),(b-1)/2));
}
int main()
{
    tc{
        ll n;
        scn(n);
        vec v;
        vec v1;
        ll i=1;
        for(ll j=1;j<=30;i++)
        {
            v.pb(i);
            if(j%2)
            i+=3;
            else i++;
        }
        i=2;
        for(ll j=1;j<=30;i++)
        {
            v1.pb(i);
            if(j%2)
            i+=3;
            else i++;
        }

        ll a=0,b=0;
        ll vsiz=v.size();
        ll vvsiz=v1.size();

        rep(i,0,vsiz)
        {
            ll h=v[i];
            if(h>n)
            break;
            a+=power(2,h);
        }
        rep(i,0,vvsiz)
        {
            ll h=v[i];
            if(h>n)
            break;
            b+=power(2,h);
        }
        cout<<abs(a-b)<<endl;

    }
}
