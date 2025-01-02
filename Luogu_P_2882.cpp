#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,minn=1<<30,ans,cnt;
char ch;
bool a[10005],b[10005],f,flag;
int main()
{
#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif		
	scanf("%lld",&n);
	char ch;
	for(int i=1;i<=n;i++)
	{
		scanf("\n%c",&ch);
		if(ch=='F') a[i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		memset(b,0,sizeof(b));
		f=cnt=flag=0;
		for(int j=1;j<=n;j++)
		{
			f^=b[j];
			if(!(a[j]^f))
			{
				if(j+i-1>n)
				{  
					flag=1;
					break;
				}
				f^=1;
				b[j+i]^=1;
				cnt++;
			}
		}
		if(!flag&&cnt<minn)
		{
			minn=cnt;
			ans=i;
		}
	}
	printf("%lld %lld\n",ans,minn);
}