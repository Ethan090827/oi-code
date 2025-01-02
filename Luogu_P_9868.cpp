#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
string s1[3005],s2[3005];
bool cmp(char a,char b)
{
	return a>b;
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
	{
		cin>>s1[i];
		sort(s1[i].begin(),s1[i].end());
		s2[i]=s1[i];
		sort(s2[i].begin(),s2[i].end(),cmp);
	}
	for(int i=1;i<=n;i++)
	{
		bool f=0;
		for(int j=1;j<=n;j++)
		{
			if(j==i) continue;
			if(s2[j]<=s1[i])
			{
				printf("0");
				f=1;
				break;
			}
		}
		if(!f) printf("1");
	}
	puts("");
    return 0;
}
