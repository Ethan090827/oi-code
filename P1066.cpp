#include <bits/stdc++.h>
#define ll long long
using namespace std;
string Name[25];
bool lie[25];
map <string,ll> mp;
struct Sen
{
	string name,sen;
	ll id;
}s[105];
ll n,m,p,ans_cnt,ans,f1,f2,f3,f4,f5;
string Day[]={"","Today is Monday.",
				"Today is Tuesday.",
				"Today is Wednesday.",
				"Today is Thursday.",
				"Today is Friday.",
				"Today is Saturday.",
				"Today is Sunday."};
bool check(int id,int day)
{
	ll cnt_lie=0,cnt_not_lie=0;
	memset(lie,0,sizeof(lie));
	for(int i=1;i<=p;i++)
	{
		f1=f2=f3=f4=f5=0;
		//WeekDay incorrect
		for(int d=1;d<=7;d++)
			if(s[i].sen==Day[d]&&d!=day)
			{
				lie[i]=1;
				f1=1;
				break;
			}
		//"XXX is guilty." incorrect	
		for(int ID=1;ID<=m;ID++)
			if(s[i].sen.length()>11&&s[i].sen.substr(s[i].sen.length()-11)==Name[ID]&&ID!=id)
			{
				lie[i]=1;
				f2=1;
				break;
			}	
		//"XXX is not guilty." incorrect	
		for(int ID=1;ID<=m;ID++)
			if(s[i].sen.length()>15&&s[i].sen.substr(s[i].sen.length()-15)==Name[ID]&&ID==id)
			{
				lie[i]=1;
				f3=1;
				break;
			}
		if(s[i].sen=="I am guilty."&&id!=i)
		{
			lie[i]=1;
			f4=1;
			break;
		}
		if(s[i].sen=="I am not guilty."&&id==i)
		{
			lie[i]=1;
			f5=1;
			break;
		}	
		if(lie[i]) cnt_lie++;
		if(!f1||!f2||!f3||!f4||!f5) cnt_not_lie++;
	}
	if(cnt_lie>n||cnt_not_lie>m-n) return 0;
	return 1;
}				
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%lld%lld%lld",&m,&n,&p);
	for(int i=1;i<=m;i++) 
	{
		cin>>Name[i];
		mp[Name[i]]=i;
	}
	getchar();	
	for(int i=1;i<=p;i++)
	{
		cin>>s[i].name;
		s[i].name=s[i].name.substr(s[i].name.length()-2);
		s[i].id=mp[s[i].name];
		getchar();
		getline(cin,s[i].sen);
	}
	for(int id=1;id<=m;id++)
		for(int day=1;day<=7;day++)
		{
			if(check(id,day))
			{
				cout<<ans<<" "<<Name[id]<<" "<<day<<" "<<ans_cnt<<endl;
				if(ans==0) ans=id;
				else if(id!=ans)
				{
					puts("Cannot Determine");
					return 0;
					ans_cnt++;
				}
				
			}
		}
	if(!ans) puts("Impossible");
	else if(ans_cnt>1) puts("Cannot Determine");
	else cout<<Name[ans]<<endl;
	return 0;
}
