#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,Q,ans[5005],k,ans1[5005],k1;
bool ret; 
bool check(ll a,ll b)
{
	printf("%lld %lld\n",a,b);
	fflush(stdout);
	scanf("%d",&ret);
	return ret;
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		k=k1=0;
		queue <ll> q;
		scanf("%lld%lld",&n,&Q);
		ans[++k]=0;
		for(int i=1;i<n;i++)
		{
			if(q.empty())
			{
				if(check(ans[k],i)) ans[++k]=i;
				else q.push(i);
			}
			else
			{
				if(check(q.front(),i))
				{
					ans[++k]=i;
					ans[++k]=q.front();
					q.pop();
				}
				else q.push(i);
			}	
		}
		ans1[++k1]=0;
		if(!q.empty())
		{
			for(int i=1;i<=k;i++)
			{
				ans1[++k1]=ans[i];
				if(q.empty()) continue;
				if(i==k&&check(ans[i],q.front())) ans1[++k1]=q.front();
				if(check(ans[i],q.front())&&check(ans[i]+1,q.front())&&i<k)
				{
					ans1[++k1]=q.front();
					q.pop();
				}
			}
			if(!q.empty())
			{
				printf("-1\n");
				fflush(stdout);
			}
			else
			{
				for(int i=1;i<k1;i++)
					printf("%lld ",ans1[i]);
				printf("%lld\n",ans1[k1]);
				fflush(stdout);
			}
		}
		else
		{
			for(int i=1;i<k;i++)
				printf("%lld ",ans[i]);
			printf("%lld\n",ans[k]);
			fflush(stdout);
		}
	}
	return 0;
}

