#include<bits/stdc++.h>
using namespace std;
#define ll           long long
#define rep(i,j,n)   for(ll i=j;i<n;i++)
#define scn(a)       scanf("%lld",&a)
#define nl         printf("\n")
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

int main() 
{
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k;
	    cin>>n>>k;
	    
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    
	    sort(a,a+n);
	    
	    int ans=0;
	    
	    for(int i=0;i<n;i++)
	    {
	        int x=a[i]+k;
	        
	        int l=i,r=n-1,m=0;

    		// ind of num just less than x;
    		int indl=-1;
    	    
    		// Finding number just less than x
    	    while(l<=r)
    	    {
    	        m=(r-l)/2 + l;
    
    			if(a[m]==x)
    			{
    				r=m-1;
    				indl=m-1;
    			}
    	        else if(a[m]>x)
    	        r=m-1;
    	        else 
    			{
    				l=m+1;
    				indl=m;
    			}
    	    }
    	    
    	    if(indl<i)
    	    indl=i;
	        
	        ans+=(indl-i);

			// cout<<ans<<" "<<endl;
	    }
	    
	    cout<<ans<<endl;
	    
	}
	return 0;
}