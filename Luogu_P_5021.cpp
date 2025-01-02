#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,cnt,u,v,w,l,r=50005,mid;
struct edge
{
	ll to,w
};
vector <edge> e[50005];
bool vis[maxn];
int dia,dp[maxn];
struct node
{
	int cnt,edge;
	node(int cnt_,int edge_)
	{
		cnt=cnt_;
		edge=edge_;
	}
};

int flg;

node dfs(int x,int fa,int binary_len)
{
	int cnt=0,edge=0;
	multiset<int> _set;

	for(ri i=head[x];i;i=e[i].nex)
	{
		int to=e[i].to;
		int val=e[i].val;
		
		if (to == fa)
		{
			continue;
		}
		node son=dfs(to,x,binary_len);
		if (val+son.edge >= binary_len)
		{
			++cnt;
		}
		else
		{
			_set.insert(val+son.edge);
		}
		cnt += son.cnt;
	}
	
	while (!_set.empty())
	{
		
		multiset<int>::iterator it=_set.upper_bound(0);//迭代器
		
		int top=*it;//迭代器的值
		_set.erase(it);
		it=_set.lower_bound(binary_len-top);
		
		if (it == _set.end())
		{
			edge=top;
		}
		else
		{
			_set.erase(it);
			++cnt;
		}
	}

	if (cnt >= m)
	{
		flg=true;//个数过多
	}
	return node(cnt,edge);//推进去
}
int ans;
int main()
{
	srand((time)(0));
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n-1;i++)
	{
		scanf("%lld%lld%lld",&u,&v,&w);
		e[u].push_back((edge){v,w});
		e[v].push_back((edge){u,w});
	}
	int l=0;
	int r=dia;
	int mid;
	while (l<=r)//二分最短长
	{
		mid=(l+r)>>1;
		flg=false;
		dfs(1,0,mid);//flg赋值
		if (flg)
		{
			l=mid+rand()%2;
			ans=mid;
		}
		else
		{
			r=mid-rand()%2;//原谅我至今不知道是否要加减。
		}
	}
	return 0&printf("%d",ans);
}