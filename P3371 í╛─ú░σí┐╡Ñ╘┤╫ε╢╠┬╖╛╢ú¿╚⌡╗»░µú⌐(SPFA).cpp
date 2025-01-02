//SPFA

#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,s,u,v,w,dis[10005];
bool flag,vis[10005];
struct edge
{
	ll to,w;
};
vector <edge> e[10005];
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
	queue <ll> q;
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	vis[s]=1;
	q.push(s);
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		vis[u]=0;
		for(unsigned int i=0;i<e[u].size();i++)
		{
			v=e[u][i].to;
			w=e[u][i].w;
			if(dis[v]>dis[u]+w) dis[v]=dis[u]+w;
			if(!vis[v])
			{
				q.push(v);
				vis[v]=1;
			}
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
