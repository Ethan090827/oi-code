#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a,b,x,y;
ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    ll d=exgcd(b,a%b,y,x);
    y-=(a/b)*x;
    return d;
}
int main()
{
    scanf("%lld%lld",&a,&b);
    exgcd(a,b,x,y);
    printf("%lld\n",((x%b)+b)%b);
    return 0;
}