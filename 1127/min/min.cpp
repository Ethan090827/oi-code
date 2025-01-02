#include <bits/stdc++.h>
#define ll long long
#define FileI(a) auto abcdefg=freopen(a,"r",stdin)
#define FileO(a) auto Abcdefg=freopen(a,"w",stdout)
#define scanf int ABCDEFG=scanf
using namespace std;
ll n,a[200005],b[200005],l,r,min1,min2,ans;
int main()
{
#ifndef ONLINE_JUDGE
	FileI("min3.in");
	FileO("min.out");
#endif
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%lld",&b[i]);
	for(int k=1;k<=n;k++)
	{
		ans=1<<30;
		for(l=1;l<=n;l++)
		{
			r=l+k-1;
			min1=min2=1<<30;
			if(r>n) break;
			for(int i=l;i<=r;i++)
			{
				min1=min(min1,a[i]);
				min2=min(min2,b[i]);
			}	
			ans=min(ans,abs(min1-min2));		
		}
		printf("%lld\n",ans);
	}	
	return 0;
}
