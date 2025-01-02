#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[10005],cnt=1;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		if(a[i]!=a[i-1]) cnt++;
		if(cnt==k)
		{
			printf("%lld\n",a[i]);
			return 0;
		}
	}
	printf("NO RESULT\n");
	return 0;
}

