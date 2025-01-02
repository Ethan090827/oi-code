#include <bits/stdc++.h>
#define ll long long
#define FileI(a) auto abc=freopen(a,"r",stdin);while(abc!=abc);
#define FileO(a) auto Abc=freopen(a,"w",stdout);while(Abc!=Abc);
#define scanf auto ABC=scanf
using namespace std;
ll n,m1,m2,deg[100005],a,b,res[100005],k;
vector <ll> e[100005];
queue <ll> q;
int main()
{
#ifndef ONLINE_JUDGE
	FileI(".in");
	FileO(".out");
#endif
	scanf("%lld %lld %lld",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
	{
		scanf("%lld%lld",&a,&b);
		deg[b]++;
		e[a].push_back(b);
	}
	for(int i=1;i<=n;i++)
		if(!deg[i]) q.push(i);
	while(!q.empty())
	{
		ll id=q.front();
		q.pop();
		res[id]=++k;
		for(unsigned int i=0;i<e[id].size();i++)
		{
			deg[e[id][i]]--;
			if(!deg[e[id][i]]) q.push(e[id][i]);
		}
	}
	for(int i=1;i<=m2;i++)
	{
		scanf("%lld%lld",&a,&b);
		if(res[a]<res[b]) printf("%lld %lld\n",a,b);
		else printf("%lld %lld\n",b,a);
	}
	return 0;
}
