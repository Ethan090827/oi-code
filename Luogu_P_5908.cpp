#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,d,u,v,ans,vis[100005];
vector <ll> e[100005];
void dfs(ll pos,ll depth)
{
	vis[pos]=1;
	if(depth==d) return;
	for(ll i:e[pos])
		if(!vis[i])
		{
			dfs(i,depth+1);
			ans++;
		}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	scanf("%lld%lld",&n,&d);
	for(int i=1;i<n;i++)
	{
		scanf("%lld%lld",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	printf("%lld\n",ans);
	return 0;
}
