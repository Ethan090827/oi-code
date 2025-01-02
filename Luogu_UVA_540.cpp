#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,id,mem[1000005],cnt;
string op;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	while(1)
	{
		scanf("%lld",&t);
		if(t==0) break;
		memset(mem,0,sizeof(mem));
		queue <ll> team,member[1005];
		printf("Scenario #%lld\n",++cnt);
		for(int i=1;i<=t;i++)
		{
			scanf("%lld",&n);
			for(int j=1;j<=n;j++)
			{
				scanf("%lld",&id);
				mem[id]=i;
			}	
		}
		while(1)
		{
			cin>>op;
			if(op=="STOP") break;
			if(op=="ENQUEUE")
			{
				scanf("%lld",&id);
				if(member[mem[id]].empty())
				{
					team.push(mem[id]);
					member[mem[id]].push(id);
				}
				else member[mem[id]].push(id);
			}
			if(op=="DEQUEUE")
			{
				printf("%lld\n",member[team.front()].front());
				member[team.front()].pop();
				if(member[team.front()].empty()) team.pop();
			}
		}
		puts("");
	}
	return 0;
}
