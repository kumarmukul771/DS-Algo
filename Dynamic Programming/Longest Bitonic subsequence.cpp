https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1

int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    int n=nums.size();
	    vector<int> lis(n,1),lds(n,1);
	    
	    for(int i=1;i<n;i++)
	    for(int j=0;j<i;j++)
	    if(nums[i]>nums[j])
	    lis[i]=max(lis[i],lis[j]+1);
	    
	    for(int i=n-2;i>=0;i--)
	    for(int j=n-1;j>i;j--)
	    if(nums[i]>nums[j])
	    lds[i]=max(lds[i],lds[j]+1);
	    
	    int ans=lis[0]+lds[0]-1;
	    
	    for(int i=1;i<n;i++)
	    ans=max(ans,lis[i]+lds[i]-1);
	    
	    return ans;
	}