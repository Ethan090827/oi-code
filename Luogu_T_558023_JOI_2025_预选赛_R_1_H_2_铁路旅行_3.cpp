#include <bits/stdc++.h>
#define ll long long
#define FileI(a) auto abc=freopen(a,"r",stdin)
#define FileO(a) auto Abc=freopen(a,"w",stdout)
#define scanf auto ABC=scanf
using namespace std;
ll p,q,a,b;
int main()
{
#ifndef ONLINE_JUDGE
	FileI(".in");
	FileO(".out");
#endif
	scanf("%lld%lld%lld%lld",&p,&q,&a,&b);
	if(q<=p) printf("%lld\n",q*a);
	else printf("%lld\n",a*p+(q-p)*b);
	return 0;
}
