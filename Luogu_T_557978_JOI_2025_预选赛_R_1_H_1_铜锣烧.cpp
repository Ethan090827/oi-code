#include <bits/stdc++.h>
#define ll long long
#define FileI(a) auto abc=freopen(a,"r",stdin)
#define FileO(a) auto Abc=freopen(a,"w",stdout)
#define scanf auto ABC=scanf
using namespace std;
ll n,m,a[105],b[105],ans;
int main()
{
#ifndef ONLINE_JUDGE
	FileI(".in");
	FileO(".out");
#endif
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++)
		scanf("%lld",&b[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			ans+=(a[i]+b[j])*max(a[i],b[j]);
	printf("%lld\n",ans);		
	return 0;
}
