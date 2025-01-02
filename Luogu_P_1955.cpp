#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,m[200005],k,f[100005],flag,x,y;
struct limit
{
	ll i,j,e;
}a[100005];
bool cmp(limit a,limit b)
{
	return a.e>b.e;
}
ll findfa(ll x)
{
	if(f[x]==x) return x;
	return f[x]=findfa(f[x]);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	scanf("%lld",&t);
	while(t--)
	{
		memset(f,0,sizeof(f));
		flag=0;
		k=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&a[i].i,&a[i].j,&a[i].e);
			m[++k]=a[i].i;
			m[++k]=a[i].j;
		}
		sort(m+1,m+k+1);
		k=unique(m+1,m+k+1)-m;
		for(int i=1;i<=n;i++)
		{
			a[i].i=lower_bound(m+1,m+k+1,a[i].i)-m;
			a[i].j=lower_bound(m+1,m+k+1,a[i].j)-m;
		}
		for(int i=1;i<=k;i++) f[i]=i;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			x=findfa(a[i].i);
			y=findfa(a[i].j);
			if(a[i].e&&x!=y) f[x]=y;
			if(!a[i].e&&x==y)
			{
				flag=1;
				break;
			}
		}
		if(flag) puts("NO");
		else puts("YES");
	}
	return 0;
}
