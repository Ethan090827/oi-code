#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,last[50005],cnt,s[50005],dp[50005],ans=1<<30,u,v;
vector <ll> e[50005];
void dfs(ll x,ll fa)
{
	for(ll i:e[x])
		if(i!=fa)
		{
			s[x]++;
			dfs(i,x);
			s[x]+=s[i];
		}
}
void dfs1(ll x,ll y)
{
	for(ll i:e[x])
	{
		if(x!=1) dp[x]=dp[y]+n-2*s[x];
		if(i==y) continue;
		dfs1(i,x);
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	scanf("%lld",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%lld%lld",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
		dp[1]+=s[i];
	for(int i=1;i<=n;i++) s[i]++;
	dfs1(1,0);
	for(int i=1;i<=n;i++)
		if(dp[i]<ans)
		{
			ans=dp[i];
			cnt=i;
		}
	printf("%lld %lld\n",cnt,ans);
	return 0;
}
