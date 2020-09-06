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
        ll n;
        string str;
       cin>>str;
        n=str.length();
        //cout<<n;nl;
        ll dp[n][2];
        mem(dp,0);
        ll maxim=0;
        if(str[0]=='S') dp[0][0]=1;
        else dp[0][1]=1;
        //cout<<dp[0][0];
        rep(i,1,n)
        {
            dp[i][0]=dp[i-1][0];
            dp[i][1]=dp[i-1][1];
            if(str[i]=='S') dp[i][0]++;
            else dp[i][1]++;
        }
        ll cnt=0;
        rep(i,2,n)
        {
            if(dp[i][0]-dp[i-2][0]<2 && dp[i][1]-dp[i-2][1]<2) cnt++;
            else if(cnt!=0)
            {
                if(maxim<cnt) maxim=cnt;
                cnt=0;
            }
        }
        //cout<<maxim<<endl;
        if(maxim>0)
            print(n-maxim-2);
        else
        print(n-maxim);
        nl;
    }
}
