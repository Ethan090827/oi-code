#include <bits/stdc++.h>
#define ll long long
#define FileI(a) auto abcdefg=freopen(a,"r",stdin)
#define FileO(a) auto Abcdefg=freopen(a,"w",stdout)
#define scanf int ABCDEFG=scanf
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
//	FileI(".in");
	FileO("tatooine6.in");
#endif
	puts("600");
	srand(time(0));
	for(int i=2;i<=600;i++)
		printf("%d %d %d\n",1,i,rand()%20+1);
	return 0;
}
