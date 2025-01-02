//Bellman-Ford

#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,s,u,v,w,dis[10005];
bool flag;
struct edge
{
    ll to,w;
};
vector <edge> e[10005];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&s);
    for(int i=1;i<=m;i++)
    {
        scanf("%lld%lld%lld",&u,&v,&w);
        e[u].push_back((edge){v,w});
    }
    memset(dis,0x3f,sizeof(dis));
    dis[s]=0;
    for(int i=1;i<n;i++)
    {
        flag=0;
        for(int j=1;j<=n;j++)
            for(unsigned int k=0;k<e[j].size();k++)
            {
                u=j;
                v=e[j][k].to;
                w=e[j][k].w;
                if(dis[u]>(1<<30)) continue;
                if(dis[v]>dis[u]+w)
                {
                    dis[v]=dis[u]+w;
                    flag=1;
                }
            }
        if(!flag) break;
    }
    for(int i=1;i<=n;i++)
    {
        if(dis[i]>(1<<30)) printf("2147483647 ");
        else printf("%lld ",dis[i]);
    }
    puts("");
    return 0;
}
