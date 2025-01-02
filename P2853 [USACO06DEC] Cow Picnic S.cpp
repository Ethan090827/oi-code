#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll k,n,m,l[105],cnt,s,e;
vector <ll> r[1005];
bool f[105],flag,vis[1005];
void dfs(ll s)
{
	vis[s]=1;
	for(int i=1;i<=k;i++)
		if(l[i]==s) f[i]=1;
	for(int i=0;i<r[s].size();i++)
		if(!vis[r[s][i]]) dfs(r[s][i]);
	return;	
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%lld%lld%lld",&k,&n,&m);
	for(int i=1;i<=k;i++)
		scanf("%lld",&l[i]);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld",&e,&s);
		r[s].push_back(e);
	}
	for(int i=1;i<=n;i++)
	{
		memset(f,0,sizeof(f));
		memset(vis,0,sizeof(vis));
		dfs(i);
		flag=0;
		for(int j=1;j<=k;j++)
			if(!f[j])
			{
				flag=1;
				break;
			}
		if(!flag) cnt++;
	}
	printf("%lld\n",cnt);		
	return 0;
}
