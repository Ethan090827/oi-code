#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,p,a[100005],s[100005],w[100005],ans,W;
int main()
{
	while(1)
	{
		scanf("%lld",&n);
		if(n==0) break;
		ans=0;
		p=0;
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		a[n+1]=0;
		for(int i=1;i<=n+1;i++)
		{
			if(a[i]>s[p])
			{
				s[++p]=a[i];
				w[p]=1;
			}
			else
			{
				W=0;
				while(s[p]>a[i])
				{
					W+=w[p];
					ans=max(ans,W*s[p--]);
				}
				s[++p]=a[i];
				w[p]=W+1;
			}
		}
		printf("%lld\n",ans);
	}
}
