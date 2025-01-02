#include <bits/stdc++.h>
using namespace std;
int a[500001],n,t[500001];
long long ans;
void Msort(int l,int r)
{
	if(l==r) return;
	int i,j,mid,k;
	mid=(l+r)/2;
	Msort(l,mid);
	Msort(mid+1,r);
	i=l;
	j=mid+1;
	k=l;
	while(i<=mid&&j<=r)
	{
		if(a[i]<=a[j]) t[k++]=a[i++];
		else
		{
			t[k++]=a[j++];
			ans+=mid-i+1;
		}
	}
	if(i>mid)
		while(j<=r)
			t[k++]=a[j++];
	if(j>r)
		while(i<=mid)
			t[k++]=a[i++];
	for(int x=l;x<=r;x++)
		a[x]=t[x];
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	while(1)
	{
		ans=0;
		memset(a,sizeof(a),0);
		memset(t,sizeof(t),0);
		scanf("%d",&n);
		if(n==0) return 0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		Msort(1,n);
		printf("%lld\n",ans);
	}
	
	return 0;
}

