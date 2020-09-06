ll dfs(ll node,ll par)
{
    ll max1=0,max2=0;
    for(auto x:v[node])
    {
        if(x!=par && x<=n)
        {
            ll val=dfs(x,node);
            if(val>=max1)
            {
                max2=max1;
                max1=val;
            }
            else if(val>max2) max2=val;
        }
    }
   //if(max1+max2>ans) ans=max1+max2;
   if(node) return max1+1;
   else return max1+max2;
}
