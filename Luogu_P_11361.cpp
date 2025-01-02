#include <bits/stdc++.h>
#define ll long long
#define feropen(a,b,c) auto I_am_EthanHYZ=freopen("edit.in","r",stdin)
#define frepoen(a,b,c) auto Luogu_ID_575298=freopen("edit.out","w",stdout)
#define scanf int I_Love_QQ=scanf
using namespace std;
ll t,n,pos1,pos2,a[1000005],b[1000005],K1,K2,k1,k2,ans,cntta,cnttb,cnta[20],cntb[2];
struct area
{
	ll s,e,cnt[20];
}p[1000005],q[1000005];
string s1,s2,t1,t2,S1,S2,str1[100005],str2[100005];
bool caseA;
void dfs1(ll depth)
{
	if(depth==n) 
	{
		bool f1=1;
		for(int i=0;i<n;i++)
			if((a[i]==-1||t1[i]=='0')&&S1[i]!=s1[i])
			{
				f1=0;
				break;
			}
		if(!f1) return;
		for(int i=1;i<=k1;i++)
		{
			cnta[0]=cnta[1]=0;
		//	printf("%lld %lld %lld %lld\n",p[i].s,p[i].e,p[i].cnt[0],p[i].cnt[1]);
			for(int l=p[i].s;l<=p[i].e;l++)
				cnta[S1[l]-'0']++; 
			if(cnta[0]!=p[i].cnt[0]||cnta[1]!=p[i].cnt[1])
			{
				f1=0;
				break;
			}	
		}
		if(!f1) return;
	//	cout<<S1<<endl;
		str1[++K1]=S1;
		return;
	}	
	S1[depth]='0';
	dfs1(depth+1);
	S1[depth]='1';
	dfs1(depth+1);
	S1[depth]='0';
}
void dfs2(ll depth)
{
	if(depth==n) 
	{
		bool f2=1;
		for(int i=0;i<n;i++)
			if((b[i]==-1||t2[i]=='0')&&S2[i]!=s2[i])
			{
				f2=0;
				break;
			}
		if(!f2) return;
		for(int i=1;i<=k2;i++)
		{
			cnta[0]=cnta[1]=0;
			for(int l=q[i].s;l<=q[i].e;l++)
				cnta[S2[l]-'0']++; 
			if(cnta[0]!=q[i].cnt[0]||cnta[1]!=q[i].cnt[1])
			{
				f2=0;
				break;
			}	
		}
		if(!f2) return;
		str2[++K2]=S2;
	//	cout<<S2<<endl;
		return;
	}	
	S2[depth]='0';
	dfs2(depth+1);
	S2[depth]='1';
	dfs2(depth+1);
	S2[depth]='0';
}
int main()
{
//	feropen("edit2.in","w",stdin);
//	frepoen("edit,out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		cin>>s1>>s2>>t1>>t2;
		pos1=pos2=ans=caseA=cntta=cnttb=k1=k2=0;
		cnta[0]=cnta[1]=cntb[0]=cntb[1]=0;
		memset(p,0,sizeof(p));
		memset(q,0,sizeof(q));
		fill(a+1,a+n+1,-1);
		fill(b+1,b+n+1,-1);
		if(t1[0]=='1')
		{
			k1=1;
			p[k1].s=0;
		}
		if(t2[0]=='1')
		{
			k2=1;
			q[k2].s=0;
		}
		for(int i=0;i<n;i++)
		{
			if(t1[i]=='1') 
			{
				if(t1[i-1]=='0') p[++k1].s=i;
				p[k1].e=i;
				p[k1].cnt[s1[i]-'0']++;
				a[i]=k1;
			}	
			else
			{
				cntta++;
				if((i&&i-p[k1].s<=1)||p[k1].s==n-1) 
				{
					a[i-1]=-1;
					p[k1].cnt[0]=p[k1].cnt[1]=0;
					k1--;
				}
				a[i]=-1;
			}
			if(t2[i]=='1') 
			{
				if(t2[i-1]=='0') q[++k2].s=i;
				q[k2].e=i;
				q[k2].cnt[s2[i]-'0']++;
				b[i]=k2;
			}	
			else
			{
				cnttb++;
				if((i&&i-q[k2].s<=1)||q[k2].s==n-1) 
				{
					b[i-1]=-1;
					q[k2].cnt[0]=q[k2].cnt[1]=0;
					k2--;
				}
				b[i]=-1;
			}
		}
		
		if(n<=10)
		{
			K1=K2=0;
			// for(int i=1;i<=k1;i++)
			// 	printf("%lld %lld %lld %lld\n",p[i].s,p[i].e,p[i].cnt[0],p[i].cnt[1]);
			// puts("");
			// for(int i=1;i<=k2;i++)
			// 	printf("%lld %lld %lld %lld\n",q[i].s,q[i].e,q[i].cnt[0],q[i].cnt[1]);	
			S1=S2="00000000000000000";
			for(int i=1;i<=K1;i++) str1[i]="";
			for(int i=1;i<=K2;i++) str2[i]="";
			dfs1(0);
		//	puts("");
			dfs2(0);
			for(int i=1;i<=K1;i++)
				for(int j=1;j<=K2;j++)
				{
					ll cnt=0;
					for(int k=0;k<n;k++)
						if(str1[i][k]==str2[j][k]) cnt++;
					ans=max(ans,cnt);
				}
			printf("%lld\n",ans);
			continue;
		}
		for(int i=1;i<n;i++)
			if(s1[i]!=s1[i-1]) caseA=1;
		//Case A	
		if(!caseA)
		{
			for(int i=0;i<n;i++)
				if(s2[i]==s1[0]) ans++;
			printf("%lld\n",ans);
			continue;
		}
		//Case B
		if(t1==t2)
		{
			for(int i=0;i<n;i++)
			{
				if(t1[i]=='0')
				{
					ans+=min(cnta[0],cntb[0])+min(cnta[1],cntb[1]);
					cnta[0]=cnta[1]=cntb[0]=cntb[1]=0;
					if(s1[i]==s2[i]) ans++;
				}
				else
				{
					cnta[s1[i]-'0']++;
					cntb[s2[i]-'0']++;
				}	
			}
			ans+=min(cnta[0],cntb[0])+min(cnta[1],cntb[1]);
			printf("%lld\n",ans);
			continue;
		}
		//Case C
		if(cntta==1&&cnttb==1)
		{
			ll it1=t1.find('0'),it2=t2.find('0');
			if(it1>it2)
			{
				swap(s1,s2);
				swap(t1,t2);
				swap(it1,it2);
			}
			for(int i=0;i<it1-1;i++)
				cnta[s1[i]-'0']++;
			for(int i=0;i<it2-1;i++)
				cntb[s2[i]-'0']++;
			ans+=min(cnta[0],cntb[0])+min(cnta[1],cntb[1]);
			cntb[0]=max(cntb[0]-cnta[0],0ll);
			cntb[1]=max(cntb[1]-cnta[1],0ll);
			if(cntb[s1[it1]-'0'])
			{
				ans++;
				cntb[s1[it1]-'0']--;
			}
			cnta[0]=cnta[1]=0;
			for(int i=it1+1;i<n;i++)
				cnta[s1[i]-'0']++;
			ans+=min(cnta[0],cntb[0])+min(cnta[1],cntb[1]);
			cntb[0]=cntb[1]=0;
			if(cnta[s2[it2]-'0'])
			{
				ans++;
				cnta[s2[it2]-'0']--;
			}
			cnta[0]=max(cnta[0]-cntb[0],0ll);
			cnta[1]=max(cnta[1]-cntb[1],0ll);
			for(int i=it2+1;i<n;i++)
				cntb[s2[i]-'0']++;
			ans+=min(cnta[0],cntb[0])+min(cnta[1],cntb[1]);
			printf("%lld\n",ans);
			continue;
		}
		if(n<=100000)
		{
			K1=K2=0;
			// for(int i=1;i<=k1;i++)
			// 	printf("%lld %lld %lld %lld\n",p[i].s,p[i].e,p[i].cnt[0],p[i].cnt[1]);
			// puts("");
			// for(int i=1;i<=k2;i++)
			// 	printf("%lld %lld %lld %lld\n",q[i].s,q[i].e,q[i].cnt[0],q[i].cnt[1]);	
			for(int i=1;i<=n;i++)
			{
				S1+="0";
				S2+="0";
			}
			for(int i=1;i<=K1;i++) str1[i]="";
			for(int i=1;i<=K2;i++) str2[i]="";
			dfs1(0);
		//	puts("");
			dfs2(0);
			for(int i=1;i<=K1;i++)
				for(int j=1;j<=K2;j++)
				{
					ll cnt=0;
					for(int k=0;k<n;k++)
						if(str1[i][k]==str2[j][k]) cnt++;
					ans=max(ans,cnt);
				}
			printf("%lld\n",ans);
			continue;
		}
		// for(int i=0;i<n;i++)
		// {
		// 	if(a[i]==-1)
		// 	{
		// 		if(b[i]==-1)
		// 			if(s1[i]==s2[i]) ans++;
		// 		else
		// 			if(q[b[i]].cnt[s1[i]-'0'])
		// 			{
		// 				ans++;
		// 				q[b[i]].cnt[s1[i]-'0']--;
		// 			}
		// 	}
		// 	else
		// 	{
		// 		if(b[i]==-1)
		// 			if(s1[i]==s2[i]) ans++;
		// 		else
		// 		{

		// 		}	
		// 	}
		// }
	}
	return 0;
}
