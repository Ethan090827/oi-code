#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[10][10],b[10],dif[10],cnt,flag,c[10],ans;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%lld",&n);
	if(n==1)
	{
		puts("81");
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=5;j++)
			scanf("%lld",&a[i][j]);
	for(b[1]=0;b[1]<=9;b[1]++)
		for(b[2]=0;b[2]<=9;b[2]++)
			for(b[3]=0;b[3]<=9;b[3]++)
				for(b[4]=0;b[4]<=9;b[4]++)
					for(b[5]=0;b[5]<=9;b[5]++)
					{
						flag=0;
						for(int i=1;i<=n;i++)
						{
							cnt=0;
							for(int j=1;j<=5;j++)
							{
								dif[j]=(a[i][j]-b[j]+10)%10;
								if(dif[j]) c[++cnt]=j;
							}
							if(cnt==0||cnt>2||(cnt==2&&(c[2]-c[1]>1||dif[c[2]]!=dif[c[1]]))) 
							{
								flag=1;
								break;
							}
						}
						if(flag) continue;
						ans++;
					}
	printf("%lld\n",ans);				
	return 0;
}
