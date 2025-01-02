#include <bits/stdc++.h>
#define ll long long
using namespace std;
constexpr ll M = 998244353;
constexpr ll B = 26;
unsigned ll res[1000005],s1,s2,l,ans;
unsigned ll get_hash(ll l,ll r)
{
	return ((res[r]-res[l-1]*(ll)pow(B,r-l+1))%M);
}
string s;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	cin>>s;
	l=s.length();
	for(int i=0;i<l;i++)
	{
		res[i]=((ll)res[i-1]*B%M+s[i]);
		printf("%llu\n",res[i]);
	}
			
	for(unsigned int i=1;i<l;i++)
	{
		s1=get_hash(i,l-1);
		s2=get_hash(0,l-i-1);
		cout<<s1<<" "<<s2<<endl;
		if(s1==s2)
		{
			ans=i;
			break;
		}
	}
	if(!ans) cout<<s+s<<endl;
	else cout<<s.substr(0,ans)+s<<endl;
	return 0;
}