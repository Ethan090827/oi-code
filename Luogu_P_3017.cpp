#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll R,C,A,B,l=1<<30,r,mid,ans,a[505][505],s[505][505];
bool check(ll x)
{
	ll t=0,cnt,sum,k=0;
	for(int i=1;i<=R;i++)
	{
		cnt=sum=0;
		for(int j=1;j<=C;j++)
		{
			sum+=s[i][j]-s[t][j];
			if(sum >= x)
			{
				cnt++;
				sum=0;
			}
		}
		if(cnt>=B)
		{
			t=i;
			k++;
		}
	}
	return k>=A;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif	
	scanf("%lld%lld%lld%lld",&R,&C,&A,&B);
	for(int i=1;i<=R;i++)
		for(int j = 1; j <= C; ++j)
		{
			scanf("%lld",&a[i][j]);
			s[i][j]=s[i-1][j]+a[i][j];
			r+=a[i][j];
			l=min(l, a[i][j]);
		}
	while(l<=r)
	{
		mid=(l+r)/2;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	printf("%lld",l-1);
	return 0;
}
