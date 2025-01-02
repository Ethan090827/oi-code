#include <bits/stdc++.h>
#define ll long long
#define N 200005
#define LLM LONG_LONG_MAX
using namespace std;
ll n,m,s,l[N],r[N],w[N],v[N],L=LLM,R,mid,t,y,ans=LLM,p[N],q[N];
bool check(ll x)
{
	memset(p,0,sizeof(p));
	memset(q,0,sizeof(q));
	for(int i=1;i<=n;i++)
	{
		if(w[i]>mid) q[i]=q[i-1]+1,p[i]=p[i-1]+v[i];
		else q[i]=q[i-1],p[i]=p[i-1];
	}
	y=0;
	for(int i=1;i<=m;i++)
		y+=(q[r[i]]-q[l[i]-1])*(p[r[i]]-p[l[i]-1]);
	t=abs(y-s);
	return y>s;  
}	
int main()
{
#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	scanf("%lld%lld%lld",&n,&m,&s);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&w[i],&v[i]);
		R=max(R,w[i]);
		L=min(L,w[i]);
	}
	for(int i=1;i<=m;i++)
		scanf("%lld%lld",&l[i],&r[i]);
	L--;
	R+=2;
	while(L<=R)
	{
		mid=(L+R)/2;
		if(check(mid)) L=mid+1;
		else R=mid-1;
		ans=min(ans,t);
	}
	printf("%lld\n",min(ans,t));
	return 0;
}
