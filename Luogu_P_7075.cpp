#include <bits/stdc++.h>
#define ll long long
#define FileI(a) auto abc=freopen(a,"r",stdin);while(abc!=abc);
#define FileO(a) auto Abc=freopen(a,"w",stdout);while(Abc!=Abc);
#define scanf int ABC=scanf
using namespace std;
ll q,r,days,Day=0,month=1,monthday[15]={0,31,28,31,30,31,30,31,31,30,31,30,31};
//1582/10/4前的闰年判断
bool is_run1(ll year)
{
	if(year<0) year++;
	if(year%4==0) return 1;
	return 0;
}
//1582/10/15后的闰年判断
bool is_run2(ll year)
{
	if(year%400==0) return 1;
	if(year%100==0) return 0;
	if(year%4==0) return 1;
	return 0;
}
int main()
{
#ifndef ONLINE_JUDGE
	FileI("julian3.in");
	FileO("julian3.out");
#endif
	scanf("%lld",&q);
	while(q--)
	{
		scanf("%lld",&r);
		ll R=r,year=-4713,M=0,D=0;
		if(r<=2299160)
		{
			year+=4*(R/1461);
			R%=1461ll;
			R++;
			if(R>366)
			{
				R-=366;
				year++;
				while(R>365)
				{
					R-=365;
					year++;
				}
			}
			if(year>=0) year++;
			if(is_run1(year)) monthday[2]++;
			for(int i=1;i<=12;i++)
			{
				if(R>monthday[i])
				{
					R-=monthday[i];
					M=i;
				}
				else break;
			}
			M++;
			D=R;
			if(D==0)
			{
				if(M==1)
				{
					M=12;
					D=31;
					year--;
				}
				else
				{
					M--;
					D=monthday[M];
				}
			}
			monthday[2]=28;
			if(year<0) printf("%lld %lld %lld BC\n",D,M,-year);
			else printf("%lld %lld %lld\n",D,M,year);
		}
		else
		{
			R-=2299160;
			if(R<=78)
			{
				if(R<=17) printf("%lld 10 1582\n",14+R);
				else if(R<=47) printf("%lld 11 1582\n",R-17);
				else printf("%lld 12 1582\n",R-47);
			}
			else
			{
				R-=78;
				year=1583;
				if(r<=2305448)
				{
					year+=4*(R/1461);
					R%=1461ll;
					if(R>365)
					{
						R-=365;
						year++;
					}
					if(R>366)
					{
						R-=366;
						year++;
						while(R>365)
						{
							R-=365;
							year++;
						}
					}
					if(is_run2(year)) monthday[2]++;
					for(int i=1;i<=12;i++)
					{
						if(R>monthday[i])
						{
							R-=monthday[i];
							M=i;
						}
						else break;
					}
					M++;
					D=R;
					if(D==0)
					{
						if(M==1)
						{
							M=12;
							D=31;
							year--;
						}
						else
						{
							M--;
							D=monthday[M];
						}
					}
					monthday[2]=28;
					printf("%lld %lld %lld\n",D,M,year);
				}
				else
				{
					R=r-2305447;
					year=1600;
					year+=400*(R/146097);
					R%=146097;
					if(R>36525)
					{
						R-=36525;
						year+=100;
						while(R>36524)
						{
							R-=36524;
							year+=100;
						}
					}
					if(year%400==0)
					{
						year+=4*(R/1461);
						R%=1461ll;
						if(R>366)
						{
							R-=366;
							year++;
							while(R>365)
							{
								R-=365;
								year++;
							}
						}
						if(is_run2(year)) monthday[2]++;
						for(int i=1;i<=12;i++)
						{
							if(R>monthday[i])
							{
								R-=monthday[i];
								M=i;
							}
							else break;
						}
						M++;
						D=R;
						if(D==0)
						{
							if(M==1)
							{
								M=12;
								D=31;
								year--;
							}
							else
							{
								M--;
								D=monthday[M];
							}
						}
						monthday[2]=28;
						printf("%lld %lld %lld\n",D,M,year);
					}
					else
					{
						if(R<=1460)
						{
							while(R>365)
							{
								R-=365;
								year++;
							}
							for(int i=1;i<=12;i++)
							{
								if(R>monthday[i])
								{
									R-=monthday[i];
									M=i;
								}
								else break;
							}
							M++;
							D=R;
							if(D==0)
							{
								if(M==1)
								{
									M=12;
									D=31;
									year--;
								}
								else
								{
									M--;
									D=monthday[M];
								}
							}
							monthday[2]=28;
							printf("%lld %lld %lld\n",D,M,year);
						}
						else
						{
							R++;
							year+=4*(R/1461);
							R%=1461ll;
							if(R>366)
							{
								R-=366;
								year++;
								while(R>365)
								{
									R-=365;
									year++;
								}
							}
							if(is_run2(year)) monthday[2]++;
							for(int i=1;i<=12;i++)
							{
								if(R>monthday[i])
								{
									R-=monthday[i];
									M=i;
								}
								else break;
							}
							M++;
							D=R;
							if(D==0)
							{
								if(M==1)
								{
									M=12;
									D=31;
									year--;
								}
								else
								{
									M--;
									D=monthday[M];
								}
							}
							monthday[2]=28;
							printf("%lld %lld %lld\n",D,M,year);
						}
					}
				}
			}
		}
	}
	return 0;
}
