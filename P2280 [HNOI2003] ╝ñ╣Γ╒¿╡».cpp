#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,M,x,y,v,m[5005][5005],ans,N=5001;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%d%d",&n,&M);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x,&y,&v);
		m[x+1][y+1]+=v;
	}
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			m[i][j]=m[i-1][j]+m[i][j-1]-m[i-1][j-1]+m[i][j];	
	for(int i=M;i<=N;i++)
		for(int j=M;j<=N;j++)
			ans=max(ans,m[i][j]-m[i-M][j]-m[i][j-M]+m[i-M][j-M]);
	printf("%d\n",ans);			
	return 0;
}

