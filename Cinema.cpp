#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct film
{
	ll voi,sub;
}a[200005];
map <ll,ll> lan;
ll n,m,x,maxn=-1,ans[200005],res,cnt;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&x);
		lan[x]++;
	}
	scanf("%lld",&m);
	for(int i=1;i<=m;i++)
		scanf("%lld",&a[i].voi);
	for(int i=1;i<=m;i++)
		scanf("%lld",&a[i].sub);
	for(int i=1;i<=m;i++)
	{
		if(lan[a[i].voi]>maxn)
		{
			cnt=0;
			maxn=lan[a[i].voi];
			ans[++cnt]=i;
		} 
		else if(lan[a[i].voi]==maxn) ans[++cnt]=i;
	}	
	maxn=-1; 
	for(int i=1;i<=cnt;i++)
		if(lan[a[ans[i]].sub]>maxn)
		{
			maxn=lan[a[ans[i]].sub];
			res=ans[i];
		}
	printf("%lld\n",res);	
	return 0;
}

