#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
ll n,ans,res,p[2000005];
string str;
map <ll,ll> m;
stack <char> s;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
    p[0]=1;
    for(int i=1;i<=2000000;i++)
        p[i]=p[i-1]*529ull;
	scanf("%lld",&n);
	cin>>str;
    str=" "+str;
	m[0]++;
	for(int i=1;i<=n;i++)
	{
		if(!s.empty()&&s.top()==str[i])
		{
			res-=s.top()*p[s.size()];
			s.pop();
		}
		else
		{
			s.push(str[i]);
			res+=s.top()*p[s.size()];
		}
        ans+=m[res];
        m[res]++;
	}
	printf("%lld\n",ans);
	return 0;
}