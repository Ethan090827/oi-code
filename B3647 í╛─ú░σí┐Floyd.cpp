//floyd

#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,dis[4505][4505],u,v,w;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		dis[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&u,&v,&w);
		dis[u][v]=dis[v][u]=min(w,dis[u][v]);
	}
	for(int k=1;k<=n;k++)
		for(int x=1;x<=n;x++)
			for(int y=1;y<=n;y++)
				dis[x][y]=min(dis[x][y],dis[x][k]+dis[k][y]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%lld ",dis[i][j]);
		puts("");	
	}
	return 0;
}
