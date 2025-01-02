#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,h,w,x,y,ans[20],a,b,k;
map <pair <ll,ll>,ll> m;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
    scanf("%lld%lld%lld",&h,&w,&n);
    ans[0]=(h-2)*(w-2);
    while(n--)
    {
        scanf("%lld%lld",&x,&y);
        for(int i=-1;i<=1;i++)
            for(int j=-1;j<=1;j++)
            {
                a=x+i;
                b=y+j;
                if(a>1&&a<h&&b>1&&b<w)
                {
                    k=++m[make_pair(a,b)];
                    ans[k]++;
                    ans[k-1]--;
                }
            }
    }
    for(int i=0;i<=9;i++)
        printf("%lld\n",ans[i]);
    return 0;
}
