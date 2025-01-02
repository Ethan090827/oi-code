#include <bits/stdc++.h>
#define ll long long
#define mp(a,b) make_pair(a,b)
#define fi first
#define se second
using namespace std;
vector <pair <ll,ll>> mac[100005];
ll n,k,h,m,s,e,f[1445],ans[1445],size,maxn;
string str;
map <string,int> M;
int main()
{
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		cin>>str;
		if(!M[str]) M[str]=++size;
		scanf("%lld:%lld",&h,&m);
		s=h*60+m;
		e=min(1440ll,s+k-1);
		mac[M[str]].push_back(mp(s,e));
	}
	for(int i=1;i<=size;i++)
	{
		memset(f,0,sizeof(f));
		for(auto j:mac[i])
			for(int t=j.fi;t<=j.se;t++)
				f[t]=1;
		for(int t=0;t<=1440;t++)
			if(f[t]) ans[t]++;		
	}
	for(int i=0;i<=1440;i++)
		maxn=max(maxn,ans[i]);
	printf("%lld\n",maxn);	
	return 0;
}
