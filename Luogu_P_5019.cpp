#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[100005],ans;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=2;i<=n;i++)
		if(a[i]>a[i-1]) ans+=a[i]-a[i-1];
	printf("%lld\n",ans+a[1]);	
	return 0;
}
