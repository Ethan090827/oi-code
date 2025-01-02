#include <bits/stdc++.h>
#define ll long long
#define MAXN 500005
using namespace std;
ll n,m,k,s,t,f[MAXN][21],x,y,z;
struct edge
{
	ll next,to,vl;
}p[MAXN];
ll head[MAXN],num;
void add(ll x,ll y,ll z)
{
	p[++num].next=head[x];
	p[num].to=y;
	p[num].vl=z;
	head[x]=num;
}
struct node
{
	ll x,vl;
	bool operator < (const node b) const
	{
		return vl>b.vl;
	}
}u;
priority_queue <node> pq;
void Dij()
{
	for(int i=0;i<=k;i++) 
		f[s][i]=0;
	for(int i=0;i<=k;i++)
	{
		pq.push((node){s,0});
		while(!pq.empty())
		{
			u=pq.top();
			pq.pop();
			if(u.vl>f[u.x][i]) continue;
			for(int j=head[u.x];j;j=p[j].next)
			{
				ll v=p[j].to,flag=0;
				if(i&&f[v][i]>f[u.x][i-1])
				{
					f[v][i]=f[u.x][i-1];
					flag=1;
				}
				if(f[v][i]>f[u.x][i]+p[j].vl)
				{
					f[v][i]=f[u.x][i]+p[j].vl;
					flag=1;
				}
				if(flag) pq.push((node){v,f[v][i]});
			}
		}
	}
}
int main()
{
	scanf("%lld%lld%lld%lld%lld",&n,&m,&k,&s,&t);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	memset(f,0x3f,sizeof(f));
	Dij();
	printf("%lld\n",f[t][k]);
	return 0;
}