#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll Inv[3000005],n,p;
ll mod(ll a,ll p)
{
    return (a%p+p)%p;
}
ll inv(ll a,ll p)
{
    if(Inv[a]) return Inv[a];
    return Inv[a]=mod(-p/a*inv(p%a,p),p);
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
    Inv[1]=1;
    scanf("%lld%lld",&n,&p);
    for(int i=1;i<=n;i++)
        printf("%lld\n",inv(i,p));
    return 0;
}
