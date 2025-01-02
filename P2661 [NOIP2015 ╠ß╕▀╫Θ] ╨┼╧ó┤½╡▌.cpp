#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll f[200005],d[200005],A,n,minn=1<<30,last,t;
ll findfa(ll x)
{
	if(f[x]==x) return x; 
    ll last=f[x];
    f[x]=findfa(f[x]);
    d[x]+=d[last];
    return f[x];
}
void check(ll a,ll b)
{
    ll x=findfa(a);
	ll y=findfa(b); 
	if(x==y) minn=min(minn,d[b]+1);
    else
	{
		f[x]=y; 
		d[a]=d[b]+1;
	} 
    return;
}
int main()
{
	freopen("P2661_2.in","r",stdin);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&A);
        check(i,A);
    }
    printf("%lld\n",minn);
    return 0;
}

