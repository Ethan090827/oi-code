#include <bits/stdc++.h>
#define ll long long
#define np string::npos
using namespace std;
ll n,k;
string s,t;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("espace2.in","r",stdin);
	freopen("espace.out","w",stdout);
#endif
	scanf("%lld",&n);
	cin>>s;
	while(1)
	{
		auto p1=s.find("ABC"),p2=s.find("BCA"),p3=s.find("CAB");
		if(p1==np&&p2==np&&p3==np) break;
		if(p1!=np)
		{
			string S=s;
			s=S.substr(0,p1)+S.substr(p1+3,n-p1-3);
		}
		if(p2!=np)
		{
			string S=s;
			s=S.substr(0,p2)+S.substr(p2+3,n-p2-3);
		}
		if(p3!=np)
		{
			string S=s;
			s=S.substr(0,p3)+S.substr(p3+3,n-p3-3);
		}
	}
	scanf("%lld",&k);
	while(k--)
	{
		cin>>t;
		while(1)
		{
			auto p1=t.find("ABC"),p2=t.find("BCA"),p3=t.find("CAB");
			if(p1==np&&p2==np&&p3==np) break;
			if(p1!=np)
			{
				string S=t;
				t=S.substr(0,p1)+S.substr(p1+3,n-p1-3);
			}
			if(p2!=np)
			{
				string S=t;
				t=S.substr(0,p2)+S.substr(p2+3,n-p2-3);
			}
			if(p3!=np)
			{
				string S=t;
				t=S.substr(0,p3)+S.substr(p3+3,n-p3-3);
			}
		}
		if(s==t) puts("yes");
		else puts("no");
	}
	return 0;
}