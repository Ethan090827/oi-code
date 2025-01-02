#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
//	freopen(".in","r",stdin);
	freopen("seq.in","w",stdout);
	srand(time(0));
	for(int i=1;i<=500000;i++)
		printf("%d",rand()%2);
	puts("");
	for(int i=1;i<=200000;i++)
		printf("%d",rand()%2);
	puts("");	    
	return 0;
}
