struct Box
{
    int h,w,d;
};
int compare (const void *a, const void * b) 
{ 
	return ( (*(Box *)b).d * (*(Box *)b).w ) - 
		( (*(Box *)a).d * (*(Box *)a).w ); 
} 
int maxHeight(int height[],int width[],int length[],int n)
{
    //Your code here
    Box rot[3*n+5];
    int index=0;

    for(int i=0;i<n;i++)
    {
        rot[index].h=height[i];
        rot[index].w=min(width[i],length[i]);
        rot[index].d=max(width[i],length[i]);
        index++;

        rot[index].h=width[i];
        rot[index].w=min(height[i],length[i]);
        rot[index].d=max(height[i],length[i]);
        index++;

        rot[index].h=length[i];
        rot[index].w=min(height[i],width[i]);
        rot[index].d=max(height[i],width[i]);
        index++;
    }

    n=3*n;
    qsort (rot, n, sizeof(rot[0]), compare);

    int msh[n]={0};
    
    for(int i=0;i<n;i++)
    msh[i]=rot[i].h;

    for(int i=0;i<n;i++)
    for(int j=0;j<i;j++)
    if((rot[i].w<rot[j].w) && (rot[i].d<rot[j].d))
    msh[i]=max(msh[i],msh[j]+rot[i].h);

    int mx=0;
    for(int i=0;i<n;i++)
    mx=max(mx,msh[i]);

    return mx;
}