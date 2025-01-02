#include <bits/stdc++.h>
#define ll long long
#define id i*n+j-1
using namespace std;
ll t,n,m,a,s1[100005],s2[100005],dis[100005],cnt,cntt,minn,minm;
int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		cntt=0;
		cnt=0;
		scanf("%lld%lld",&n,&m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				scanf("%lld",&a);
				s1[id]=a;
			}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				scanf("%lld",&a);
				s2[id]=a;
				dis[id]=s2[id]-s1[id];
			}	
		while(1)
		{
			cntt++;
			minn=1<<30;
			for(int i=1;i<n;i++)
				for(int j=1;j<=m;j++)
					if(dis[id]>0) minn=min(minn,dis[id]);
			if(minn==1<<30) break;
			for(int i=1;i<=n;i++)
			{
				minm=1<<30;
				for(int j=1;j<=m;j++) 
					minm=min(minm,dis[id]);
				if(minm==minn)
				{
					for(int j=1;j<=m;j++)
						dis[id]-=minn;
					cnt+=minn;	
				}	
			}
			for(int j=1;j<=m;j++)
			{
				minm=1<<30;
				for(int i=1;i<=n;i++) 
					minm=min(minm,dis[id]);
				if(minm==minn)
				{
					for(int i=1;i<=n;i++)
						dis[id]-=minn;
					cnt+=minn;	
				}	
			}
//			if(cntt>=5000)
//			{
//				puts("-1");
//				break;
//			}		
		}
		printf("%lld\n",cnt);	
	}
	return 0;
}

