int dfsDiam(int node,int par)
{
    int mx1=0,mx2=0;    
 
    for(auto it:v[node])
    if(it!=par)
    {
        int val=dfsDiam(it,node);
 
        if(val>=mx1)
        swap(mx1,mx2),mx1=val;
        else if(val>mx2)
        mx2=val;
 
        diameter=max(diameter,mx1+mx2);
    }
 
    return mx1+1;
}