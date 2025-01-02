#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct node
{
	ll l,r,sum,tag,tag2=1;
}t[400005];
ll n,m,a[100005],op,x,y,k,q;
void pushdown(ll lid,ll rid,ll id)
{
	t[lid].sum=(t[lid].sum*t[id].tag2+t[id].tag*(t[lid].r-t[lid].l+1))%q;
	t[rid].sum=(t[rid].sum*t[id].tag2+t[id].tag*(t[rid].r-t[rid].l+1))%q;
	t[lid].tag2=(t[lid].tag2*t[id].tag2)%q;
	t[rid].tag2=(t[rid].tag2*t[id].tag2)%q;	
	t[lid].tag=(t[lid].tag*t[id].tag2+t[id].tag)%q;
	t[rid].tag=(t[rid].tag*t[id].tag2+t[id].tag)%q;
	t[id].tag2=1;
	t[id].tag=0;
}
void build(ll l,ll r,ll id)
{
	t[id].tag2=1;
	t[id].l=l;
	t[id].r=r;
	if(l==r)
	{
		t[id].sum=a[l];
		t[id].sum%=q;
		return;
	}
	ll lid=2*id,rid=2*id+1,mid=(l+r)/2;
	build(l,mid,lid);
	build(mid+1,r,rid);
	t[id].sum=t[lid].sum+t[rid].sum;
	t[id].sum%=q;
}
void reditadd(ll l,ll r,ll id,ll k)
{
	ll L=t[id].l,R=t[id].r;
	if(L>=l&&R<=r) 
	{
		t[id].tag+=k;
		t[id].sum+=k*(t[id].r-t[id].l+1);
		t[id].sum%=q;
		t[id].tag%=q;
		return;
	}
	ll lid=2*id,rid=2*id+1,mid=(L+R)/2;
	pushdown(lid,rid,id); 
	if(l<=mid) reditadd(l,r,lid,k);
	if(r>=mid+1) reditadd(l,r,rid,k);
	t[id].sum=t[lid].sum+t[rid].sum; 
	t[id].sum%=q;
}
void reditmul(ll l,ll r,ll id,ll k)
{
	ll L=t[id].l,R=t[id].r;
	if(L>=l&&R<=r) 
	{
		t[id].tag2*=k;
		t[id].tag*=k;
		t[id].sum*=k;
		t[id].sum%=q;
		t[id].tag%=q;
		t[id].tag2%=q;
		return;
	}
	ll lid=2*id,rid=2*id+1,mid=(L+R)/2;
	pushdown(lid,rid,id); 
	if(l<=mid) reditmul(l,r,lid,k);
	if(r>=mid+1) reditmul(l,r,rid,k);
	t[id].sum=t[lid].sum+t[rid].sum; 
	t[id].sum%=q;
}
ll query(ll l,ll r,ll id)
{
	ll L=t[id].l,R=t[id].r,lid=2*id,rid=2*id+1,mid=(L+R)/2,ans=0;
	if(L>=l&&R<=r) return t[id].sum%q;
	pushdown(lid,rid,id);
	if(l<=mid) ans=query(l,r,lid);
	if(r>=mid+1) ans+=query(l,r,rid);
	return ans%q;
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&q);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	build(1,n,1);
	while(m--)
	{
		scanf("%lld",&op);
		if(op==1)
		{
			scanf("%lld%lld%lld",&x,&y,&k);
			reditmul(x,y,1,k);
		} 
		else if(op==2)
		{
			scanf("%lld%lld%lld",&x,&y,&k);
			reditadd(x,y,1,k);
		} 
		else
		{
			scanf("%lld%lld",&x,&y);
			printf("%lld\n",query(x,y,1)%q);
		}
	}	
	return 0;
}
