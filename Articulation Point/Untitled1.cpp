#include<bits/stdc++.h>
using namespace std;
#define ll           int
#define rep(i,j,n)   for(ll i=j;i<n;i++)
#define scn(a)       scanf("%d",&a)
#define scns(a,b)    scanf("%d %d",&a,&b)
#define print(a)     printf("%d\n",a)
#define vec          vector<ll>
#define pb           push_back
#define pairs        pair<ll,ll>
#define f            first
#define s            second
#define all(v)       v.begin(),v.end()
#define mem(a,b)     memset(a,b,sizeof(a))
#define inf          INT_MAX
const ll mod=1e9+7;
const ll N=2e5+5;
int t,n,m,x,y,p,q,k;

int main()
{
    scn(t);

    while(t--)
    {
        string s1;
        cin>>s1;

        n=s1.size();
        ll ans=inf;

        rep(i,0,n)
        {
            string s2(n,'0');

            ll cnt=0;

            rep(j,i,n)
            s2[j]='1';

            rep(j,0,n)
            if(s2[j]!=s1[j])
            cnt++;

            ans=min(cnt,ans);
        }

        rep(i,0,n)
        {
            string s2(n,'0');

            ll cnt=0;

            rep(j,0,i)
            s2[j]='1';

            rep(j,0,n)
            if(s2[j]!=s1[j])
            cnt++;

            ans=min(cnt,ans);
        }

        print(ans);
    }
}
