#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[100005][25],l,r,Log[100005],s,ans;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i][0]);
        a[i][0]=-a[i][0];
    }
	for(int i=2;i<=100000;i++)
		Log[i]=Log[i/2]+1;
	for(int j=1;j<=Log[n];j++)	
		for(int i=1;i+(1<<(j-1))<=n;i++)
			a[i][j]=max(a[i][j-1],a[i+(1<<(j-1))][j-1]);	
	while(m--)
	{
		scanf("%lld%lld",&l,&r);
		s=Log[r-l+1];
		ans=max(a[l][s],a[r-(1<<s)+1][s]);
		printf("%lld ",-ans);
	}
    puts("");
	return 0;
}