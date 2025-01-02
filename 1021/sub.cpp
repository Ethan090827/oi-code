#include <bits/stdc++.h>
#define ll long long
#define mod 998244353
#define bp(i) __builtin_popcount(i)
using namespace std;
ll n,q,l,r,y[1000005],c[1000005][4];
map <vector <ll>,ll> mem;
ll qpow(ll p,ll q=mod-2)
{
	ll ans=1;
	while(q!=0)
	{
		if((q&1)!=0) ans=ans*p%mod;
		p=p*p%mod;
		q>>=1;
	}
    return ans;
}
bool chk(vector <ll> v)
{
	ll n=(ll)v.size();
	for(int i=1;i<(1<<n);i++)
	{
		ll c[3]={0,0,0},minn=n,maxn=0;
		for(ll j=0;j<n;j++)
			if((i>>j)&1)
			{
				c[v[j]-1]++;
				minn=min(minn,j);
				maxn=max(maxn,j);
			}
		if(maxn-minn+1!=bp(i)&&max({c[0],c[1],c[2]})*2<bp(i))
			return 0;
  	}
  	return 1;
}
ll bf(vector <ll> V)
{
	if(mem.find(V)!=mem.end()) return mem[V];
	ll c=0,t=1;
	for(unsigned int i=0;i<V.size();i++)
		if(V[i]==0)
		{
			c++;
			t*=3;
		}
	ll ans=0;
	for(int i=0;i<t;i++)
	{
		ll I=i;
		vector <ll> v;
		for(unsigned int j=0;j<V.size();j++)
		{
			if(V[j]!=0) v.push_back(V[j]);
			else
			{
				v.push_back(I%3+1);
				I/=3;
			}
		}
		ans+=chk(v);
  	}
	return mem[V]=ans;
}
int main()
{
//	freopen("sub.in", "r", stdin);
//	freopen("sub.out", "w", stdout);
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&y[i]);
		for(int j=0;j<=3;j++)
			c[i][j]=c[i-1][j]+(y[i]==j);
	}
	while(q--)
	{
		scanf("%lld%lld",&l,&r);
		if(r-l<4)
		{
			vector <ll> v;
			for(int i=l;i<=r;i++)
				v.push_back(y[i]);
			printf("%lld\n",bf(v));
			continue;
		}
		ll c0=c[r][0]-c[l-1][0],cc=0;
		for(int i=1;i<=3;i++)
			if(c[r][i]==c[l-1][i]) cc++;
		if(cc==0) puts("0");
		else if(cc==1) printf("%lld\n",qpow(2,c0));
		else if(cc==2) printf("%lld\n",2LL*qpow(2,c0+1)-1);
		else printf("%lld\n",3LL*qpow(2,c0)%mod-3);
	}
	return 0;
}
