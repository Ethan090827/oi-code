#include <bits/stdc++.h>
#define ll long long
#define FileI(a) auto abcdefg=freopen(a,"r",stdin)
#define FileO(a) auto Abcdefg=freopen(a,"w",stdout)
#define scanf int ABCDEFG=scanf
using namespace std;
ll n,ans=LONG_LONG_MAX,x,cnt,minn;
struct people
{
	ll a,b;
}t[100005];
bool cmp(people x,people y)
{
	return x.a+x.b<y.a+y.b;
}
bool cmp1(people x,people y)
{
	return x.b<y.b;
}
int main()
{
#ifndef ONLINE_JUDGE
	FileI("boast4.in");
	FileO("boast.out");
#endif
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld",&t[i].a,&t[i].b);
	if(n<=1500)
	{
		sort(t+1,t+n+1,cmp1);	
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
				{
					x=t[i].a+max(t[i].b,t[j].b)+t[j].a+max(t[j].b,t[k].b)+t[k].a;
					ans=min(ans,x);
				}
		printf("%lld\n",ans);
		return 0;		
	}	
	sort(t+1,t+n+1,cmp);
	sort(t+1,t+4,cmp1);
	ans=t[1].a+t[2].a+t[3].a+t[2].b+t[3].b;
	for(int i=4;i<=n;i++)
	{
		x=t[2].a+t[3].a+t[i].a+t[3].b+max(t[i].b,t[2].b);
		ans=min(ans,x);
	}
	printf("%lld\n",ans);
	return 0;
}
