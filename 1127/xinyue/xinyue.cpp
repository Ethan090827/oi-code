#include <bits/stdc++.h>
#define ll long long
#define FileI(a) auto abcdefg=freopen(a,"r",stdin)
#define FileO(a) auto Abcdefg=freopen(a,"w",stdout)
#define scanf int ABCDEFG=scanf
using namespace std;
ll n,h[200005],A,a[200005],flag,vis[200005],ans=1<<30;
void dfs(ll H)
{
	ll f=0;
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			vis[i]=1;
			ll tA=A,tH=a[i]*(ceil(h[i]*1.0/A)-1);
			H+=tH;
			A=max(A,a[i]);
			dfs(H);
			vis[i]=0;
			A=tA;
			H-=tH;
			f=1;
		}
	if(!f) ans=min(ans,H);
}
bool check(ll H)
{
	for(int i=1;i<=n;i++)
	{
		H-=a[i]*(ceil(h[i]*1.0/A)-1);
		A=max(A,a[i]);
		if(H<0) return 0;
	}
	return 1;
}
int main()
{
#ifndef ONLINE_JUDGE
	FileI("xinyue.in");
	FileO("xinyue.out");
#endif
	scanf("%lld%lld",&n,&A);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld",&a[i],&h[i]);
	dfs(0);
	printf("%lld\n",ans);
	return 0;
}
