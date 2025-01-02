#include <bits/stdc++.h>
#define ll long long
#define FileI(a) auto abcdefg=freopen(a,"r",stdin)
#define FileO(a) auto Abcdefg=freopen(a,"w",stdout)
#define scanf int ABCDEFG=scanf
using namespace std;
ll n,ans=LONG_LONG_MAX,x,cnt;
struct people
{
	ll a,b;
}t[100005];
bool cmp(people x,people y)
{
	return x.b<y.b;
}
int main()
{
#ifndef ONLINE_JUDGE
	FileI("boast4.in");
	FileO("boast4.ans");
#endif
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld",&t[i].a,&t[i].b);
	sort(t+1,t+n+1,cmp);	
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
