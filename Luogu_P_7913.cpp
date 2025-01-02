#include <bits/stdc++.h>
#define ll long long
#define pll pair <ll,ll>
using namespace std;
ll n,m1,m2,ans1[100005],ans2[100005],ans;
struct flight
{
	ll arr,dep;
}dom[100005],intl[100005];
bool cmp(flight a,flight b)
{
	return a.arr<b.arr;
}
void solve(flight *t,ll m,ll *ans)
{
	priority_queue <pll,vector <pll>,greater <pll>> pqf;
	priority_queue <ll,vector <ll>,greater <ll>> pqb;
	for(int i=1;i<=n;i++)
		pqb.push(i);
	for(int i=1;i<=m;i++)
	{
		while(!pqf.empty()&&t[i].arr>=pqf.top().first)
		{
			pqb.push(pqf.top().second);
			pqf.pop();
		}
		if(pqb.empty()) continue;
		ans[pqb.top()]++;
		pqf.push(make_pair(t[i].dep,pqb.top()));
		pqb.pop();
	}
	for(int i=1;i<=n;i++)
		ans[i]+=ans[i-1];
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%lld%lld%lld",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
		scanf("%lld%lld",&dom[i].arr,&dom[i].dep);
	sort(dom+1,dom+m1+1,cmp);
	for(int i=1;i<=m2;i++)
		scanf("%lld%lld",&intl[i].arr,&intl[i].dep);
	sort(intl+1,intl+m2+1,cmp);
	solve(dom,m1,ans1);
	solve(intl,m2,ans2);
	for(int i=0;i<=n;i++)
		ans=max(ans,ans1[i]+ans2[n-i]);
	printf("%lld\n",ans);	
	return 0;
}
