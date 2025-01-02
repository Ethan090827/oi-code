#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,ans,cnt;
bool f[200005],flag;
struct people
{
	ll l,r,c;
}a[200005];
void solve()
{
	flag=0;
	for(int i=1;i<=n;i++)
	{
		cnt=0;
		if(f[i]) continue;
		for(int j=a[i].l;j<=a[i].r;j++)
			if(f[j]) cnt++;
		if(cnt>=a[i].c) 
		{
			ans++;
			flag=1;
		}	
	}
	if(!flag) return;
	solve();	
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		memset(f,0,sizeof(f));
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
			scanf("%lld%lld%lld",&a[i].l,&a[i].r,&a[i].c);
		while(1)
		{
			flag=0;
			for(int i=1;i<=n;i++)
			{
				cnt=0;
				if(f[i]) continue;
				for(int j=a[i].l;j<=a[i].r;j++)
					if(f[j]) cnt++;
				if(cnt>=a[i].c) 
				{
					ans++;
					flag=1;
				}	
			}
			if(!flag) break;
		}
		for(int i=1;i<=n;i++)
		{
			if(f[i]) printf("1");
			else printf("0");
		}	
		puts("");
	}
	return 0;
}

