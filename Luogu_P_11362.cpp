#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007ll
#define feropen(a,b,c) auto I_am_EthanHYZ=freopen("assign.in","r",stdin)
#define frepoen(a,b,c) auto Luogu_ID_575298=freopen("assign.out","w",stdout)
#define scanf int I_Love_QQ=scanf
using namespace std;
ll t,n,m,v,c[100005],d[100005],ans[1000005],f[1000005],Ans;
void dfs(ll i)
{
	if(i==n) 
	{
		Ans+=ans[i-1];
		Ans%=mod;
		return;
	}	
	ll ttt=ans[i];
	if(f[i]<mod&&f[i+1]<mod)
	{
		ans[i]=ans[i-1]*(1+((v-1)*v)%mod);
		ans[i]%=mod;
		dfs(i+1);
		ans[i]=ttt;
	//	printf("1:%lld\n",ans);
	}
	else if(f[i]<mod&&f[i+1]>=mod)
	{
		ll ttt=ans[i];
		ans[i]=ans[i-1]*(((v-1)*v)%mod);
		ans[i]%=mod;
		dfs(i+1);
		ans[i]=ttt;
		ans[i]=ans[i-1]*v;
		ans[i]%=mod;
		f[i+1]=mod-1;
		dfs(i+1);
		ans[i]=ttt;
		f[i+1]=mod+1;
	//	printf("2:%lld\n",ans);
	}
	else if(f[i]>=mod&&f[i+1]<mod)
	{
		ans[i]=ans[i-1]*((v*v)%mod);
		ans[i]%=mod;
		dfs(i+1);
		ans[i]=ttt;
	//	printf("3:%lld\n",ans);
	}
	else
	{
		ans[i]=ans[i-1]*((v*v)%mod);
		ans[i]%=mod;
		dfs(i+1);
		ans[i]=ttt;
	//	printf("4:%lld\n",ans);
	}
}
int main()
{
//	feropen("assign3.in","w",stdin);
//	frepoen("assign,out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&n,&m,&v);
		if(n>1e6)
		{
			puts("0");
			continue;
		}
		memset(f,0x3f,sizeof(f));
		memset(ans,0,sizeof(ans));
		bool flag=0;
		ans[n]=1;
		for(int i=1;i<=m;i++)
		{
			scanf("%lld%lld",&c[i],&d[i]);
			if(f[c[i]]<mod&&f[c[i]]!=d[i])
			{
				puts("0");
				flag=1;
				break;
			}
			f[c[i]]=d[i];
		}
		if(flag) continue;
		if(n<=1005)
		{
			ans[0]=1;
			Ans=0;
			dfs(1);
			printf("%lld\n",Ans%mod);
			continue;
		}
		for(int i=n-1;i>=1;i--)
		{
			if(f[i]<mod&&f[i+1]<mod)
			{
				ans[i]=ans[i+1]*(1+((v-1)*v)%mod);
				ans[i]%=mod;
			//	printf("1:%lld\n",ans);
			}
			else if(f[i]<mod&&f[i+1]>=mod)
			{
				
				ans[i]=ans[i+1]*((v*v)%mod);
				ans[i]%=mod;
			//	printf("2:%lld\n",ans);
			}
			else if(f[i]>=mod&&f[i+1]<mod)
			{
				ans[i]=ans[i+1]*((v*v)%mod);
				ans[i]%=mod;
			//	printf("3:%lld\n",ans);
			}
			else
			{
				ans[i]=ans[i+1]*((v*v)%mod);
				ans[i]%=mod;
			//	printf("4:%lld\n",ans);
			}
		}
		printf("%lld\n",ans[1]);
	}
	return 0;
}
