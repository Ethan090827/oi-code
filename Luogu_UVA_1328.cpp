#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll Next[1000005],cnt,n,j;
int main()
{
	while(1)
	{
        scanf("%lld",&n);
        if(n==0) break;
		cin>>s;
        s=' '+s;
		printf("Test case #%lld\n",++cnt);
        j=0;
		for(int i=2;i<=n;i++)
		{
			while(j&&s[i]!=s[j+1])
				j=Next[j];  
			if(s[i]==s[j+1]) j++;
			Next[i]=j;
			if(j&&(i%(i-j))==0)
				printf("%d %d\n",i,i/(i-j));
		}
		puts("");
	}
    return 0;
}
