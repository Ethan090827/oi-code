#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,c[45][25];
int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=2*n;i++)
    {
    	c[i][0]=c[i][i]=1;
    	for(int j=1;j<i;j++)
    		c[i][j]=c[i-1][j]+c[i-1][j-1];
	}
    printf("%lld",c[2*n][n]-c[2*n][n-1]);
    return 0;
}