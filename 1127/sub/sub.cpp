#include <bits/stdc++.h>
#define ll long long
#define FileI(a) auto abcdefg=freopen(a,"r",stdin)
#define FileO(a) auto Abcdefg=freopen(a,"w",stdout)
#define scanf int ABCDEFG=scanf
using namespace std;
ll t,a,b;
void turn(ll &a,ll &b)
{
	swap(a,b);
	a=-a;
	b=-b;
}
int main()
{
#ifndef ONLINE_JUDGE
	FileI("sub.in");
	FileO("sub.out");
#endif
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&a,&b);
		if(a<b) swap(a,b);
		if(a*b>=0)
		{
			puts("0");
			continue;
		}
		if(a*b<0)
		{
			if(a<(-b)) turn(a,b);
			printf("%lld\n",min(a+b,-b));
		}
	}
	return 0;
}
