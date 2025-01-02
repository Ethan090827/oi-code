#include <bits/stdc++.h>
#define ll __int128
#define pll pair <ll,ll> 
#define F first
#define S second
using namespace std;
ll n,c,u,m,from,to,w,cnt,top,flag,d,cntt;
vector <ll> e[100005];
struct point
{
	ll deg,deg2,isend;
	pll c;
}a[100005]; 
void build(ll from,ll to)
{
	e[from].push_back(to);
	a[to].deg++;
	a[from].deg2++;
}
queue <ll> q;
ll read()
{
	ll x=0;
	char ch;
	while(1)
	{
		ch=getchar();
		if(ch>='0'&&ch<='9')
			x=x*10+ch-'0';
		else break;	
	}
	return x;
}
void write(ll x)
{
	string s;
	while(x)
	{
		s+=x%10+'0';
		x/=10;
	}
	reverse(s.begin(),s.end());
	cout<<s;
}
void print(pll x)
{
	write(x.F);
	putchar(' ');
	write(x.S);
	puts("");
}
ll gcd(ll a,ll b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
pll add(pll a,pll b)
{
	ll low,up;
	low=a.S*b.S;
	up=a.F*b.S+b.F*a.S;
	ll Gcd=gcd(low,up);
	low/=Gcd;
	up/=Gcd;
	return make_pair(up,low);
}
pll div(pll a,ll b)
{
	ll low,up;
	up=a.F;
	low=a.S*b;
	if(up==0) return make_pair(0,1);
	ll Gcd=gcd(low,up);
	low/=Gcd;
	up/=Gcd;
	return make_pair(up,low);
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		a[i].c=make_pair(0,1);
		d=read();
		if(d) a[i].isend=1;
		while(d--)
		{
			to=read();
			build(i,to);
		} 
	} 
	for(int i=1;i<=m;i++) 
		a[i].c=make_pair(1,1);
	for(int i=1;i<=n;i++)
		if(a[i].deg==0) q.push(i);
	while(!q.empty())
	{
		top=q.front();
		q.pop();
		for(unsigned int i=0;i<e[top].size();i++)
		{
			to=e[top][i];
			a[to].c=add(div(a[top].c,a[top].deg2),a[to].c);
			a[to].deg--;
			if(a[to].deg==0) q.push(to);
		}
	}	
	for(int i=1;i<=n;i++)
		if(!a[i].isend) print(a[i].c);	
	return 0;
}
