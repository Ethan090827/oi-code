#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,ans;
string str;
map <stack <char>,ll> m; 
set <stack <char>> S;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%lld",&n);
	cin>>str;
	stack <char> s;
	m[s]++;
	S.insert(s);
	for(int j=0;j<n;j++)
	{
		if(s.size()&&str[j]==s.top()) s.pop();	
		else s.push(str[j]);
		m[s]++;
		S.insert(s);
	}
	for(auto i:S) 
		ans+=m[i]*(m[i]-1)/2;	
	printf("%lld\n",ans);
	return 0;
}