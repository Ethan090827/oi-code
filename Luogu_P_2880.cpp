#include <bits/stdc++.h>
#define ll long long
#define MAXN 50005
using namespace std;
ll Log2[MAXN],Min[MAXN][20],Max[MAXN][20],n,m,x,l,r,s,ma,mi;
int main()
{
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&x);
        Min[i][0]=Max[i][0]=x;
    }
    for(int i=2;i<=n;i++)
        Log2[i]=Log2[i/2]+1;
    for(int i=1;i<=16;i++)
        for(int j=1;j+(1<<i)-1<=n;j++)
        {
            Min[j][i]=min(Min[j][i-1],Min[j+(1<<(i-1))][i-1]);
            Max[j][i]=max(Max[j][i-1],Max[j+(1<<(i-1))][i-1]);
        }
    while(m--)
    {
        scanf("%lld%lld",&l,&r);
        s=Log2[r-l+1];
        ma=max(Max[l][s],Max[r-(1<<s)+1][s]);
        mi=min(Min[l][s],Min[r-(1<<s)+1][s]);
        printf("%lld\n",ma-mi);
    }
    return 0;
}