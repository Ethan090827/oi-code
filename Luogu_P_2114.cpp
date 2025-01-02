#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,x=0,y=~x,t,ans;
string op;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		cin>>op;
		scanf("%lld",&t);
		if(op=="AND")
		{
			x&=t;
			y&=t;
		}
		if(op=="OR")
		{
			x|=t;
			y|=t;
		}
		if(op=="XOR")
		{
			x^=t;
			y^=t;
		}
	}
	for(int i=30;~i;i--)
	{
		if((x>>i)&1) ans+=1<<i;
		else if((y>>i&1)&&(1<<i)<=m)
		{
			ans+=(1<<i);
			m-=(1<<i);
		}	
	}
	printf("%lld\n",ans);
	return 0;
}
