#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll k,l,j,flag;
string s;
struct bignum
{
	ll x[205];
	bignum()
	{
		memset(x,0,sizeof(x));
	}
}n,t,mul,ans;
bignum operator * (bignum a,bignum b)
{
	bignum ans;
	for(int i=0;i<k;i++)
		for(int j=0;j<k;j++)
			ans.x[i+j]+=a.x[i]*b.x[j];
	for(int i=0;i<k;i++)
	{
		ans.x[i+1]+=ans.x[i]/10;
		ans.x[i]%=10;
	}	
	for(int i=k;i<205;i++)
		ans.x[i]=0;
	return ans;
}
bignum operator * (bignum a,ll b)
{
	for(int i=0;i<=200;i++)
		a.x[i]*=b;
	for(int i=0;i<=200;i++)
	{
		a.x[i+1]+=a.x[i]/10;
		a.x[i]%=10;
	}	
	return a;
}
int main()
{
	cin>>s>>k;
	ans.x[0]=1;
	l=s.length();
	for(int i=0;i<k;i++)
		n.x[i]=s[l-i-1]-'0';
	mul=n;
	for(int i=0;i<k;i++)
	{
		t=n;
		flag=1;
		for(j=1;j<=10;j++)
		{
			t=t*mul;
			if(t.x[i]==n.x[i])
			{
				ans=ans*j;
				flag=0;
				break;
			}
		}
		if(flag)
		{
			puts("-1");
			return 0;
		}
		t=mul;
		for(int k=1;k<j;k++)
			mul=mul*t;
	}
	l=200;
	while(ans.x[l]==0&&l>=1) l--;
	for(;l;l--) putchar(ans.x[l]+'0');
}
