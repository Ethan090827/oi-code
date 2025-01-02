#include <bits/stdc++.h>
#define ll long long
#define FileI(a) auto abcdefg=freopen(a,"r",stdin)
#define FileO(a) auto Abcdefg=freopen(a,"w",stdout)
#define scanf int ABCDEFG=scanf
using namespace std;
/* Large integers.
 * Only integers larger than -1 accepted
 * Containing large_number plus large_number,
 *            large_number multiple long long,
 *            common comparison (<, >, <=, >=, ==, !=),
 *            min and max,
 *            exchange between long long and large_integer.
 * Not sure of being correct all the time.
 */
struct large_number
{
	string num;
	// Turns long long into large_number.
	static large_number LTH (const ll &x)
	{
		string s;
		ll X=x;
		if(X<0) return (large_number){"ERROR: Can't be negative!"};
		if(X==0) s="0";
		while(X)
		{
			s+=X%10+'0';
			X/=10;
		}
		reverse(s.begin(),s.end());
		return (large_number){s};
	}
	/* Turns large_number into long long.
	 * If it is larger than LONG_LONG_MAX, it'll return LONG_LONG_MAX
	 */
	ll HTL()
	{
		if(num>LTH(LONG_LONG_MAX).num) return LONG_LONG_MAX;
		string s=num;
		ll ans=0;
		for(unsigned int i=0;i<s.length();i++)
			ans=ans*10+s[i]-'0';
		return ans;
	}
	//large_number plus large_number
	large_number operator + (const large_number &x) const
	{
		string s1=num,s2=x.num;
		ll l1=s1.length(),l2=s2.length();
		if(l1<l2) 
		{
			swap(s1,s2);
			swap(l1,l2);
		}	
		reverse(s1.begin(),s1.end());
		reverse(s2.begin(),s2.end());
		ll t=0;
		for(int i=0;i<l2;i++)
		{
			ll n1=s1[i]-'0',n2=s2[i]-'0';
			ll T=t;
			t=(n1+n2)/10;
			n1=(n1+n2)%10+T;
			s1[i]=n1+'0';
		}
		if(l1==l2&&t) s1+=t+'0';
		else s1[l2]+=t;
		reverse(s1.begin(),s1.end());
		return (large_number){s1};
	}
	void operator += (const large_number &x)
	{
		num=((large_number){num}+x).num;
	}
	//large_number multiple long long
	large_number operator * (const ll &x) const
	{
		string s1=num;
		large_number ans={""};
		ll l1=s1.length();
		reverse(s1.begin(),s1.end());
		for(int i=0;i<l1;i++)
		{
			string s=LTH((s1[i]-'0')*x).num;
			for(int j=1;j<=i;j++) s+='0';
			ans+=(large_number){s};
			cout<<ans.num<<endl;
		}
		return (large_number){ans};
	}
	large_number operator *= (const ll &x)
	{
		num=((large_number){num}*x).num;
	}
	bool operator < (const large_number &x) const
	{
		return num<x.num;
	}
	bool operator <= (const large_number &x) const
	{
		return num<=x.num;
	}
	bool operator > (const large_number &x) const
	{
		return num>x.num;
	}
	bool operator >= (const large_number &x) const
	{
		return num>=x.num;
	}
	bool operator == (const large_number &x) const
	{
		return num==x.num;
	}
	bool operator != (const large_number &x) const
	{
		return num!=x.num;
	}
};
#define lth(a) large_number::LTH(a)
#define htl(a) a.HTL()
large_number min(large_number a,large_number b)
{
	return a<b?a:b;
}
large_number max(large_number a,large_number b)
{
	return a>b?a:b;
}
int main()
{
#ifndef ONLINE_JUDGE
	FileI(".in");
	FileO(".out");
#endif
	cout<<(large_number){"-1000000000000"}.HTL()<<endl;
	return 0;
}
