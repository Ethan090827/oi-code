#include <bits/stdc++.h>
#define ll long long
//#define _N2_ 1
#define FileI(a) auto abcdefg=freopen(a,"r",stdin)
#define FileO(a) auto Abcdefg=freopen(a,"w",stdout)
#define scanf int ABCDEFG=scanf
using namespace std;
ll n,a[5005],dp[5005],ans=1,len;
int main()
{
#ifndef ONLINE_JUDGE
	FileI(".in");
	FileO(".out");
#endif
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
#ifdef _N2_
	for(int i=1;i<=n;i++) dp[i]=1;
	for(int i=2;i<=n;i++)
		for(int j=1;j<i;j++)
			if(a[j]<a[i])
			{
				dp[i]=max(dp[i],dp[j]+1);
				ans=max(ans,dp[i]);
			}
	printf("%lld\n",ans);
#else
	dp[1]=a[1];
	len=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]>dp[len]) dp[++len]=a[i];
		else 
		{
			auto it=lower_bound(dp+1,dp+len+1,a[i]);
			*it=min(a[i],*it);
		}
	}
	printf("%lld\n",len);
#endif
	return 0;
}
