#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,h[105],f[105],g[105],ans;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&h[i]);	
		f[i]=g[i]=1;
	}
	for(int i=n-1;i>=1;i--)
		for(int j=i+1;j<=n;j++)
			if(h[i]>h[j]&&f[i]<=f[j]+1)
				f[i]=f[j]+1;
	for(int i=2;i<=n;i++)
		for(int j=1;j<i;j++)
			if(h[i]>h[j]&&g[i]<=g[j]+1)
				g[i]=g[j]+1;
	for(int i=1;i<=n;i++)
		ans=max(ans,f[i]+g[i]-1);
	printf("%lld\n",n-ans);				
	return 0;
}

