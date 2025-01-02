#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,l,r,t,cnt,w,cntt,id[1005];
set <ll> c[1005];
struct edge
{
	ll from,to,w;
}E[1000005],e[1000005];
bool cmp(edge a,edge b)
{
	return a.w<b.w;
}
ll find(ll p)
{
	if(id[p]==p) return p;
	return id[p]=find(id[p]);
}
ll kruskal()
{
	ll ans=0,k=0;
	sort(e,e+cntt,cmp);
	for(int i=0;i<cnt;i++)
	{
		ll p=find(e[i].from),q=find(e[i].to);
		if(p==q) continue;
		ans+=e[i].w;
		id[p]=q;
		if(++k==n-1) break;
	}
	return ans;
}
int main()
{
//	freopen("city3.in","r",stdin);
//	freopen("city.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		t=i;
		cnt=0;
		while(t)
		{
			if(t%2) c[i].insert(cnt++);
			t/=2;
		}
		// printf("%d:",i);
		// for(ll j:c[i]) printf("%lld ",j);
		// puts("");
	}
	cnt=0;
	for(int i=1;i<=n;i++)
	{
		set <ll> s=c[i];
		for(int j=i+1;j<=n;j++)
		{
			w=0;
			for(ll k:c[j])
				c[i].insert(k);
			for(ll k:c[i])
				w+=(1<<k);
			E[cnt++]=(edge){i,j,w};
			E[cnt++]=(edge){j,i,w};
			c[i]=s;
		}
	}
	// for(int i=0;i<cnt;i++)
	// 	printf("%lld %lld %lld\n",E[i].from,E[i].to,E[i].w);
	while(m--)
	{
		scanf("%lld%lld",&l,&r);
		cntt=0;
		for(int i=0;i<cnt;i++)
			if(E[i].from>=l&&E[i].from<=r&&E[i].to>=l&&E[i].to<=r)
				e[cntt++]=E[i];
		// puts("");		
		// for(int i=0;i<cntt;i++)
		// 	printf("%lld %lld %lld\n",e[i].from,e[i].to,e[i].w);		
		for(int i=1;i<=n;i++) id[i]=i;
		printf("%lld\n",kruskal());	
	}
	return 0;
}
