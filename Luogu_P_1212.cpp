#include <bits/stdc++.h>
#define ll long long
#define FileI(a) auto abc=freopen(a,"r",stdin);while(abc!=abc);
#define FileO(a) auto Abc=freopen(a,"w",stdout);while(Abc!=Abc);
#define scanf auto ABC=scanf
using namespace std;
ll cnt[10],length[10005],shorth[10005],k,L,S,ans=1<<30,K,flag,meml[5],memr[5];
struct rect
{
	ll length,shorth,id;
	bool operator < (const rect &A) const
	{
		return id>A.id;
	}
}a[10];
struct Ans
{
	ll length,shorth;
}b[10005];
bool cmp(Ans a,Ans b)
{
	return a.shorth<b.shorth;
}
int main()
{
#ifndef ONLINE_JUDGE
//	FileI(".in");
	FileO("P1212.out");
#endif
	for(int i=1;i<=4;i++)
	{
		scanf("%lld%lld",&a[i].length,&a[i].shorth);
		a[i].id=a[i+4].id=i;
		a[i+4].length=a[i].shorth;
		a[i+4].shorth=a[i].length;
	}
	sort(a+1,a+9);
	do
	{
		flag=1;
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=4;i++)
			if(a[i].length!=meml[i]||a[i].shorth!=memr[i])
				flag=0;
		for(int i=1;i<=4;i++) cnt[a[i].id]++;
		for(int i=1;i<=4;i++)
			if(cnt[i]!=1)
			{
				flag=1;
				break;
			}
		if(flag) continue;
		printf("\n1:%lldx%lld 2:%lldx%lld 3:%lldx%lld 4:%lldx%lld\n",a[1].length,a[1].shorth,a[2].length,a[2].shorth,a[3].length,a[3].shorth,a[4].length,a[4].shorth);
		
	//	Case 1
		k++;
		for(int i=1;i<=4;i++)
		{
			length[k]=max(length[k],a[i].length);
			shorth[k]+=a[i].shorth;
		}
		printf("Case 1:L=%lld,W=%lld,S=%lld\n",length[k],shorth[k],length[k]*shorth[k]);
		ans=min(ans,length[k]*shorth[k]);

	//	Case 2
		k++;
		for(int i=1;i<=3;i++)
		{
			length[k]=max(length[k],a[i].length);
			shorth[k]+=a[i].shorth;
		}
		length[k]+=a[4].length;
		shorth[k]=max(shorth[k],a[4].shorth);
		printf("Case 2:L=%lld,W=%lld,S=%lld\n",length[k],shorth[k],length[k]*shorth[k]);
		ans=min(ans,length[k]*shorth[k]);

	//	Case 3
		k++;
		shorth[k]=max(a[1].shorth+a[2].shorth,a[4].shorth)+a[3].shorth;
		length[k]=max(a[3].length,max(a[1].length,a[2].length)+a[4].length);
		printf("Case 3:L=%lld,W=%lld,S=%lld\n",length[k],shorth[k],length[k]*shorth[k]);
		ans=min(ans,length[k]*shorth[k]);

	//	Case 4
		k++;
		length[k]=max(max(a[1].length,a[4].length),a[2].length+a[3].length);
		shorth[k]=max(a[2].shorth,a[3].shorth)+a[1].shorth+a[4].shorth;
		printf("Case 4:L=%lld,W=%lld,S=%lld\n",length[k],shorth[k],length[k]*shorth[k]);
		ans=min(ans,length[k]*shorth[k]);

	//	Case 5
		k++;
		length[k]=max(max(a[3].length,a[4].length),a[1].length+a[2].length);
		shorth[k]=max(a[1].shorth,a[2].shorth)+a[3].shorth+a[4].shorth;
		printf("Case 5:L=%lld,W=%lld,S=%lld\n",length[k],shorth[k],length[k]*shorth[k]);
		ans=min(ans,length[k]*shorth[k]);

	//	Case 6
		k++;
		length[k]=max(a[1].length+a[2].length,a[3].length+a[4].length);
		for(int i=1;i<=length[k];i++)
		{
			if(i<=a[2].length&&i<=a[4].length) shorth[k]=max(shorth[k],a[2].shorth+a[4].shorth);
			if(i>a[2].length&&i<=a[1].length+a[2].length&&i<=a[4].length) shorth[k]=max(shorth[k],a[1].shorth+a[4].shorth);
			if(i<=a[2].length&&i<=a[3].length+a[4].length&&i>a[4].length) shorth[k]=max(shorth[k],a[2].shorth+a[3].shorth);
			if(i>a[2].length&&i<=a[1].length+a[2].length&&i>a[4].length&&i<=a[3].length+a[4].length) shorth[k]=max(shorth[k],a[1].shorth+a[3].shorth);
			if(i<=a[1].length+a[2].length&&i>a[3].length+a[4].length) shorth[k]=max(shorth[k],max(max(a[1].shorth,a[2].shorth),max(a[3].shorth,a[4].shorth)));
			if(i>a[1].length+a[2].length&&i<=a[3].length+a[4].length) shorth[k]=max(shorth[k],max(max(a[1].shorth,a[2].shorth),max(a[3].shorth,a[4].shorth)));
		}
		printf("Case 6:L=%lld,W=%lld,S=%lld\n",length[k],shorth[k],length[k]*shorth[k]);
		ans=min(ans,length[k]*shorth[k]);

		for(int i=1;i<=4;i++)
		{
			meml[i]=a[i].length;
			memr[i]=a[i].shorth;
		}
	} while(next_permutation(a+1,a+9));
	printf("%lld\n",ans);
	for(int i=1;i<=k;i++)
		if(length[i]*shorth[i]==ans)
		{
			b[++K].length=max(length[i],shorth[i]);
			b[K].shorth=min(length[i],shorth[i]);
		}	
	sort(b+1,b+K+1,cmp);
	for(int i=1;i<=K;i++)
		if(b[i].length!=b[i-1].length&&b[i].shorth!=b[i-1].shorth)
			printf("%lld %lld\n",b[i].shorth,b[i].length);
	return 0;
}
