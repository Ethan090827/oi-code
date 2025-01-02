#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a,deg[105],top,cnt;
struct edge
{
	ll from,to;
}e[100005];
void build(ll from,ll to)
{
	e[++cnt].to=to;
	e[cnt].from=from;
	deg[to]++;
}
queue <ll> q;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		while(1)
		{
			scanf("%lld",&a);
			if(a==0) break;
			build(i,a);
		}
	for(int i=1;i<=n;i++)
		if(deg[i]==0) q.push(i);
	while(!q.empty())
	{
		top=q.front();
		q.pop();
		printf("%lld ",top);
		for(int i=1;i<=cnt;i++)
			if(e[i].from==top) 
			{
				deg[e[i].to]--;
				if(deg[e[i].to]==0) q.push(e[i].to);
			}
	}	
	return 0;
}

