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
  int n,c;
  cin>>n>>c;
  int v[n+1],w[n+1];
  for(int i=1;i<=n;i++) cin>>v[i];
  for(int i=1;i<=n;i++) cin>>w[i];
  int maxvalue=50*n;
  int dp[n+1][maxvalue+1];
  for(int i=0;i<=n;i++){
  for(int j=0;j<=maxvalue;j++)
  dp[i][j]=INT_MAX;}
  dp[0][0]=0;
 // cout<<"cvedgv";
  for(int i=1;i<=n;i++){
  for(int j=0;j<=maxvalue;j++)
  {
      dp[i][j]=dp[i-1][j];
      if(j>=v[i]&&dp[i-1][j-v[i]]!=INT_MAX)
        dp[i][j]=min(dp[i][j],w[i]+dp[i-1][j-v[i]]);
  }}
  int ans;
  for(int i=1;i<=maxvalue;i++){
  if(dp[n][i]<=c) ans=i;}
  print(ans);
}
