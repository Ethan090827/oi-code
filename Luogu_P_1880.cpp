#include <bits/stdc++.h>
#define ll long long
#define FileI(a) auto abcdefg=freopen(a,"r",stdin)
#define FileO(a) auto Abcdefg=freopen(a,"w",stdout)
#define scanf int ABCDEFG=scanf
using namespace std;
ll n,a[205],s[205],dpx[205][205],dpn[205][205],r,ansx=-1,ansn=1e10;
int main()
{
#ifndef ONLINE_JUDGE
	FileI(".in");
	FileO(".out");
#endif
	scanf("%lld",&n);
	memset(dpn,0x3f,sizeof(dpn));
	memset(dpx,-0x3f,sizeof(dpx));
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		s[i]=s[i-1]+a[i];
		dpx[i][i]=dpn[i][i]=0;
	}
	for(int i=n+1;i<=2*n;i++)
	{
		a[i]=a[i-n];
		s[i]=s[i-1]+a[i];
		dpx[i][i]=dpn[i][i]=0;
	}
	for(int len=2;len<=n;len++)
		for(int l=1;l<=2*n-len;l++)
		{
			r=l+len-1;
			for(int k=l;k<=r;k++)
			{
				dpx[l][r]=max(dpx[l][r],dpx[l][k]+dpx[k+1][r]+s[r]-s[l-1]);
				dpn[l][r]=min(dpn[l][r],dpn[l][k]+dpn[k+1][r]+s[r]-s[l-1]);
			}
		}
	for(int i=1;i<=n;i++)
	{
		ansx=max(ansx,dpx[i][i+n-1]);
		ansn=min(ansn,dpn[i][i+n-1]);
	}
	printf("%lld\n%lld\n",ansn,ansx);	
	return 0;
}
