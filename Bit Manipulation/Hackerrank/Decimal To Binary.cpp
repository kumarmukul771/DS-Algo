#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,ans=0;
        cin>>n;

        int i = 0; 
        while (n > 0 || i<32) 
        { 
            if(n%2==0)
            ans+=pow(2,i);
            
            n = n / 2; 
            i++; 
        } 

        cout<<ans<<endl;
    }
}