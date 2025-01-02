#include <bits/stdc++.h>
#define ll long long
#define FileI(a) auto abc=freopen(a,"r",stdin)
#define FileO(a) auto Abc=freopen(a,"w",stdout)
#define scanf auto ABC=scanf
#define N 4000
using namespace std;
ll t,a,p[4005],k,cnt,flag;
bool ip[4005];
int main()
{
#ifndef ONLINE_JUDGE
	FileI(".in");
	FileO(".out");
#endif
	ip[0]=ip[1]=1;
	for(int i=2;i<=sqrt(N);i++)
		if(!ip[i])
			for(int j=2;i*j<=N;j++)
				ip[i*j]=1;
	for(int i=1;i<=N;i++)
		if(!ip[i]) p[++k]=i;	
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&a);
		flag=0;
		for(int i=1;i<=k;i++)
		{
			if(a==1) break;
			cnt=0;
			while(a%p[i]==0)
			{
				a/=p[i];
				cnt++;
			}
			if(cnt==1)
			{
				flag=1;
				break;
			}
		}
		ll sr=sqrt(a)+0.0000001,cr=pow(a,1.0/3)+0.0000001;
		if(sr*sr!=a&&cr*cr*cr!=a&&a!=1) flag=1;
		if(flag) puts("no");
		else puts("yes");
	}
	return 0;
}
