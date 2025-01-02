#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,d,ans,cnt,flag;
double pos;
struct island
{
	ll x,y;
	double l,r;
}a[1005];
bool cmp(island a,island b)
{
	return a.l<b.l;
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	while(1)
	{
		scanf("%lld%lld",&n,&d);
		if(n==0&&d==0) break;
		ans=0;
		flag=0;
		pos=-100000000000;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld",&a[i].x,&a[i].y);
			if(d*d<a[i].y*a[i].y) 
			{
				flag=1;
				break;
			}	
			a[i].l=a[i].x-sqrt(d*d-a[i].y*a[i].y);
			a[i].r=a[i].x+sqrt(d*d-a[i].y*a[i].y);
		}
		if(flag||d<0)
		{
			printf("Case %lld: -1\n",++cnt);
			continue;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			if(pos<a[i].l)
			{
				ans++;
				pos=a[i].r;
			}
			else pos=min(pos,a[i].r);
		}
		printf("Case %lld: %lld\n",++cnt,ans);	
	}
	return 0;
}
