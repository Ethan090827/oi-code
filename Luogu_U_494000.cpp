#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll q,x,y;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%lld",&q);
	while(q--)
	{
		scanf("%lld%lld",&x,&y);
		if(x>y) swap(x,y);
		if(x==y)
		{
			puts("0");
			continue;
		}
		if(y%x==0)
		{
			printf("%lld\n",y);
			continue;
		}
		printf("%lld\n",x+y);
	}
	return 0;
}
