#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct data
{
	int id,num;
}a[100005];
bool cmp(data a,data b)
{
	if(a.num==b.num) return a.id<b.id;
	return a.num<b.num;
}
ll n,ans=1,cnt,vis[100005];
int main()
{
#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif	
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i].num);
		a[i].id=i;
	}	
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(i<a[i].id) cnt++;
		if(vis[i]) cnt--;
		vis[a[i].id]=1;
		ans=max(ans,cnt);
	}
   printf("%lld\n",ans);
}