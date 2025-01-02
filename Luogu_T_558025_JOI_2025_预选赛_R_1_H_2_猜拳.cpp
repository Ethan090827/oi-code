#include <bits/stdc++.h>
#define ll long long
#define FileI(a) auto abc=freopen(a,"r",stdin)
#define FileO(a) auto Abc=freopen(a,"w",stdout)
#define scanf auto ABC=scanf
using namespace std;
ll n,ans1,ans2;
string s,t;
int main()
{
#ifndef ONLINE_JUDGE
	FileI(".in");
	FileO(".out");
#endif
	scanf("%lld",&n);
	cin>>s>>t;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='R'&&t[i]=='R');
		if(s[i]=='R'&&t[i]=='P') ans2++;
		if(s[i]=='S'&&t[i]=='R') ans2++;
		if(s[i]=='S'&&t[i]=='P') ans1++;
	}
	printf("%lld %lld\n",ans1,ans2);
	return 0;
}
