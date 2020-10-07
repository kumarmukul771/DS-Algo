#include<bits/stdc++.h>
using namespace std;
#define pfi(a) printf("%d",a);
#define pfl(a) printf("%lld",a);
#define pfin(a) printf("%d\n",a);
#define pfln(a) printf("%lld\n",a);
#define sfi(a) scanf("%d",&a);
#define sfl(a) scanf("%lld",&a);
#define pb push_back
#define f(i,a,b) for(int i=a;i<b;i++)
#define ll long long
#define endl '\n'
#define int ll
const int M=1e9+7;
const int MAXN=1e5+1;

struct st{
	ll ans,total;
	bool flipped;
};

vector<int> v[MAXN];
int in[MAXN],out[MAXN],arr[MAXN],sz[MAXN],chead[MAXN],tim,tim1,n,l,chain_no=1,chain_ind[MAXN],level[MAXN],base[MAXN];
int up[MAXN][20];

ll val[MAXN];

st tree[4*MAXN];


ll rev(ll a){
	ll newnum=0;

	while(a){
		newnum=newnum*10+a%10;
		a/=10ll;
	}

	return newnum;
}

void dfs(int node,int p,int le){
	in[node]=tim;
	up[node][0]=p;
	level[node]=le;
	f(i,1,l+1)
		up[node][i]=up[up[node][i-1]][i-1];

	for(int u:v[node]){
		if(u!=p){
			tim++;
			sz[node]+=sz[u];
			dfs(u,node,le+1);
		}
	}
 	sz[node]++;
	out[node]=tim;
}

bool is_ancestor(int u,int v){
	return in[u]<=in[v] && out[u]>=out[v];
}

int lca(int u,int v){
	if(is_ancestor(u,v))
		return u;
	if(is_ancestor(v,u))
		return v;

	for(int i=l;i>=0;i--){
		if(!is_ancestor(up[u][i],v))
			u=up[u][i];
	}

	return up[u][0];

}

void preprocess(){
	tim=0;
	l = ceil(log2(n));
	dfs(1,1,0);
}

//scary scary

void hld(int node,int par){

	if(chead[chain_no]==-1){
		chead[chain_no]=node;
	}

 	base[node]=tim1;
 	arr[tim1]=node;
 	tim1++;
	chain_ind[node]=chain_no;

	int bigchild=-1,maxi=-1;

	for(int x:v[node]){
		if(x==par) continue;
		if(sz[x]>maxi)
			maxi=sz[x],bigchild=x;
	}

	if(bigchild!=-1)
		hld(bigchild,node);

	for(int x:v[node]){
		if(x==par || x==bigchild) continue;
		chain_no++;
		hld(x,node);
	}

}

void build(int node,int st,int end){
	if(st==end){
		tree[node].ans=val[arr[st]];
		tree[node].total=val[arr[st]]+rev(val[arr[st]]);
		tree[node].flipped=false;
		return;
	}

	int mid=(st+end)/2;

	build(2*node,st,mid);
	build(2*node+1,mid+1,end);

	tree[node].ans=tree[2*node].ans+tree[2*node+1].ans;
	tree[node].total=tree[2*node].total+tree[2*node+1].total;
	tree[node].flipped=false;

}

ll query(int node,int st,int end,int l,int r){

	if(st>r || l>end){
		return 0;
	}

	if(tree[node].flipped){
		tree[node].ans=tree[node].total-tree[node].ans;

		if(st!=end){
			tree[2*node].flipped=!tree[2*node].flipped;
			tree[2*node+1].flipped=!tree[2*node+1].flipped;
		}

		tree[node].flipped=false;
	}




	if(st>=l && end<=r)
		return tree[node].ans;

	int mid=(st+end)/2;

	return (query(2*node,st,mid,l,r)+query(2*node+1,mid+1,end,l,r));

}

void update(int node,int st,int end,int l,int r){

	if(tree[node].flipped){
		tree[node].ans=tree[node].total-tree[node].ans;

		if(st!=end){
			tree[2*node].flipped=!tree[2*node].flipped;
			tree[2*node+1].flipped=!tree[2*node+1].flipped;
		}

		tree[node].flipped=false;
	}

	if(st>r || end<l)
	return;

	if(st>=l && end<=r){

		tree[node].ans=tree[node].total-tree[node].ans;

		if(st!=end){
			tree[2*node].flipped=!tree[2*node].flipped;
			tree[2*node+1].flipped=!tree[2*node+1].flipped;
		}

		return;
	}

	int mid=(st+end)/2;

	update(2*node,st,mid,l,r);
	update(2*node+1,mid+1,end,l,r);

	tree[node].ans = tree[2*node].ans + tree[2*node+1].ans;

}

ll query_up(int u,int v){
	int uchain,vchain=chain_ind[v];
	ll tot=0;

	while(1){
		uchain=chain_ind[u];

		if(uchain==vchain){
			tot=tot+query(1,0,tim,base[v],base[u]);
			break;
		}

		tot=tot+query(1,0,tim,base[chead[uchain]],base[u]);

		u=chead[uchain];
		u=up[u][0];
	}
	return tot;

}

void upddate_util(int u,int v){
	int uchain,vchain=chain_ind[v];

	while(1){
		//cout<<"*";
		uchain=chain_ind[u];
		if(uchain==vchain){
			update(1,0,tim,base[v],base[u]);
			break;
		}

		update(1,0,tim,base[chead[uchain]],base[u]);
		u=chead[uchain];
		u=up[u][0];
	}

}

void update_hld(int u,int v){
	int lc=lca(u,v);

	upddate_util(u,lc);

	upddate_util(v,lc);

	update(1,0,tim,base[lc],base[lc]);

}

void find(int u,int v){
	int lc=lca(u,v);

	ll temp1=query_up(u,lc);
	ll temp2=query_up(v,lc);

	ll ans=temp2+temp1;

	ans-=(query(1,0,tim,base[lc],base[lc]));

	cout<<ans<<endl;
}


int main(){
  	ll q;
 	cin>>n>>q;


 	f(i,1,n+1){
 		cin>>val[i];
 		chead[i]=-1;
 	}

 	for(int i=0;i<n-1;i++){
 		int x,y;
 		cin>>x>>y;
 		v[x].push_back(y);
 		v[y].push_back(x);
 	}

 	preprocess();
 	hld(1,1);

 	build(1,0,tim);

 	while(q--){
 		int tp,x,y;
 		cin>>tp>>x>>y;

 		if(tp==2){
 			find(x,y);
 		}
 		else{
 			update_hld(x,y);
 		}

 	}



}
