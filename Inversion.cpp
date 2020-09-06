#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define im int main()
ll maxim=INT_MIN;
 ll tree[1000006];
ll getsum(ll ind)
{
    ll sum=0;
    while(ind>0)
    {
        sum+=tree[ind];
        ind-=ind&(-ind);
    }
    return sum;
}
void update(ll ind)
{
    while(ind<=maxim)
    {
        tree[ind]++;
        ind+=ind&(-ind);
    }
}
using namespace std;
im
{
    ll n;
    cin>>n;
    //sum=no. of inversion
    ll a[n];ll sum=0;
    for(ll i=0;i<n;i++){
         cin>>a[i];
         if(a[i]>maxim) maxim=a[i];}
    for(ll i=n-1;i>=0;i--)
    {
        sum+=getsum(a[i]-1);
        update(a[i]);
    }
    cout<<sum;
}
