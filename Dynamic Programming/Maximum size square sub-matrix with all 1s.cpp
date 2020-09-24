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
#define maxx         300005
#define inf          INT_MAX
#define zer          INT_MIN
ll n,m,ans;
ll a[100][100];
void rec(ll str,ll stc,ll enr,ll enc)
{
    if(str<1 || stc<1 || enr>n || enc>m)
    return;

    ll cnt=0,found_zero=0;

    rep(i,str,enr+1)
    {
        rep(j,stc,enc+1)
        {
            if(a[i][j]==0)
            {
                found_zero=1;
                break;
            }
            else cnt+=a[i][j];
        }
        if(found_zero)
        break;
    }

    if(!found_zero)
    ans=max(ans,cnt);
    else
    {
         rep(i,str,enr+1)
         rep(j,stc,enc+1)
         {
            if(a[i][j]==0)
            {
                rec(str,stc,i-1,enc);
                rec(i+1,stc,enr,enc);
                rec(str,stc,enr,j-1);
                rec(str,j+1,enr,enc);
            }
         }
    }
}
int main()
{
    scns(n,m);

    rep(i,1,n+1)
    rep(j,1,m+1)
    scn(a[i][j]);

    rec(1,1,n,m);

    cout<<ans;
}