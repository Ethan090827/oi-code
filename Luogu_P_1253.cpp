#include <bits/stdc++.h>
#define ll long long
#define MAXN 0x3f3f3f3f3f3f3f3f
using namespace std;
struct node
{
	ll l,r,maxn=-MAXN,add,change; //add是加标记 change是修改标记
}t[4000005];
ll n,a[1000005],l,r,x,q,op;
//修改
void change_change(ll id,ll change)
{
	t[id].add=0;
	t[id].change=change;
	t[id].maxn=change;
}
//加
void change_add(ll id,ll add)
{
	t[id].add+=add;
	t[id].maxn+=add;
}
//建树
void build(ll l,ll r,ll id)
{
	t[id].l=l;
	t[id].r=r;
	t[id].change=MAXN;
	if(l==r)
	{
		t[id].maxn=a[l];
		return;
	}
	ll lid=id*2,rid=id*2+1,mid=(l+r)/2;
	build(l,mid,lid);
	build(mid+1,r,rid);
	t[id].maxn=max(t[lid].maxn,t[rid].maxn);
}
//下放标记
void push_down(ll id)
{
	ll lid=id*2,rid=id*2+1;
	if(t[id].change<MAXN)
	{
		change_change(lid,t[id].change);
		change_change(rid,t[id].change);
	}
	if(t[id].add)
	{
		change_add(lid,t[id].add);
		change_add(rid,t[id].add);
	}
	t[id].change=MAXN;
	t[id].add=0;
}
//区间加
void edit_change(ll l,ll r,ll id,ll x)
{
	if(t[id].l>=l&&t[id].r<=r)
	{
		change_change(id,x);
		return;
	}
	if(t[id].l>r||t[id].r<l) return;
	ll lid=id*2,rid=id*2+1;
	push_down(id);
	edit_change(l,r,lid,x);
	edit_change(l,r,rid,x);
	t[id].maxn=max(t[lid].maxn,t[rid].maxn);
}
//区间修改
void edit_add(ll l,ll r,ll id,ll x)
{
	if(t[id].l>=l&&t[id].r<=r)
	{
		change_add(id,x);
		return;
	}
	if(t[id].l>r||t[id].r<l) return;
	push_down(id);
	ll lid=id*2,rid=id*2+1;
	edit_add(l,r,lid,x);
	edit_add(l,r,rid,x);
	t[id].maxn=max(t[lid].maxn,t[rid].maxn);
}
//区间查询
ll query(ll l,ll r,ll id)
{
	if(t[id].l>=l&&t[id].r<=r) return t[id].maxn;
	if(t[id].l>r||t[id].r<l) return -MAXN;
	push_down(id);
	ll lid=id*2,rid=id*2+1;
	return max(query(l,r,lid),query(l,r,rid));
}
//快读
char buf[1<<20],*p1,*p2;
#define getchar() ((p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2))?0:*p1++)
ll read()
{
	char ch=getchar();
	int x = 0, f = 1;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
#undef getchar

int main()
{
	n=read();
	q=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	build(1,n,1);
	while(q--)
	{
		op=read();
		if(op==1)
		{
			l=read();
			r=read();
			x=read();
			edit_change(l,r,1,x);
		}
		if(op==2)
		{
			l=read();
			r=read();
			x=read();
			edit_add(l,r,1,x);
		}
		if(op==3)
		{
			l=read();
			r=read();
			printf("%lld\n",query(l,r,1));
		}
	}
	return 0;
}
