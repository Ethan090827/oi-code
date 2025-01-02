#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,t[20005],ans,cnt;
struct cow
{
	ll s,e;
}a[20005];
bool cmp(cow a,cow b)
{
	return a.e<b.e;
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%lld%lld",&c,&n);
	for(int i=1;i<=c;i++)
		scanf("%lld",&t[i]);
	sort(t+1,t+c+1);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld",&a[i].s,&a[i].e);	
	sort(a+1,a+n+1,cmp);
	cnt=n;
	for(int j=1;j<=n;j++)
	{
		for(int i=1;i<=c;i++)
			if(a[j].s<=t[i]&&t[i]<=a[j].e)
			{
				t[i]=1<<30;
				ans++;
				cnt--;
				break;
			}
		if(!cnt) break;	
	}	
	printf("%lld\n",ans);
	return 0;
}
