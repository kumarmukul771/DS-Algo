#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define im int main()
ll prime[1000006];
ll n=100006;
using namespace std;
void Seive()
{
    for(ll i=2;i<=sqrt(n)+1;i++)
    {
        if(!prime[i])
        {
            for(ll j=i*i;j<=n;j+=i)
                prime[j]=1;
        }
    }
}
im
{
    Seive();
   ll t;
   cin>>t;
   while(t--)
   {
       ll n1,cnt=0;
       cin>>n1;
       ll a[n1];
       for(ll i=0;i<n1;i++)
        cin>>a[i];
       for(ll j=0;j<n1;j++)
       {
           if(prime[a[j]]==0)
            cnt++;
       }
       cout<<cnt<<endl;
   }
}
