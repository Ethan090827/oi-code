#include <bits/stdc++.h>
#define ll long long
#define FileI(a) auto abc=freopen(a,"r",stdin)
#define FileO(a) auto Abc=freopen(a,"w",stdout)
#define scanf auto ABC=scanf
using namespace std;
ll n;
string s;
int main()
{
#ifndef ONLINE_JUDGE
	FileI(".in");
	FileO(".out");
#endif
	scanf("%lld",&n);
	cin>>s;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='J') s[i]='O';
		else if(s[i]=='O') s[i]='I';
		else s[i]='J';
	}
	cout<<s<<endl;
	return 0;
}
