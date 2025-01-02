#include <bits/stdc++.h>
#define ll long long
#define FileI(a) auto abcdefg=freopen(a,"r",stdin)
#define FileO(a) auto Abcdefg=freopen(a,"w",stdout)
#define scanf int ABCDEFG=scanf
using namespace std;
ll n,p,s,w[1005],v[1005],l,r=LONG_LONG_MAX,mid,dp[1005];
bool check(ll L)
{
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++)
		if(w[i]<=L)
			for(int R=s;R>=w[i];R--)
				dp[R]=max(dp[R],dp[R-w[i]]+v[i]);
	return dp[s]>=p;
}
int main()
{
#ifndef ONLINE_JUDGE
	FileI(".in");
	FileO(".out");
#endif
	scanf("%lld%lld%lld",&n,&p,&s);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld",&w[i],&v[i]);
	if(!check(r))
	{
		puts("No Solution!");
		return 0;
	}	
	while(l<=r)
	{
		mid=(l+r)/2;
		if(check(mid)) r=mid-1;
		else l=mid+1;
	}
	printf("%lld\n",l);
	return 0;
}
