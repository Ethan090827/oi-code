#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll pmt[1000005];
string s,p;
void get_pmt()
{
	ll j=0;
	for(unsigned int i=1;i<p.length();i++)
	{
		while(j&&p[i]!=p[j])
			j=pmt[j-1];
		if(p[i]==p[j]) j++;
		pmt[i]=j;
	}
}
void kmp()
{
	unsigned ll j=0;
	for(unsigned int i=0;i<s.length();i++)
	{
		while(j&&s[i]!=p[j])
			j=pmt[j-1];
		if(s[i]==p[j]) j++;
		if(j==p.length())
		{
			printf("%lld\n",i-j+2);
			j=pmt[j-1];
		}
	}
}
int main()
{
	cin>>s>>p;
	get_pmt();
	kmp();
	for(unsigned int i=0;i<p.length();i++)
		printf("%lld ",pmt[i]);
	puts("");	
	return 0;
}