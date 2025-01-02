#include <bits/stdc++.h>
#define ll long long
#define lid id*2
#define rid id*2+1
#define mid (l+r)/2
using namespace std;
struct node
{
	ll l,r,cnt,tag;
}t[400005];
ll n,m,c,l,r;
void build(ll l,ll r,ll id)
{
	t[id].l=l;
	t[id].r=r;
	if(l==r)
	{
		t[id].cnt=0;
		return;
	} 
	build(l,mid,lid);
	build(mid+1,r,rid);
	t[id].cnt=t[lid].cnt+t[rid].cnt;
}
void push_down(ll id)
{
	if(!t[id].tag) return;
	t[lid].tag^=1;
	t[rid].tag^=1;
	t[lid].cnt=(t[lid].r-t[lid].l+1)-t[lid].cnt;
	t[rid].cnt=(t[rid].r-t[rid].l+1)-t[rid].cnt;
	t[id].tag=0;
}
void edit(ll l,ll r,ll id)
{
	if(l<=t[id].l&&r>=t[id].r)
	{
		t[id].tag^=1;
		t[id].cnt=(t[id].r-t[id].l+1)-t[id].cnt;
		return;
	}
	if(t[id].l>r||t[id].r<l) return;
	push_down(id);
	edit(l,r,lid);
	edit(l,r,rid);
	t[id].cnt=t[lid].cnt+t[rid].cnt;
}
ll query(ll l,ll r,ll id)
{
	ll ans;
	if(l<=t[id].l&&r>=t[id].r) return t[id].cnt;
	if(t[id].l>r||t[id].r<l) return 0;
	push_down(id);
	return query(l,r,lid)+query(l,r,rid);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	scanf("%lld%lld",&n,&m);
	build(1,n,1);
	while(m--)
	{
		scanf("%lld%lld%lld",&c,&l,&r);
		if(!c) edit(l,r,1);
		else printf("%lld\n",query(l,r,1));
	}
	return 0;
}