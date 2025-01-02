#include <bits/stdc++.h>
#define ll long long
#define y1 Y1
using namespace std;
struct rect
{
	ll x1,y1,x2,y2;
}a[1005];
ll n,k,k1,k2,x1,x2,y1,y2,ans;
void add(ll x1,ll y1,ll x2,ll y2)
{
	a[++k]=(rect){x1,y1,x2,y2};
}
void cut(ll p,ll x1,ll y1,ll x2,ll y2,ll op)
{
	ll k1,k2;
	if(!op)
	{
		k1=max(x1,a[p].x1);
		k2=min(x2,a[p].x2);
		if(a[p].x1<k1) add(a[p].x1,a[p].y1,k1,a[p].y2);
		if(k2<a[p].x2) add(k2,a[p].y1,a[p].x2,a[p].y2);
		cut(p,k1,y1,k2,y2,1);
	}
	else
	{
		k1=min(y1,a[p].y1);
		k2=max(y2,a[p].y2);
		if(a[p].y1>k1) add(x1,a[p].y1,x2,k1);
		if(k2>a[p].y2) add(x1,k2,x2,a[p].y2);
	}
}
int main()
{
	scanf("%lld",&n);
	ll x1,y1,x2,y2;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
		if(i==1)
		{
			add(x1,y1,x2,y2);
			continue;
		}
		for(int j=1;j<=k;j++)
		{
			if(a[j].x1>=x2||a[j].x2<=x1||a[j].y1<=y2||a[j].y2>=y1)continue;//判断是否相交
			cut(j,x1,y1,x2,y2,0);
			a[j]=a[k];
			k--;
			j--;
		}
		add(x1,y1,x2,y2);
	}
	for(int i=1;i<=k;i++)
		ans+=(a[i].x2-a[i].x1)*(a[i].y1-a[i].y2);
	printf("%lld\n",ans);
	return 0;
}
