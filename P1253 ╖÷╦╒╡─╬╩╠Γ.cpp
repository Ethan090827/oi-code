#include <bits/stdc++.h>
#define ll long long
#define Lid id*2
#define Rid id*2+1
using namespace std;
ll n,q,a[1000005],op,l,r,x;
struct node
{
	ll l,r,ans,tedit,tadd;
}t[4000005];
void pushdown(ll lid,ll rid,ll id)
{
	if(t[id].tedit!=0)
	{
		t[lid].tedit=t[id].tedit; 
		t[rid].tedit=t[id].tedit;
		t[lid].tadd+=t[id].tadd;
		t[rid].tadd+=t[id].tadd;		
		t[lid].ans=t[lid].tedit+t[lid].tadd;
		t[rid].ans=t[rid].tedit+t[rid].tadd;
	}
	else
	{
		t[lid].tadd+=t[id].tadd;
		t[rid].tadd+=t[id].tadd;
		t[lid].ans+=t[lid].tadd;
		t[rid].ans+=t[rid].tadd;
	}
	t[id].tadd=0;
	t[id].tedit=0;
}
void build(ll l,ll r,ll id)
{
	t[id].l=l;
	t[id].r=r;
	if(l==r)
	{
		t[id].ans=a[l];
		return;
	}
	ll mid=(l+r)/2;
	build(l,mid,Lid);
	build(mid+1,r,Rid);
	t[id].ans=max(t[Lid].ans,t[Rid].ans);
}
void edit(ll l,ll r,ll id,ll x)
{
	ll L=t[id].l,R=t[id].r,mid=(L+R)/2;
	if(L>=l&&R<=r)
	{
		t[id].tedit=x;
		t[id].ans=x;
		return;
	}
	pushdown(Lid,Rid,id);
	if(l<=mid) edit(l,r,Lid,x);
	if(r>mid) edit(l,r,Rid,x);
}
void add(ll l,ll r,ll id,ll x)
{
	ll L=t[id].l,R=t[id].r,mid=(L+R)/2;
	if(L>=l&&R<=r)
	{
		t[id].tadd+=x;
		t[id].ans+=x;
		return;
	}
	pushdown(Lid,Rid,id);
	if(l<=mid) add(l,r,Lid,x);
	if(r>mid) add(l,r,Rid,x);
}
ll query(ll l,ll y,ll id)
{
	ll L=t[id].l,R=t[id].r,mid=(L+R)/2;
	if(L>=l&&R<=r) return t[id].ans;
	pushdown(Lid,Rid,id);
	ll ans=0;
	if(l<=mid) ans+=query(l,r,Lid);
	if(r>mid) ans+=query(l,r,Rid);
	return ans;
} 
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	build(1,n,1);	
	while(q--)
	{
		scanf("%lld",&op);
		if(op==1)
		{
			scanf("%lld%lld%lld",&l,&r,&x);
			edit(l,r,1,x);
		}
		else if(op==2)
		{
			scanf("%lld%lld%lld",&l,&r,&x);
			add(l,r,1,x);
		}
		else
		{
			scanf("%lld%lld",&l,&r);
			printf("%lld\n",query(l,r,1));
		}
	}	
	return 0;
}

