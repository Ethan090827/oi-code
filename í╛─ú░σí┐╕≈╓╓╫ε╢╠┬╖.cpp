#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,s,u,v,w,dis[100005],minn,diss[5005][5005];
bool flag,vis[100005];
struct edge
{
	ll to,w;
};
//Dij堆优用
struct node
	{
		ll id,dis;
		bool operator > (const node & a) const
		{
			return dis>a.dis;
		}
	};
vector <edge> e[100005];

//Floyd
//O(n^3)
//多源，u-->v 的最短路为 dis[u][v]
//边权可为负，但不能有负环
void Floyd()
{
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)
	{
		diss[i][i]=0;
		for(unsigned int j=0;j<e[i].size();j++)
			diss[i][e[i][j].to]=e[i][j].w;
	}
	for(int k=1;k<=n;k++)
		for(int x=1;x<=n;x++)
			for(int y=1;y<=n;y++)
				diss[x][y]=min(diss[x][y],diss[x][k]+diss[k][y]);
}

//Bellman-Ford
//O(nm)
//单源，s-->e 的最短路为 dis[e]
//边权可为负 可判负环
//返回值为1说明有负环
bool Bellman_Ford(ll s)
{
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	for(int i=1;i<=n;i++)
	{
		flag=0;
		for(int j=1;j<=n;j++)
			for(unsigned int k=0;k<e[j].size();k++)
			{
				u=j;
				v=e[j][k].to;
				w=e[j][k].w;
				if(dis[u]>(1<<30)) continue;
				if(dis[v]>dis[u]+w)
				{
					dis[v]=dis[u]+w;
					flag=1;
				}
			}
		if(!flag) break;
	}
	return flag; //第n遍还能松弛说明有负环
}

//SPFA
//实为Bellman-Ford的优化
//O(kn)，稀疏图快(k约等于2)，稠密图(m很大时)退化至O(mn)
//其余同Bellman-Ford
bool SPFA(ll s)
{
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
	return flag;
}

//朴素Dij
//O(n^2)
//单源，s-->e 的最短路为 dis[e]
//无负权边
void Normal_Dij(ll s)
{
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
}	

//堆优化Dij
//O((n+m)logn)
//单源，s-->e 的最短路为 dis[e]
//无负权边
//在无负权边的情况下的最稳定做法
void Dij_With_Pq(ll s)
{
	priority_queue <node,vector <node>,greater <node>> pq;
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
}	
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
	puts("Floyd:");
	Floyd();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%lld ",diss[i][j]);
		puts("");	
	}
	puts("\nBellman-Ford:");
	printf("Negative Loop: %d\n",Bellman_Ford(s));
	for(int i=1;i<=n;i++)
	{
		if(dis[i]>(1<<30)) printf("-1 ");
		else printf("%lld ",dis[i]);
	}
	puts("");
	puts("\nSPFA:");
	printf("Negative Loop: %d\n",SPFA(s));
	for(int i=1;i<=n;i++)
	{
		if(dis[i]>(1<<30)) printf("-1 ");
		else printf("%lld ",dis[i]);
	}
	puts("");
	puts("\nNormal Dij:");
	Normal_Dij(s);
	for(int i=1;i<=n;i++)
	{
		if(dis[i]>(1<<30)) printf("-1 ");
		else printf("%lld ",dis[i]);
	}
	puts("");
	puts("\nDij with pq:");
	Dij_With_Pq(s);
	for(int i=1;i<=n;i++)
	{
		if(dis[i]>(1<<30)) printf("-1 ");
		else printf("%lld ",dis[i]);
	}
	puts("");
	return 0;
}
