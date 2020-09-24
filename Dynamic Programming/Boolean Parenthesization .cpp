#include <bits/stdc++.h>
using namespace std;
long long int dp[205][205][2];
int rec(string s,int i,int j,int isTrue)
{
    if(i>j)
    return 0;
    
    if(i==j)
    {
        if(isTrue)
        return s[i]=='T'?1:0;
        else return s[i]=='F'?1:0;          
    }
    
    if(dp[i][j][isTrue]!=-1)
    return dp[i][j][isTrue];
    
    long long int numOfWays=0;
    
    for(int k=i+1;k<j;k+=2)
    {
        int lf,lt,rf,rt;
        
        if(dp[i][k-1][0]!=-1)
        lf=dp[i][k-1][0];
        else lf=rec(s,i,k-1,0);
        
        if(dp[i][k-1][1]!=-1)
        lt=dp[i][k-1][1];
        else lt=rec(s,i,k-1,1);
        
        if(dp[k+1][j][0]!=-1)
        rf=dp[k+1][j][0];
        else rf=rec(s,k+1,j,0);
        
        if(dp[k+1][j][1]!=-1)
        rt=dp[k+1][j][1];
        else rt=rec(s,k+1,j,1);
        
        if(s[k]=='|')
        {
            if(isTrue)
            numOfWays=(numOfWays+((lf*rt)+(lt*rt)+(lt*rf)))%1003;
            else numOfWays=(numOfWays+((lf*rf)))%1003;
        }
        else if(s[k]=='&')
        {
            if(isTrue)
            numOfWays=(numOfWays+((lt*rt)))%1003;
            else numOfWays=(numOfWays+((lf*rt)+(lf*rf)+(lt*rf)))%1003;
        }
        else
        {
            if(isTrue)
            numOfWays=(numOfWays+((lf*rt)+(lt*rf)))%1003;
            else numOfWays=(numOfWays+((lf*rf)+(rt*lt)))%1003;
        }
    }
    
    return dp[i][j][isTrue]=numOfWays%1003;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    string s;
	    cin>>s;
	    
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		for(int k=0;k<2;k++)
		dp[i][j][k]=-1;
	    
	    int ans=rec(s,0,n-1,1);
	    
	    cout<<ans<<endl;
	}
	return 0;
}