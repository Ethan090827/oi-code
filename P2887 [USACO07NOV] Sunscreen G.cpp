#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct cow
{
	ll sl,su;
}a[2505];
struct lotion
{
	ll s,c;
}b[2505];
bool cmp1(cow a,cow b)
{
	return a.su<b.su;
}
bool cmp2(lotion a,lotion b)
{
	return a.s<b.s;
}
ll c,l,ans; 
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%lld%lld",&c,&l);
	for(int i=1;i<=c;i++)
		scanf("%lld%lld",&a[i].sl,&a[i].su);
	sort(a+1,a+c+1,cmp1);	
	for(int i=1;i<=l;i++)
		scanf("%lld%lld",&b[i].s,&b[i].c);
	sort(b+1,b+l+1,cmp2);
	for(int i=1;i<=c;i++)
		for(int j=1;j<=l;j++)
			if(b[j].c>0&&b[j].s>=a[i].sl&&b[j].s<=a[i].su)
			{
				ans++;
				b[j].c--;
				break;
			}
	printf("%lld\n",ans);		
	return 0;
}

