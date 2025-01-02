#include <bits/stdc++.h>
#define ll long long
#define FileI(a) auto abcdefg=freopen(a,"r",stdin)
#define FileO(a) auto Abcdefg=freopen(a,"w",stdout)
#define scanf int ABCDEFG=scanf
using namespace std;
ll n,a[15],b[15]={0,1,3,5,7,9,10,11,14,15,17},w[15],dp[15][100005];
int main()
{
#ifndef ONLINE_JUDGE
	FileI(".in");
	FileO(".out");
#endif
	scanf("%d",&n);
	for(int i=1;i<=10;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=10;i++)
		for(int j=i;j<=10;j++)
			w[j]=max(w[j],w[j-i]+a[i]);
	for(int i=1;i<=10;i++)
		w[i]-=b[i];
	for(int i=1;i<=10;i++)
		for(int j=1;j<=n;j++)
		{
			dp[i][j]=dp[i-1][j];
			if(j>=i) dp[i][j]=max(dp[i][j],dp[i][j-i]+w[i]); 
		}
	printf("%lld\n",dp[10][n]);
	return 0;
}
