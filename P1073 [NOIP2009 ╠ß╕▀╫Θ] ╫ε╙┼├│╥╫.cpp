#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,p[100005],from,to,dir,mp[100005],dp[100005];
vector <ll> e[100005];
void dfs(ll x,ll minn,ll prev)
{
	bool flag=0;
	minn=min(minn,p[x]);
	if(mp[x]>minn)
	{
		mp[x]=minn;
		flag=1;
	}
	ll maxn=max(dp[prev],p[x]-minn);
	if(dp[x]<maxn)
	{
		dp[x]=maxn;
		flag=1;
	}
	if(!flag) return;
	for(int i=0;i<e[x].size();i++)
		dfs(e[x][i],minn,x);
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%lld%lld",&n,&m);
	memset(mp,0x3f,sizeof(mp));
	for(int i=1;i<=n;i++)
		scanf("%lld",&p[i]);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&from,&to,&dir);
		e[from].push_back(to);
		if(dir==2) e[to].push_back(from);
	}
	dfs(1,1<<30,0);
	printf("%lld\n",dp[n]);	
	return 0;
}

