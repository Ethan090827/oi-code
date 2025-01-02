#include <bits/stdc++.h>
#define ll long long
#define FileI(a) auto abc=freopen(a,"r",stdin)
#define FileO(a) auto Abc=freopen(a,"w",stdout)
#define scanf auto ABC=scanf
using namespace std;
ll x;
int main()
{
#ifndef ONLINE_JUDGE
	FileI(".in");
	FileO(".out");
#endif
	scanf("%lld",&x);
	if(x%2==0) printf("%lld\n",x/2);
	else printf("%lld\n",x/2+3);
	return 0;
}
