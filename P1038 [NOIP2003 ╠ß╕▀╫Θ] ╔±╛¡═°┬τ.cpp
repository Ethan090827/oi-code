#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,p,c,u,from,to,w,cnt,top,flag;
struct edge
{
	ll from,to,w;
}e[10005];
struct point
{
	ll c,deg,isend;
}a[105]; 
void build(ll from,ll to,ll w)
{
	e[++cnt].from=from;
	e[cnt].to=to;
	e[cnt].w=w;
	a[to].deg++;
}
queue <ll> q;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%lld%lld",&n,&p);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&c,&u);
		a[i].c=c;
		if(c) a[i].deg=0;
		else a[i].c-=u;
	}
	for(int i=1;i<=p;i++)
	{
		scanf("%lld%lld%lld",&from,&to,&w);
		build(from,to,w);
		a[from].isend=1;
	}
	for(int i=1;i<=n;i++)
		if(a[i].deg==0) q.push(i);
	while(!q.empty())
	{
		top=q.front();
		q.pop();
		if(a[top].c<=0) continue;
		for(int i=1;i<=p;i++)
			if(e[i].from==top)
			{
				to=e[i].to;
				a[to].c+=e[i].w*a[top].c;
				a[to].deg--;
				if(a[to].deg==0) q.push(to);
			} 
	}	
	for(int i=1;i<=n;i++)
		if(!a[i].isend&&a[i].c>0) 
		{
			flag=1;
			printf("%lld %lld\n",i,a[i].c);
		}
	if(!flag) puts("NULL");	
	return 0;
}

