#include <bits/stdc++.h>
#define ll long long
#define FileI(a) auto abcdefg=freopen(a,"r",stdin)
#define FileO(a) auto Abcdefg=freopen(a,"w",stdout)
#define scanf int ABCDEFG=scanf
#define MAXN 800005
using namespace std;
struct edge
{
	ll to,c,next;
}e[MAXN*3];
ll n,x[MAXN],y[MAXN],c[MAXN],ans,ed,k,head[MAXN];
bool vis[MAXN];
void adde(int ai,int bi,int ci)
{
	e[++k].to=bi;
	e[k].next=head[ai];
	e[k].c=ci;
	head[ai]=k;
}
void Dfs(ll pos,ll minn)
{
	vis[pos]=1;
	for(int i=head[pos];i;i=e[i].next)
    {
        ll to=e[i].to,C=e[i].c;
        if(!vis[to]&&(pos!=x[ed]||to!=y[ed])&&(pos!=y[ed]||to!=x[ed]))
		{
			ll t=min(minn,C);
			if(t<LONG_LONG_MAX) ans+=t;
			Dfs(to,t);
		}
    }
	vis[pos]=0;	
}
int main()
{
#ifndef ONLINE_JUDGE
	FileI("tatooine6.in");
	FileO("tatooine6.out");
#endif
	scanf("%lld",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%lld%lld%lld",&x[i],&y[i],&c[i]);
		adde(x[i],y[i],c[i]);
		adde(y[i],x[i],c[i]);
	}
	for(int I=1;I<n;I++)
	{
		if(n>600) puts("0");
		ed=I;
		ans=0;
		for(int x=1;x<=n;x++)
		{
			bool vis[MAXN]={0};
			Dfs(x,LONG_LONG_MAX);
		}
		printf("%lld\n",ans/2);
	}
	return 0;
}
