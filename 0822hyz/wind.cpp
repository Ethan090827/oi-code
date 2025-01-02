#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,m,x[200005],v[200005],cnt;
double v0;
int main()
{
	freopen("wind.in","r",stdin);
	freopen("wind.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		cnt=0;
		scanf("%lld%lld",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%lld",&x[i]);
		for(int i=1;i<=n;i++)
			scanf("%lld",&v[i]);
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
			{
				if(i==j) continue;
				if(x[i]==x[j])
				{
					if(v[i]==v[j])
					{
						cnt++;
						continue;
					}
					else continue;
				}
				v0=(x[j]*v[i]-x[i]*v[j])*1.0/(x[i]-x[j]);
				if(abs(v0)<=m) cnt++;
			}	
		printf("%lld\n",cnt);		
	}
	return 0;
}

