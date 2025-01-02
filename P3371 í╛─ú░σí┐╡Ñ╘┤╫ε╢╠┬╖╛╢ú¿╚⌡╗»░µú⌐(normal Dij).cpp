//Dij without pq optimization

#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,s,u,v,w,dis[100005],minn;
bool flag,vis[100005];
struct edge
{
	ll to,w;
};
vector <edge> e[100005];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&s);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&u,&v,&w);
		e[u].push_back((edge){v,w});
	} 
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	for(int i=1;i<=n;i++)
	{
		minn=1<<30;
		for(int j=1;j<=n;j++)
			if(!vis[j]&&dis[j]<minn)
			{
				u=j;
				minn=dis[j];
			}
		vis[u]=1;
		for(unsigned int j=0;j<e[u].size();j++)
		{
			v=e[u][j].to;
			w=e[u][j].w;
			if(dis[v]>dis[u]+w) dis[v]=dis[u]+w;
		}	
	}
	for(int i=1;i<=n;i++)
	{
		if(dis[i]>(1<<30)) printf("2147483647 ");
		else printf("%lld ",dis[i]);
	}
	puts("");
	return 0;
}
