#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll x,n,ans,pos,maxn;
struct chocolate
{
	mutable ll date,price,num;
	bool operator < (const chocolate &A) const
	{
		if(price==A.price) return date>A.date;
		return price>A.price;
	}
}a[100005];
bool cmp(chocolate a,chocolate b)
{
	return a.date<b.date;
}
priority_queue <chocolate> pq;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%lld%lld",&x,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&a[i].price,&a[i].date,&a[i].num);
		maxn=max(maxn,a[i].date);
	}
	if(maxn<x)
	{
		puts("-1");
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	pos=n;
	for(int i=x;i>=1;i--)
	{
		while(a[pos].date>=i) pq.push(a[pos--]);
		if(pq.empty())
		{
			puts("-1");
			return 0;
		}
		ans+=pq.top().price;
		if(--pq.top().num==0) pq.pop();
	}
	printf("%lld\n",ans);
	return 0;
}
