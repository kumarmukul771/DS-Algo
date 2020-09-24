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
vector <string> str,ans;
ll n,found;
void rec(string s)
{
    if(s.size()==0)
    {
        found=1;
        return;
    }

    if(found)
    return;

    rep(i,0,n)
    {
        if(found)
        return;

        ll sz1=str[i].size(),sz2=s.size();

        if(sz1<=sz2)
        {
            string x=s.substr(0,sz1);
            if(x==str[i])
            {
                string d=s.substr(sz1,n);
                ans.pb(x);
                rec(d);
                if(!found)
                ans.pop_back();
            }
        }
    }
}
int main()
{
    scn(n);

    string s;
    rep(i,0,n)
    {
        string x;
        cin>>x;
        str.pb(x);
    }

    cin>>s;
    rec(s);

    if(!found)
    {
        cout<<-1<<endl;
        return 0;
    }

    for(auto t:ans)
    cout<<t<<" ";
}