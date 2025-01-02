# P11257 [GDKOI2023 普及组] 交换机 题解

这个题解可能没有其他大佬的优，但主打一个简单易懂

## 题意简述
给定若干数据帧，每一数据帧包含：$\texttt{MAC}$ 地址、时间

每一 $\texttt{MAC}$ 地址会保存一给定时间（被称为老化期），老化期一到立即删除，除非老化期内又收到含有该 $\texttt{MAC}$ 的数据帧，则刷新老化期。

问同一时刻内最多同时存储着几个数据帧。

## 思路分析
### 读入
第一行输入两个整数 $n,k$，不必多说

接下来 $n$ 行，每行两个字符串，表示 $\texttt{MAC}$ 地址和时间（$\texttt{hh:mm}$）

字符串不方便存储，可以使用 `map` 。
具体来说，每读入一个新的 $\texttt{MAC}$ 地址，按读入的先后顺序将其从 $1$ 开始编号。

而时间可以通过 `scanf` 分别读入小时和分钟，并计算为一天中的第几分钟。

同时，计算出该数据帧所对应的清除时刻，和发送时刻一起加入其 $\texttt{MAC}$ 地址对应的 `vector` 中。

其中，要特别注意，清除时刻可能会超过 $1440$，即一天中的分钟数，导致越界，要特别处理（见注释）。

~~不要问我怎么知道的，问就是 RE 了好几个点~~

还有，为了防止某一时刻一个地址删除而另一个地址加入导致多算，可以将删除时间减 $1$ 。

```cpp
vector <pair <ll,ll>> mac[100005];
map <string,int> M; //MAC地址的编号
scanf("%lld%lld",&n,&k);
for(int i=1;i<=n;i++)
{
	cin>>str; //读入MAC地址
	if(!M[str]) M[str]=++size; //如果是新地址则编号
	scanf("%lld:%lld",&h,&m); //读入时间
	s=h*60+m;
	e=min(1440ll,s+k-1); //就是这里
	mac[M[str]].push_back(make_pair(s,e));
}
```

### 计算

遍历每个 $\texttt{MAC}$ 地址（其实是其对应编号），因为从 $1$ 开始且大小记录在 `size` 中，所以相当方便。

- 对于每一个 $\texttt{MAC}$ 地址，遍历其 `vector` 中存储的“加入时间-删除时间”对。
- - 遍历从加入时间到删除时间中的每一分钟，打上标记
- 遍历一天中的每一分钟，如果有标记则该时刻的“交换机表”大小加 $1$。

遍历遍历一天中的每一分钟，求“交换机表”大小的最大值。

----------

虽然看似效率不高（确实也不快），有 $3$ 重循环，时间复杂度高达 $\mathcal{O}(nt)$（ $t$ 表示一天中的分钟数），但非常直观明了。

时间复杂度是 $\mathcal{O}(nt)$（ $t$ 表示一天中的分钟数），虽然有三重循环，但因为前两重循环相当于遍历了所有 $n$ 个数据帧，所以并没有 $\mathcal{O}(n^2)$ 级。而且考虑到一天只有 $1440$ 分钟，这个时间复杂度也是可以接受的。

```cpp
for(int i=1;i<=size;i++)
{
	memset(f,0,sizeof(f)); //清空标记数组
	for(auto j:mac[i]) //遍历mac[i]中每个pair，非常方便的写法
		for(int t=j.first;t<=j.second;t++)
			f[t]=1; //标记加入到删除时刻间的所有分钟
	for(int t=0;t<=1440;t++)
		if(f[t]) ans[t]++;		
}
for(int i=0;i<=1440;i++)
	maxn=max(maxn,ans[i]); //统计最大值
```

### 输出

最后输出最大值 `maxn`，没什么好说的。


## 完整代码
```cpp
#include <bits/stdc++.h>
#define ll long long
#define mp(a,b) make_pair(a,b)
#define fi first
#define se second
using namespace std;
vector <pair <ll,ll>> mac[100005];
ll n,k,h,m,s,e,f[1445],ans[1445],size,maxn;
string str;
map <string,int> M;
int main()
{
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		cin>>str;
		if(!M[str]) M[str]=++size;
		scanf("%lld:%lld",&h,&m);
		s=h*60+m;
		e=min(1440ll,s+k-1);
		mac[M[str]].push_back(mp(s,e));
	}
	for(int i=1;i<=size;i++)
	{
		memset(f,0,sizeof(f));
		for(auto j:mac[i])
			for(int t=j.fi;t<=j.se;t++)
				f[t]=1;
		for(int t=0;t<=1440;t++)
			if(f[t]) ans[t]++;		
	}
	for(int i=0;i<=1440;i++)
		maxn=max(maxn,ans[i]);
	printf("%lld\n",maxn);	
	return 0;
}
```

## 完结撒花～