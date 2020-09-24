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
#define maxx         1000005
#define inf          INT_MAX
#define zer          INT_MIN
int dp[105][105];
int rec(int i,int j,int a[],int n)
{
    if(i>j)
    return 0;
    if(i==(j+1))
    return max(i,j);

    if(dp[i][j]!=-1)
    return dp[i][j];

    int ans=0;

    int x=a[i]+min(rec(i+1,j-1,a,n),rec(i+2,j,a,n));
    int y=a[j]+min(rec(i+1,j-1,a,n),rec(i,j-2,a,n));

    ans=max(x,y);

    return dp[i][j]=ans;
}
int main()
{
    tc
    {
        int n;
        scanf("%d",&n);

        int a[n];
        rep(i,0,n)
        scanf("%d",&a[i]);

        memset(dp,-1,sizeof(dp));

        cout<<rec(0,n-1,a,n)<<endl;
    }
}