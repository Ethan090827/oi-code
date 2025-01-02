#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
#define int long long
#define ll __int128
#define y1 ___
#define y2 ____
const int N = 51; 
int n,m,k,ok[N][N][N][N];
ll f[N][N];
signed main(signed argc,char* argv[])
{
    registerTestlibCmd(argc, argv);
	int tt = inf.readLong();
	ll T = tt;
	n = ouf.readLong(),m = ouf.readLong(),k = ouf.readLong();
	if(n>50||m>50||k>300) quitf(_wa,"Wrong answer.");
	while(k--)
	{
		int x1,y1,x2,y2;
		x1 = ouf.readLong(),y1 = ouf.readLong(),x2 = ouf.readLong(),y2 = ouf.readLong();
		ok[x1][y1][x2][y2] = ok[x2][y2][x1][y1] = 1;
	}
	f[1][1] = 1;
	for(int i = 1;i<=n;i++)
		for(int j = 1;j<=m;j++)
		{
			if(i==1&&j==1) continue;
			if(!ok[i][j][i-1][j]) f[i][j]+=f[i-1][j];
			if(!ok[i][j][i][j-1]) f[i][j]+=f[i][j-1];
		}
	if(T!=f[n][m]) quitf(_wa,"Wrong answer.");
	quitf(_ok,"Correct answer.");
	return 0;
}
