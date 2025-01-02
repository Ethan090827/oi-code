#include <bits/stdc++.h>
#define ll long long
#define MAXN 5000005
using namespace std;
ll Log2[MAXN],fa[MAXN][20],dep[MAXN],n,m,s,x,y;
bool vis[MAXN];
vector <ll> e[500005];
void dfs(ll cur,ll fath=0)
{
	if(vis[cur]) return;
	vis[cur]=1;
	dep[cur]=dep[fath]+1;
	fa[cur][0]=fath;
	for(int i=1;i<=Log2[dep[cur]];i++)
		fa[cur][i]=fa[fa[cur][i-1]][i-1];
	for(unsigned int i=0;i<e[cur].size();i++)
		dfs(e[cur][i],cur);
}
ll lca(ll a,ll b)
{
	if(dep[a]>dep[b]) swap(a,b);
	while(dep[a]!=dep[b])
		b=fa[b][Log2[dep[b]-dep[a]]];
	if(a==b) return a;
	for(int k=Log2[dep[a]];k>=0;k--)
		if(fa[a][k]!=fa[b][k])
		{
			a=fa[a][k];
			b=fa[b][k];
		}
	return fa[a][0];
}
int main()
{
	scanf("%lld%lld%lld",&n,&m,&s);
	for(int i=2;i<=n;i++)
		Log2[i]=Log2[i/2]+1;
	for(int i=1;i<n;i++)
	{
		scanf("%lld%lld",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(s);
	while(m--)
	{
		scanf("%lld%lld",&x,&y);
		printf("%lld\n",lca(x,y));
	}
	return 0;
}
