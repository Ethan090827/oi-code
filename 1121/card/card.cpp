#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[1000005],b[1000005],j=1,ans;
int main()
{
//	freopen("card4.in","r",stdin);
//	freopen("card.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld",&a[i],&b[i]);
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	ans=n;
	for(int i=2;i<=n;i++)
		if(a[i]>b[j])
		{
			ans--;
			j++;
		}	
	printf("%lld\n",ans);
	return 0;
}
