#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,x,y,s,t,node,step[10005];
bool f[10005],F[10005];
vector <ll> e[10005],E[10005]; 
queue <ll> q;
int main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld",&x,&y);
		e[x].push_back(y);
		E[y].push_back(x);
	}
	scanf("%lld%lld",&s,&t);
	q.push(t);
	f[t]=1;
	while(!q.empty())
	{
		node=q.front();
		q.pop();
		for(int i=0;i<E[node].size();i++)
			if(!f[E[node][i]]) 
			{
				q.push(E[node][i]);
				f[E[node][i]]=1;
			}
	}
	for(int i=1;i<=n;i++)
		if(f[i])
		{
			F[i]=1;
			for(int j=0;j<e[i].size();j++)
				if(!f[e[i][j]])
				{
					F[i]=0;
					break;
				} 
		}
	while(!q.empty()) q.pop();	
	if(F[s]) q.push(s);
	while(!q.empty())
	{
		node=q.front();
		q.pop();
		if(node==t)
		{
			printf("%lld\n",step[node]);
			return 0;
		}
		for(int i=0;i<e[node].size();i++)
			if(!step[e[node][i]]&&F[e[node][i]]) 
			{
				q.push(e[node][i]);
				step[e[node][i]]=step[node]+1;
			}
	}
	puts("-1");
	return 0;
}