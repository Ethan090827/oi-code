#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll Map[205][205],p[205],vis[205],N,T;
bool match(ll i)
{
	for(int j=1;j<=N;j++)
		if(Map[i][j]&&!vis[j])
		{
			vis[j]=1;
			if(p[j]==0||match(p[j]))
			{
				p[j]=i;
				return true;
			}
		}	
	return false;
}
ll Hungarian()
{
	ll cnt=0;
	for(int i=1;i<=N;i++)
	{
		memset(vis,0,sizeof(vis));
		if(match(i)) cnt++;
	}
	return cnt;
}
int main()
{
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&N);
		memset(p,0,sizeof(p));
		for(int i=1;i<=N;i++)
			for(int j=1;j<=N;j++)
				scanf("%lld",&Map[i][j]);
		if(Hungarian()==N) puts("Yes");
		else puts("No");
	}
	return 0;
}
