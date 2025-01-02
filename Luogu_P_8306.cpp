#include <bits/stdc++.h>
#define ll long long
#define scanf int ABCDEFG=scanf
using namespace std;
struct edge
{
	ll to;
	char c;
};
ll t,n,q,pos,flag,cnt,ans[3000005],f;
vector <edge> e[3000005];
string s;
void dfs(ll id)
{
	for(edge E:e[id]) 
	{
		dfs(E.to);
		ans[id]+=ans[E.to];
	}	
}
void print(ll id)
{
	for(edge E:e[id]) 
	{
		printf("%lld %lld %c\n",id,E.to,E.c);
		print(E.to);
	}	
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--)
	{
		memset(ans,0,(cnt+1)*8);
		cin>>n>>q;
		for(int i=0;i<=cnt;i++) e[i].clear();
		cnt=1;
		for(int i=1;i<=n;i++)
		{
			cin>>s;
			pos=1;
			for(char c:s)
			{
				flag=0;
				for(edge E:e[pos])
					if(E.c==c)
					{
						pos=E.to;
						flag=1;
						break;
					}
				if(!flag) 
				{
					e[pos].push_back((edge){++cnt,c});
					pos=cnt;
				}	
			}
			ans[pos]++;
		}
		dfs(1);
		while(q--)
		{
			cin>>s;
			pos=1;
			f=0;
			for(char c:s)
			{
				flag=0;
				for(edge E:e[pos])
					if(E.c==c)
					{
						pos=E.to;
						flag=1;
						break;
					}	
				if(!flag)
				{
					cout<<0<<"\n";
					f=1;
					break;
				}	
			}
			if(f) continue;
			cout<<ans[pos]<<"\n";
		}
	}
	return 0;
}