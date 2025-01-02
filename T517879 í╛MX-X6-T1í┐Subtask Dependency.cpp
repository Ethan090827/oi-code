#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,d[105],a[105][105],p[105],m,flag,ans,f[105];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&d[i]);
		for(int j=1;j<=d[i];j++) 
			scanf("%lld",&a[i][j]);
	}
	scanf("%lld",&m);
	while(m--)
	{
		ans=0;
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++)
			scanf("%lld",&p[i]);
		for(int i=1;i<=n;i++)
		{
			if(!p[i]) f[i]=1;
			flag=0;
			for(int j=1;j<=d[i];j++)
				if(f[a[i][j]])
				{
					flag=1;
					break;
				}
			if(flag) 
			{
				f[i]=1;
				continue;
			}
			if(!f[i]) ans++;
		}	
		printf("%lld\n",ans);
	}
	return 0;
}

