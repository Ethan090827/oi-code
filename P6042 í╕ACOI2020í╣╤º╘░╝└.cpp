#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+5,mod=10086001;
ll jc[N],jcs[N],jc4as[N],jc4a2s[N],t,q,u;
int main()
{
	jc[0]=jcs[0]=1;
	for(int i=1;i<N/2;i++)
	{
		jc[i]=(jc[i-1]*i)%mod;
		jcs[i]=(jcs[i-1]+jc[i])%mod;
		jc4as[i]=(jc4as[i-1]+jc[i]*4*i)%mod;
		jc4a2s[i]=(jc4a2s[i-1]+jc[i]*4*i%mod*i)%mod;
	}
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&q);
		u=(q-1)/2;
		printf("%lld\n",(((jcs[u]*q%mod*q-jc4as[u]*q+jc4a2s[u])%mod+mod)%mod));
	}
	return 0; 
}
