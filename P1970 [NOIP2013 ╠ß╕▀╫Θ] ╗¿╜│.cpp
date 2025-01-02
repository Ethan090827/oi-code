#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,h[100005],temp,ud,cnt1=1,cnt2=1;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&h[i]);
	ud=1;
	for(int i=2;i<=n;i++)
	{
		if(ud==1&&h[i]>h[i-1])
		{
			ud=0;
			cnt1++;
			continue;
		}
		if(ud==0&&h[i]<h[i-1])
		{
			ud=1;
			cnt1++;
			continue;
		}
	}
	ud=0;
	for(int i=2;i<=n;i++)
	{
		if(ud==1&&h[i]>h[i-1])
		{
			ud=0;
			cnt2++;
			continue;
		}
		if(ud==0&&h[i]<h[i-1])
		{
			ud=1;
			cnt2++;
			continue;
		}
	}
	printf("%lld\n",max(cnt1,cnt2));
	return 0;
}

