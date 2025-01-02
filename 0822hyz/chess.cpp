#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,m,xs,ys,xt,yt,ans,d; 
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%lld",&t);
	for(int i=1;i<=t;i++)
	{
		ans=0x3f3f3f3f;
		scanf("%lld%lld%lld%lld%lld%lld",&n,&m,&xs,&ys,&xt,&yt);
		xs%=n;
		ys%=m;
		xt%=n;
		yt%=m;
		xs+=n;
		ys+=m;
		for(int xxt=xt;xxt<=xt+2*n;xxt+=n)
			for(int yyt=yt;yyt<=yt+2*m;yyt+=m)
			{
				d=min(abs(xs-xxt),abs(ys-yyt))+abs(abs(xs-xxt)-abs(ys-yyt));	
				ans=min(ans,d);
			}
				
		printf("%lld\n",ans);	
	}
	return 0;
}

