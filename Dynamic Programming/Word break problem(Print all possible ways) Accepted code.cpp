#include <bits/stdc++.h>
using namespace std;
void rec(string s,vector<string>& v,vector<string>& ans)
{
    int sz=s.size(),n=v.size();
    if(sz==0)
    {
        cout<<"(";
        
        int szans=ans.size();
        for(int i=0;i<szans-1;i++)
        cout<<ans[i]<<" ";
        
        cout<<ans[szans-1]<<")";

        return;
    }
    
    for(int i=0;i<n;i++)
    {
        int sz2=v[i].size();
        if(sz>=sz2)
        {
            if(s.substr(0,sz2)==v[i])
            {
                ans.push_back(v[i]);
                rec(s.substr(sz2,sz),v,ans);
                ans.pop_back();
            }
        }
    }
}
int main() 
{
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<string> v,ans;
	   
	    for(int i=0;i<n;i++)
	    {
	        string s;
	        cin>>s;
	        v.push_back(s);
	    }
	    
	    string str;
	    cin>>str;
	    
	    rec(str,v,ans);
	    cout<<endl;
	}
	return 0;
}