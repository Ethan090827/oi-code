#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[100005],t,pos,neg;
int main()
{
#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(i==1) continue;
		t=a[i]-a[i-1];
		if(t>0) pos+=t;
		else neg-=t;
	}
	printf("%lld\n%lld\n",max(pos,neg),abs(pos-neg)+1);
	return 0;
}
