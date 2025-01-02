#include<bits/stdc++.h>
#define ll long long
using namespace std;
string temp[3]={"ABC","BCA","CAB"};
ll n,k;
string s,t,str1,str2;
void change(string s, string &str)
{
	str.clear();
	for(int i=0;i<n;i++)
	{
		str+=s[i];
		for(int j=0;j<3;j++)
			if(str.size()>=3&&str.substr(str.size()-3,str.size())==temp[j])
				for(int k=1;k<=3;k++)
					str.pop_back();
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("espace.in","r",stdin);
	freopen("espace.out","w",stdout);
#endif
	scanf("%lld",&n);
	cin>>s;
	change(s,str1);
	scanf("%lld",&k);
	while(k--)
	{
		cin>>t;
		change(t,str2);
		if(str1==str2) puts("yes");
		else puts("no");
	}
	return 0;
}