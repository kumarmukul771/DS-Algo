#include<bits/stdc++.h>
using namespace std;
#define ll           long long
#define rep(i,j,n)   for(ll i=j;i<n;i++)
#define scn(a)       scanf("%lld",&a)
#define nl	     printf("\n")
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
#define maxx         500005
#define inf          LLONG_MAX
#define zer          LLONG_MIN
ll mod=1e9+7,n,q,ans;
map<string,ll>m1;
ll flag=0;

struct trie{
    ll count;
    trie *ptr[26];

    trie(){
        count=0;
        rep(i,0,26)
        ptr[i]=nullptr;
    }
};

void insert(trie *root,string s1,ll level){
    ll ind=s1[level]-'a';

    if(!root->ptr[ind]){
    root->ptr[ind]=new trie();

    if(!flag)
    cout<<(char)(ind+97)<<endl;

    flag=1;
    }
    if(!flag)
    cout<<(char)(97+ind);

    root->ptr[ind]->count++;

    if((level+1)!=s1.size())
    insert(root->ptr[ind],s1,level+1);

    else
        if(!flag && m1[s1])
        cout<<" "<<m1[s]+1<<endl;
}

int main(){
    trie *root=new trie();

    scn(n);

    rep(i,0,n){
        string s1;
        cin>>s1;

        insert(root,s1,0);

        flag=0;
        m1[s]++;
    }
}
