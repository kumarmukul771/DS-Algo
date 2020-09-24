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
ll dp[maxx];
unordered_set<string> st;
int ans=0;
int main()
{
    tc
    {
        int n,q,k;
        scanf("%d %d %d",&n,&q,&k);
        map<int,vector<int>> m;

        int a[n+5];
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            m[a[i]].push_back(i);
        }

        vector<int> v;

        rep(i,0,q)
        {
            int l,r;
            scanf("%d %d",&l,&r);
            v.pb(l);
            v.pb(r);
        }

        for(int j=0;j<2*q;j+=2)
        {
            int l=v[j],r=v[j+1];

            int ans=0;

            for(int i=1;i<=3;i++)
            {
                auto it=lower_bound(m[i].begin(),m[i].end(),r);
                auto t=lower_bound(m[i].begin(),m[i].end(),l);
                int ind=it-m[i].begin();
                int sz=m[i].size();
                int total_ele=0;

                if(it==m[i].end())
                {
                    if(m[i][sz-1]<=r)
                    {
                        int r1=sz-1;
                        if(t!=m[i].end())
                        {
                            int l1=t-m[i].begin();
                            total_ele=r1-l1+1;

                            if(k<=total_ele)
                            ans++;
                        }
                    }
                }
                else
                {
                    if(m[i][ind]==r)
                    {
                        int r1=ind;
                        if(t!=m[i].end())
                        {
                            int l1=t-m[i].begin();
                            total_ele=r1-l1+1;

                            if(k<=total_ele)
                            ans++;
                        }
                    }
                    else if(ind>0 && m[i][ind-1]<=r)
                    {
                        int r1=ind-1;
                        if(t!=m[i].end())
                        {
                            int l1=t-m[i].begin();
                            total_ele=r1-l1+1;

                            if(k>total_ele)
                            total_ele=0;
                        }
                    }
                }
            }
            cout<<ans<<endl;
        }
    }
}