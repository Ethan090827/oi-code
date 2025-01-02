#include <bits/stdc++.h>
#define ll long long
#define double long double
using namespace std;
ll q,a,n,p=998244353,ans;
void mod(ll a,ll b)
{
	if(b==0) return;
	if(b%2==1) ans=ans*a%p;
	mod(a*a%p,b/2);
}
double Mod(double a)
{
	if(a<p) return a;
	ll x=(ll)floor(a);
	return x%p+a-x;
}
double Pow(double a,ll n)
{
	a=Mod(a);
	double res=1.0;
	while(n--) 
	{
		res*=a;
		res=Mod(res);
	}
	return res;
}
double Sqrt(double a)
{
	return Mod(sqrt(Mod(a)));
}
int main()
{
//	freopen("blacksouls.in","r",stdin);
//	freopen("blacksouls.out","w",stdout);
//	printf("%lf %lf\n",sqrt(1234567998746),sqrt(1234567998746%998244353));
	scanf("%lld",&q);
	while(q--)
	{
		scanf("%lld%lld",&a,&n);
		if(sqrt(a)==floor(sqrt(a)))
		{
			ans=1;
			mod(2*(ll)floor(sqrt(a)),n);
			printf("%lld\n",ans);
			continue;
		}
		printf("%lld\n",(ll)floor(Pow((ceil(Sqrt(a))+Sqrt(a)),n))%p);
		printf("%lld\n",(ll)floor(Pow((ceil(sqrt(a))+sqrt(a)),n))%p);
	}
	return 0;
}

