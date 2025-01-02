#include <bits/stdc++.h>
#define ll long long
#define MAXN 5005
#define MAXM 10005
using namespace std;
ll cnt_edge,head[MAXN],n,m,x,y,w;
struct edge
{
	ll to,next,w;
}edges[MAXM];
void add_edge(ll from,ll to,ll w)
{
	edges[++cnt_edge].next=head[from];
	edges[cnt_edge].to=to;
	edges[cnt_edge].w=w;
	head[from]=cnt_edge;
}
bool inqueue[MAXN];
ll cnt[MAXN], dis[MAXN];
queue <ll> Q;
bool SPFA(ll s,ll n)
{
	memset(dis,127,sizeof(dis));
	dis[s]=0;
	Q.push(s);
	while(!Q.empty())
	{
		ll p=Q.front();
		if(cnt[p]>n) return 0;
		Q.pop();
		inqueue[p]=0;
		for(int eg=head[p];eg!=0;eg=edges[eg].next)
		{
			ll to=edges[eg].to;
			if(edges[eg].w+dis[p]<dis[to])
			{
				dis[to]=edges[eg].w+dis[p];
				if(!inqueue[to])
				{
					Q.push(to);
					inqueue[to]=1;
					cnt[to]++;
				}
			}
		}
	}
	return 1;
}
int main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=0;i<m;i++	)
	{
		scanf("%lld%lld%lld",&x,&y,&w);
		add_edge(y,x,w);
	}
	for(int i=1;i<=n;i++)
		add_edge(0,i,0);
	if(SPFA(0,n))
		for (int i=1;i<=n;i++)
			printf("%lld ",dis[i]);
	else puts("NO");
	return 0;
}