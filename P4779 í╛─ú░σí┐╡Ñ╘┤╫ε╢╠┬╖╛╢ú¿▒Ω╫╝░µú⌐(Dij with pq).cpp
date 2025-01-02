//Dij with pq optimization

#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,s,u,v,w,dis[100005],minn;
bool flag,vis[100005];
struct edge
{
	ll to,w;
};
struct node
{
	ll id,dis;
	bool operator > (const node & a) const
	{
		return dis>a.dis;
	}
};
vector <edge> e[100005];
priority_queue <node,vector <node>,greater <node>> pq;
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
	pq.push((node){s,0});
	while(!pq.empty())
	{
		u=pq.top().id;
		pq.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(unsigned int j=0;j<e[u].size();j++)
		{
			v=e[u][j].to;
			w=e[u][j].w;
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				pq.push((node){v,dis[v]});
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
