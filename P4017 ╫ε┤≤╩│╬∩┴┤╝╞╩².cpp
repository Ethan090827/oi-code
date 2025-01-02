#include <bits/stdc++.h>
#define ll long long
#define mod 80112002
using namespace std;
ll n,m,s,e,cnt[5005],ans;
bool f[5005];
vector <ll> r[5005];
vector <ll> r1[5005];
ll dfs(ll s)
{
	if(!r[s].size()) 
	{
		cnt[s]++;
		cnt[s]%=mod;
		return cnt[s];
	}
	if(cnt[s]) return cnt[s];
	for(int i=0;i<r[s].size();i++)
		cnt[s]+=dfs(r[s][i]);
	return cnt[s];	
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld",&s,&e);
		r[s].push_back(e);
		r1[e].push_back(s);
	}
	for(int i=1;i<=n;i++)
		if(!r1[i].size()) 
		{
			memset(cnt,0,sizeof(cnt));
			ans+=dfs(i);
			ans%=mod;
		}
	printf("%lld\n",ans%mod);
	return 0;
}

