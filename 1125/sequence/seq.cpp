#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s,t;
ll pos,flag,End,len=1,ans[500005],k,LenS,LenT;
int main()
{
//	freopen("seq.in","r",stdin);
//	freopen("seq.out","w",stdout);
	cin>>s>>t;
	t+=' ';
	LenS=s.length();
	LenT=t.length();
	for(int i=1;i<LenT;i++)
	{
		if(t[i]==t[i-1])
		{
			len++;
			continue;
		}
		for(;pos<LenS;pos++)
		{
			if(s[pos]==t[i-1])
			{
				ans[++k]=pos+1;
				len--;
			}
			if(!len)
			{
				pos++;
				break;
			}	
		}
		len=1;	
	}
	if(k!=LenT-1) puts("NO");
	else
	{
		puts("YES");
		for(int i=1;i<=k;i++)
			printf("%lld ",ans[i]);
		puts("");
	}
	return 0;
}
