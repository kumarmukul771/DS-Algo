#include<bits/stdc++.h>
using namespace std;
#define ll           long long
#define rep(i,j,n)   for(ll i=j;i<n;i++)
#define scn(a)       scanf("%lld",&a)
#define nl           printf("\n")
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
ll cnt;
struct trie
{
    trie* a[26];
    trie()
    {
        rep(i,0,26)
        a[i]=nullptr;
    }
};
void build(trie* root,ll lev,string s)
{
    ll ind=(ll)(s[lev] - 'a');
    if(!root->a[ind]){
    root->a[ind]=new trie();
    cnt++;
    }
    if((lev+1)!=s.size())
    build(root->a[ind],lev+1,s);
}
im
{
    trie* root=new trie();
    tc
    {
        string s;
        cin>>s;
        build(root,0,s);
    }
    cout<<cnt+1;
}
