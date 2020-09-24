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
void rec(string s)
{
    ll sz=s.size();
    rep(i,0,sz)
    {
        for(ll j=sz;j>i;j--)
        {
            string sub_str=s.substr(i,j);
            st.insert(sub_str);

            ll sz2=sub_str.size();
            rep(k,1,sz2-1)
            {
                string str=sub_str;
                str.erase(str.begin()+k);

                rec(str);
            }
        }
    }
}
int main()
{
    string s;
    cin>>s;
    sort(all(s));
    ll n=s.size();

    rec(s);

    for(auto t:st)
    cout<<t<<endl;
}