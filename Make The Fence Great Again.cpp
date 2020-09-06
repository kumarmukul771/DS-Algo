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
        scn(n);
        ll a[n],b[n];
        rep(i,0,n) scns(a[i],b[i]);
        ll ans=0;
        ll dp[3][n];
        mem(dp,0);
        rep(i,0,n)
        dp[0][i]=a[i];
        rep(i,0,n)
        {
            dp[1][i]=dp[0][i]+1;
            dp[2][i]=dp[0][i]+2;
        }
        ll dp2[3][n];
        mem(dp2,0);
        dp2[0][0]=0;
        dp2[1][0]=b[0];
        dp2[2][0]=2*b[0];
        ll ans2=0;
        rep(i,1,n)
        {
            dp2[0][i]=0;
            dp2[1][i]=b[i];
            dp2[2][i]=2*b[i];
            if(dp[0][i]==dp[0][i-1])
            {
                dp2[0][i]+=min(dp2[1][i-1],dp2[2][i-1]);
                dp2[1][i]+=min(dp2[0][i-1],dp2[2][i-1]);
                dp2[2][i]+=min(dp2[0][i-1],dp2[1][i-1]);
            }
            else if(dp[0][i]>dp[0][i-1])
            {
                if((dp[0][i]-dp[0][i-1])==1)
                {
                    dp2[0][i]+=min(dp2[0][i-1],dp2[2][i-1]);
                    dp2[1][i]+=min(dp2[0][i-1],dp2[1][i-1]);
                    dp2[2][i]+=(min(dp2[2][i-1],min(dp2[0][i-1],dp2[1][i-1])));
                }
                else if((dp[0][i]-dp[0][i-1])==2)
                {
                    dp2[0][i]+=min(dp2[0][i-1],dp2[1][i-1]);
                    dp2[1][i]+=(min(dp2[2][i-1],min(dp2[0][i-1],dp2[1][i-1])));
                    dp2[2][i]+=(min(dp2[2][i-1],min(dp2[0][i-1],dp2[1][i-1])));
                }
                else{
                dp2[0][i]+=min(dp2[0][i-1],min(dp2[1][i-1],dp2[2][i-1]));
                dp2[1][i]+=min(dp2[0][i-1],min(dp2[1][i-1],dp2[2][i-1]));
                dp2[2][i]+=min(dp2[0][i-1],min(dp2[1][i-1],dp2[2][i-1]));
                }
            }
            else if(dp[0][i]<dp[0][i-1])
            {
              if((dp[0][i-1]-dp[0][i])==1)
                {
                    dp2[0][i]+=(min(dp2[2][i-1],min(dp2[0][i-1],dp2[1][i-1])));
                    dp2[1][i]+=min(dp2[2][i-1],dp2[1][i-1]);
                    dp2[2][i]+=min(dp2[0][i-1],dp2[2][i-1]);
                }
                else if((dp[0][i-1]-dp[0][i])==2)
                {
                    dp2[0][i]+=(min(dp2[2][i-1],min(dp2[0][i-1],dp2[1][i-1])));
                    dp2[1][i]+=(min(dp2[2][i-1],min(dp2[0][i-1],dp2[1][i-1])));
                    dp2[2][i]+=min(dp2[1][i-1],dp2[2][i-1]);
                }
                else{
                dp2[0][i]+=min(dp2[0][i-1],min(dp2[1][i-1],dp2[2][i-1]));
                dp2[1][i]+=min(dp2[0][i-1],min(dp2[1][i-1],dp2[2][i-1]));
                dp2[2][i]+=min(dp2[0][i-1],min(dp2[1][i-1],dp2[2][i-1]));
                }
            }
        }

        //rep(i,0,n)
          //cout<<dp2[0][i]<<" "<<dp2[1][i]<<" "<<dp2[2][i]<<endl;
                  ans=min(dp2[0][n-1],min(dp2[1][n-1],dp2[2][n-1]));
        cout<<ans<<endl;
    }
}
