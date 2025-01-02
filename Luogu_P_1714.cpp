#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll ans,n,m,a,s[500005];
deque <ll> dq;
int main()
{
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a);
        s[i]=s[i-1]+a;
    }
    dq.push_back(0);
    for(int i=1;i<=n;i++)
    {
        while(dq.front()+m<i)
            dq.pop_front();
        ans=max(ans,s[i]-s[dq.front()]);
        while(!dq.empty()&&s[dq.back()]>=s[i])
            dq.pop_back();
        dq.push_back(i);
    }
    printf("%lld\n",ans);
    return 0;
}