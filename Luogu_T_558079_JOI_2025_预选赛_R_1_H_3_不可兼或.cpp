#include <bits/stdc++.h>
#define ll long long
#define FileI(a) auto abc=freopen(a,"r",stdin)
#define FileO(a) auto Abc=freopen(a,"w",stdout)
#define scanf auto ABC=scanf
using namespace std;
ll n,a,b,ans;
int main()
{
#ifndef ONLINE_JUDGE
	FileI(".in");
	FileO(".out");
#endif
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++)
	{
		if(i%a==0&&i%b!=0||i%a!=0&&i%b==0) ans++;
	}
	cout<<ans<<endl;
	return 0;
}
