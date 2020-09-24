#include<bits/stdc++.h>
using namespace std;
int rec(string s,string t,int n,int m)
{
    int LCSuff[n+1][m+1]; 
	int result = 0; 
	
	for (int i=0; i<=n; i++) 
	{ 
		for (int j=0; j<=m; j++) 
		{ 
			if (i == 0 || j == 0) 
				LCSuff[i][j] = 0; 

			else if (s[i-1] == t[j-1]) 
			{ 
				LCSuff[i][j] = LCSuff[i-1][j-1] + 1; 
				result = max(result, LCSuff[i][j]); 
			} 
			else LCSuff[i][j] = 0; 
		} 
	} 
	return result; 
}
int main()
{
    int f;
    cin>>f;
    while(f--)
	{
	    int n,m;
	    cin>>n>>m;
	    string s,t;
	    cin>>s>>t;
	    
    	cout<<rec(t,s,m,n)<<endl;
	}
}