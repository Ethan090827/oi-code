#include <bits/stdc++.h>
#define ll long long
using namespace std;
char buf[1<<20],*p1,*p2;
#define getchar() ((p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2))?0:*p1++)
ll read()
{
	char ch=getchar();
	ll x=0,f=1;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
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
signed main() {
	int x = read();  //读入一个整数 x
	return 0;
}