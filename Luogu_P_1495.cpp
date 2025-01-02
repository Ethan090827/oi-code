#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[10],b[10];
ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if (b==0)
    {
        x=1;
        y=0;
        return a;
    }
    ll d=exgcd(b,a%b,y,x);
    y-=(a/b)*x;
    return d;
}
ll inv(ll a, ll p)
{
    ll x,y;
    exgcd(a,p,x,y);
    return (x%p+p)%p;
}
ll CRT(ll a[],ll b[],ll n)
{
    ll p=1,x=0;
    for(int i=0;i<n;i++)
        p*=a[i];
    for(int i=0;i<n;i++)
    {
        ll r=p/a[i];
        x+=(b[i]*r*inv(r,a[i]))%p;
    }
    return x%p;
}
int main()
{
    scanf("%lld",&n);
    for(int i=0;i<n;i++)
        scanf("%lld%lld",a+i,b+i);
    printf("%lld\n",CRT(a,b,n));
    return 0;
}
