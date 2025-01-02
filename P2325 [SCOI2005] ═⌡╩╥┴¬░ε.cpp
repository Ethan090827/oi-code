#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[100005][40],ch,maxn;
vector <ll> s;
map <vector <ll>,ll> m;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=k;i++)
		s.push_back(0);
	m[s]=0;	
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&ch);
		s.clear();
		for(int j=1;j<=k;j++)
		{
			a[i][j]=a[i-1][j]+((1<<(j-1)&ch)>0);
			s.push_back(a[i][j]-a[i][1]);
		}
		if(m.count(s)) maxn=max(maxn,i-m[s]);
		else m[s]=i;
	}
	printf("%lld\n",maxn);
	return 0;
}
