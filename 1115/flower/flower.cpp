#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[1000005],ans,flag;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
#endif
	scanf("%lld",&n);
	if(n==1)
	{
		puts("0");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		a[i]*=i;
	}
	while(1)
	{
		flag=0;
	#ifdef ONLINE_JUDGE
		for(int i=1;i<=n;i++)
			printf("%lld ",a[i]);
		puts("");
	#endif
		for(int i=1;i<n;i++)
			if(a[i]>a[i+1])
			{
				flag=1;
				swap(a[i],a[i+1]);
				a[i]=a[i]/(i+1)*i;
				a[i+1]=a[i+1]/i*(i+1);
				ans++;
			#ifdef ONLINE_JUDGE
				printf("swap #%d and #%d\n",i,i+1);
			#endif
			}
		if(!flag) break;
	}
	printf("%lld\n",ans);
	return 0;
}