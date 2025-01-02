#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,ans[50005],cnt;
struct cow
{
	ll s,e,id;
}a[50005];
struct Cmp
{
	ll x;
	bool operator < (const Cmp &A) const
	{
		return a[x].e>a[A.x].e;
	}
};
bool cmp(cow a,cow b)
{
	return a.s<b.s;
}
priority_queue <Cmp> pq;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&a[i].s,&a[i].e);
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		Cmp t;
		t.x=i;
		if(!pq.empty())
		{
			Cmp p=pq.top();
			if(a[p.x].e>=a[i].s)
			{
				pq.push(t);
				ans[a[i].id]=++cnt;
			} 
			else
			{
				pq.pop();
				pq.push(t);
				ans[a[i].id]=ans[a[p.x].id];
			} 
		} 
		else
		{
			pq.push(t);
			ans[a[i].id]=++cnt;
		} 
	}
	printf("%lld\n",cnt);
	for(int i=1;i<=n;i++)
		printf("%lld\n",ans[i]);
	return 0;
}

