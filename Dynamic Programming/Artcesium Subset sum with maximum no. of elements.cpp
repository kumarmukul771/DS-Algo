#include<bits/stdc++.h>
using namespace std;
int rec(int i,int element_taken,int sum,int a[],int n,int required_sum)
{
	if(sum==required_sum)
	return element_taken;

	if(i>=n)
	return 0;

	if(sum>required_sum||element_taken==n)
	return -1e9;

	int ans=rec(i+1,element_taken+1,sum+a[i],a,n,required_sum);
	ans=max(ans,rec(i+1,element_taken,sum,a,n,required_sum));


	return ans;
}
int main()
{
	int n,required_sum;
	scanf("%d %d",&n,&required_sum);
	int a[n],dp[n+5];

	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);

	memset(dp,-1,sizeof(dp));

	int ans=rec(0,0,0,a,n,required_sum);

	cout<<ans<<endl;
}