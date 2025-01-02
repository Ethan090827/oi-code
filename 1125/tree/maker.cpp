#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
//	freopen(".in","r",stdin);
	freopen("ex_tree4.in","w",stdout);
    puts("100000");
    srand(time(0));
    for(int i=1;i<=500000;i++)
    {
        ll a=rand()*2147483648;
        printf("%lld\n",a+rand());
    }
    return 0;
}
