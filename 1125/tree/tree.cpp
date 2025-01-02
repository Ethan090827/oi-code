#include <bits/stdc++.h>
#define ll long long
#define FileI(a) auto abcdefg=freopen(a,"r",stdin)
#define FileO(a) auto Abcdefg=freopen(a,"w",stdout)
#define scanf int ABCDEFG=scanf
using namespace std;
ll t,x,ans,N;
int main()
{
//	freopen("ex_tree3.in","r",stdin);
//	freopen("tree.out","w",stdout);
	scanf("%lld",&t);
	N=sqrt(5e7/t)/2;
	while(t--)
	{
		scanf("%lld",&x);
		ans=LONG_LONG_MAX;
		for(ll p=max(1.0,sqrt(x)-N);p<=sqrt(x)+N;p++)
			for(ll q=max(x/p-N,1ll);q<=x/p+N;q++)
			{
				ll dis=abs(x-p*q);
				if(dis==0) ans=min(ans,p+q+1);
				else if((dis<p-1||dis<q-1)&&((p+dis)%2==0||(q+dis)%2==0))
					ans=min(ans,p+q+2);
			}
		printf("%lld\n",ans);
    }
	return 0;
}
