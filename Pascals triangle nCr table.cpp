#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{

    ll a[1000][1000];
    memset(a,0,sizeof(a)*1000*1000);
    for(ll i=0;i<1000;i++) a[i][0]=1;
    ll j=1;
    for(ll i=1;i<1000;i++)
    {
        for(j=1;j<=i;j++)
        a[i][j]=a[i-1][j]+a[i-1][j-1];
    }
    ll t;
    cin>>t;
    for(ll i=0;i<t;i++)
    {
        ll n;
        cin>>n;
        for(ll j=0;j<=n;j++)
        cout<<a[n][j]<<" ";
        cout<<endl;
    }
}
