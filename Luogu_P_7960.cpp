#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll t,x,ans[10000005],cnt;
bool f[10000005];
bool check(ll x)
{
	while(x)
	{
		if(x%10==7) return 1;
		x/=10;
	}
	return 0;
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	for(int i=1;i<=1e7+5;i++)
		if(check(i))
			for(int j=1;i*j<=1e7+5;j++)
				f[i*j]=1;
	for(int i=1;i<=1e7+5;i++)
		if(!f[i]) ans[++cnt]=i;			
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&x);
		if(f[x]) puts("-1");
		else 
		{
			auto it=lower_bound(ans+1,ans+cnt+1,x)-ans-1;
			printf("%lld\n",ans[it+2]);
		}	
	}
	return 0;
}
