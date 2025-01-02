#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct node
{
	ll l,r,sum,tag;
}t[400005];
ll n,m,a[100005],op,x,y,k,ans;
void pushdown(ll lid,ll rid,ll id)
{
	if(t[id].tag!=0)
	{
		t[lid].tag+=t[id].tag;
		t[lid].sum+=t[id].tag*(t[lid].r-t[lid].l+1);
		t[rid].tag+=t[id].tag;
		t[rid].sum+=t[id].tag*(t[rid].r-t[rid].l+1);
		t[id].tag=0;
	} 
}
void build(ll l,ll r,ll id)
{
	t[id].l=l;
	t[id].r=r;
	if(l==r)
	{
		t[id].sum=a[l];
		return;
	}
	ll lid=2*id,rid=2*id+1,mid=(l+r)/2;
	build(l,mid,lid);
	build(mid+1,r,rid);
	t[id].sum=t[lid].sum+t[rid].sum;
}
void redit(ll l,ll r,ll id,ll k)
{
	ll L=t[id].l,R=t[id].r;
	if(L>=l&&R<=r) 
	{
		t[id].tag+=k;
		t[id].sum+=k*(t[id].r-t[id].l+1);
		return;
	}
	ll lid=2*id,rid=2*id+1,mid=(L+R)/2;
	pushdown(lid,rid,id); 
	if(l<=mid) redit(l,r,lid,k);
	if(r>=mid+1) redit(l,r,rid,k);
	t[id].sum=t[lid].sum+t[rid].sum; 
}
ll query(ll l,ll r,ll id)
{
	ll L=t[id].l,R=t[id].r,lid=2*id,rid=2*id+1,mid=(L+R)/2,ans=0;
	if(L>=l&&R<=r) return t[id].sum;
	pushdown(lid,rid,id);
	if(l<=mid) ans=query(l,r,lid);
	if(r>=mid+1) ans+=query(l,r,rid);
	return ans;
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
		scanf("%lld",&op);
		if(op==1)
		{
			scanf("%lld%lld%lld",&x,&y,&k);
			redit(x,y,1,k);
		} 
		else
		{
			ans=0;
			scanf("%lld%lld",&x,&y);
			printf("%lld\n",query(x,y,1));
		}
	}	
	return 0;
}

