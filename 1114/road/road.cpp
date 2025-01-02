#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define N 5005
#define read(a) a=Read()
using namespace std;
char buf[1<<20],*p1,*p2;
#define getchar() ((p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2))?0:*p1++)
ll Read()
{
	char ch=getchar();
	ll x=0,f=1;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')	f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
#undef getchar
bool vis2[N];
ll n,m,match[N],pre[N],favor[N][N],val1[N],val2[N],slack[N],T,a[N],b[N];
void bfs(ll p)
{
	ll x,y=0,yy=0;
	memset(pre,0,sizeof(pre));
	memset(slack,INF,sizeof(slack));
	match[0]=p;
	do
	{
		ll d=INF;
		x=match[y];
		vis2[y]=true;
		for(int i=1;i<=n;i++)
		{
			if(vis2[i]) continue;
			if(slack[i]>val1[x]+val2[i]-favor[x][i])
			{
				slack[i]=val1[x]+val2[i]-favor[x][i];
				pre[i]=y;
			}
			if(slack[i]<d)
			{
				d=slack[i];
				yy=i;
			}
		}
		for(int i=0;i<=n;i++)
		{
			if(vis2[i]) val1[match[i]]-=d,val2[i]+=d;
			else slack[i]-=d;
		}
		y=yy;
	}while(match[y]);
	while(y)
	{
		match[y]=match[pre[y]];
		y=pre[y];
	}
}
ll KM()
{
	memset(match,0,sizeof(match));
	memset(val1,0,sizeof(val1));
	memset(val2,0,sizeof(val2));
	for(int i=1;i<=n;i++)
	{
		memset(vis2,false,sizeof(vis2));
		bfs(i);
	}
	ll res=0;
	for(int i=1;i<=n;i++)
		res+=favor[match[i]][i];
	return res;
}
int main()
{
	int u,v;
	ll w;
	read(T);
	while(T--)
	{
		read(n);
		read(m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				favor[i][j]=-INF;
		for(int i=1;i<=m;i++)
			read(a[i]);
		for(int i=1;i<=m;i++)
			read(b[i]);			
		for(int i=1;i<=m;i++)
			favor[u][v]=max(favor[u][v],-min(abs(a[i]-b[i]),m-abs(a[i]-b[i])));
		printf("%lld\n",-KM());
	}
	return 0;
}