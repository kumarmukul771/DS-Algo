https://practice.geeksforgeeks.org/problems/max-length-chain/1/?category[]=Dynamic%20Programming&category[]=Recursion&category[]=sliding-window&category[]=Backtracking&company[]=Amazon&company[]=Microsoft&company[]=Adobe&company[]=Accolite&company[]=Samsung&problemType=functional&page=1&sortBy=submissions&query=category[]Dynamic%20Programmingcategory[]Recursioncategory[]sliding-windowcategory[]Backtrackingcompany[]Amazoncompany[]Microsoftcompany[]Adobecompany[]Accolitecompany[]SamsungproblemTypefunctionalpage1sortBysubmissions


int rec(int i,int n,vector<pair<int,int>>& v,vector<int>& vis)
{
    if(i>=n)
    return 0;

    int ans=1,b=v[i].second;

    for(int j=0;j<n;j++)
    {
        if(b<v[j].first && j!=i && !vis[j])
        {
            vis[j]=1;
            ans=max(ans,1+rec(j,n,v,vis));
            vis[j]=0;
        }
    }

    return ans;
}
int maxChainLen(struct val p[],int N)
{
    //Your code here
    int n=N;
    vector<pair<int,int>> v;
    vector<int> vis(n+5,0);
    
    for(int i=0;i<n;i++)
    v.push_back({p[i].first,p[i].second});

    int ans=rec(0,n,v,vis);
    
    for(int i=1;i<n;i++)
    {
        vis[i]=1;
        ans=max(ans,rec(i,n,v,vis));
        vis[i]=0;
    }
    return ans;
}