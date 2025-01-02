#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],op,x,y;
struct node
{
	ll l,r,sum,ans,lmax,rmax;
}b[2000005];
void change(ll id,ll lid,ll rid)
{
	b[id].sum=b[lid].sum+b[rid].sum;
	b[id].lmax=max(b[lid].lmax,b[lid].sum+b[rid].lmax);
	b[id].rmax=max(b[rid].rmax,b[rid].sum+b[lid].rmax);
	b[id].ans=max(b[lid].rmax+b[rid].lmax,max(b[lid].ans,b[rid].ans));
}
void build(ll l,ll r,ll id)
{
	b[id].l=l;
	b[id].r=r;
	if(l==r)
	{
		b[id].sum=b[id].ans=b[id].lmax=b[id].rmax=a[l];
		return;
	}
	ll lid=2*id,rid=2*id+1,mid=(l+r)/2;
	build(l,mid,lid);
	build(mid+1,r,rid);
	change(lid,rid,id);
}
void edit(ll l,ll r,ll id,ll v)
{
	if(l==r)
	{
		b[id].sum=b[id].ans=b[id].lmax=b[id].rmax=v;
		return;
	}
	ll lid=2*id,rid=2*id+1,mid=(l+r)/2;
	if(id<=mid) edit(l,mid,lid,v);
	else edit(mid+1,r,rid,v);
	change(lid,rid,id);
}
node query(ll l,ll r,ll id)
{
	ll L=b[id].l,R=b[id].r;
	if(l>=L&&r<=R) return b[id];
	node a,B,ret;
	a.sum=a.lmax=a.rmax=a.ans=B.sum=B.lmax=B.rmax=B.ans=-(1<<30);
	ret.sum=0;
	ll lid=2*id,rid=2*id+1,mid=(L+R)/2;
	if(l<=mid)
	{
		a=query(l,r,lid);
		ret.sum+=a.sum;
	}
	if(r>mid)
	{
		B=query(l,r,rid);
		ret.sum+=B.sum; 
	} 
	ret.ans=max(max(a.ans,B.ans),a.rmax+B.lmax);
	ret.lmax=max(a.lmax,a.sum+B.lmax);
	ret.rmax=max(B.rmax,B.sum+a.rmax);
	if(l>mid) ret.lmax=max(ret.lmax,B.lmax);
	if(r<=mid) ret.rmax=max(ret.rmax,B.rmax);
	return ret;
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	build(1,n,1);	
	while(m--)
	{
		scanf("%lld%lld%lld",&op,&x,&y);
		if(op==2) edit(1,n,x,y);
		else printf("%lld\n",query(x,y,1).ans);
	}	
	return 0;
}

