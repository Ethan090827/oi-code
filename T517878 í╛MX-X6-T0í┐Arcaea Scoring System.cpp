#include <bits/stdc++.h>
#define ll long long
using namespace std;
int p1,p0,f,l,ans,n;
double ans1; 
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%d%d%d%d",&p1,&p0,&f,&l);
	n=p1+p0+f+l;
	ans1=p1*(1e7/n+1)+p0*1e7/n+f*1e7/n*0.5;
//	printf("%lf\n",ans1);
	ans=ceil(ans1);
	if(ans>=9.9e6) puts("EX+");
	else if(ans>=9.8e6) puts("EX");
	else if(ans>=9.5e6) puts("AA");
	else if(ans>=9.2e6) puts("A");
	else if(ans>=8.9e6) puts("B");
	else if(ans>=8.6e6) puts("C");
	else puts("D");
	return 0;
}

