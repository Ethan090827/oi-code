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
	cin>>n>>s;
	for(int i=1;i<n;i++)
	{
		bool flag=0;
		if(n%i!=0) continue;
		for(int j=i;j<=n;j+=i)
		{
		//	cout<<s.substr(j-i,i)<<endl;
			if(s.substr(j-i,i)!=s.substr(0,i))
			{
				flag=1;
				break;
			}
		}
		if(!flag)
		{
			puts("Yes");
			return 0;
		}
	}
	puts("No");
	return 0;
}
