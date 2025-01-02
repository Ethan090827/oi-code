#include <bits/stdc++.h>
#define ll long long
#define MAXN (ll)1e9
#define FileI(a) auto abcdefg=freopen(a,"r",stdin)
#define FileO(a) auto Abcdefg=freopen(a,"w",stdout)
#define scanf int ABCDEFG=scanf
using namespace std;
ll n,m,a[200005][25],b[200005][25];
ll min1,min2,Log[200005],s,ans,fA,fB,l,r;
int main()
{
#ifndef ONLINE_JUDGE
	FileI("min.in");
	FileO("min.out");
#endif
	for(int i=2;i<=200000;i++)
		Log[i]=Log[i>>1]+1;
	scanf("%lld",&n);	
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i][0]);
		a[i][0]=-a[i][0];
	}		
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&b[i][0]);
		if(b[i][0]!=1) fA=1;
		b[i][0]=-b[i][0];
	}
	//special feature A
	if(!fA)
	{
		ans=MAXN;
		for(int i=1;i<=n;i++)
			ans=min(ans,-a[i][0]);
		for(int i=1;i<=n;i++)	
			printf("%lld\n",ans-1);
		return 0;	
	}
	//else
	for(int j=1;j<=Log[n];j++)	
		for(int i=1;i+(1<<(j-1))<=n;i++)
			a[i][j]=max(a[i][j-1],a[i+(1<<(j-1))][j-1]);	
	for(int j=1;j<=Log[n];j++)	
		for(int i=1;i+(1<<(j-1))<=n;i++)
			b[i][j]=max(b[i][j-1],b[i+(1<<(j-1))][j-1]);	
	for(int k=1;k<=n;k++)
	{
		ans=MAXN;
		for(l=1;l<=n-k+1;l++)
		{
			r=l+k-1;
			for(int i=l;i<=r;i++)
			{
				s=Log[r-l+1];
				min1=-max(a[l][s],a[r-(1<<s)+1][s]);
				min2=-max(b[l][s],b[r-(1<<s)+1][s]);
			}	
			ans=min(ans,abs(min1-min2));		
		}
		printf("%lld\n",ans);
	}	
	return 0;
}
