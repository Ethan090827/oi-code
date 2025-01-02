#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%lld",&n);
	for(int i=n;i>=0;i--)
	{
		scanf("%lld",&a);
		if(n==0) printf("%lld",a);
		else if(a==0) continue;
		else if(i==n)
		{
			if(i==1)
			{
				if(a==1) printf("x");
				else if(a==-1) printf("-x");
				else printf("%lldx",a);
				continue;
			} 
			if(a==1) printf("x^%lld",n);
			else if(a==-1) printf("-x^%lld",n);
			else printf("%lldx^%lld",a,n);
		}
		else if(i==0) printf("%+lld",a);
		else
		{
			if(i==1)
			{
				if(a==1) printf("x");
				else if(a==-1) printf("-x");
				else printf("%+lldx",a);
				continue;
			} 
			if(a==1) printf("+x^%d",i);
			else if(a==-1) printf("-x^%d",i);
			else if(a==0) continue;
			else if(a>0) printf("+%lldx^%d",a,i);
			else printf("%lldx^%d",a,i);
		} 
	} 
	return 0;
}
