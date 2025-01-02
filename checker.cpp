#include <bits/stdc++.h>
#define ll long long
using namespace std;
string name,s,in,out,ans,add,id[100005];
ll n;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	puts("enter the address of the program:");
	cin>>add;
	puts("enter the name of the problem:");
	cin>>name;
	puts("enter the format of the input file:");
	cin>>in;
	puts("enter the format of the answer file:");
	cin>>ans;
	system("cd ~");
	system(("cp ~/Desktop/hyz/cmp "+add).c_str());
	system(("cd "+add).c_str());
    puts("enter the number of test cases:");
    scanf("%lld",&n);
    puts("enter the test cases ids:");
	for(int i=1;i<=n;i++)
        cin>>id[i];
	system(("g++ "+name+".cpp -std=c++14 -O2 -o "+name).c_str());
	system(("cp "+name+id[1]+"."+in+" "+name+".in").c_str());
	for(int i=1;i<=n;i++)
	{
		system(("rm "+name+"."+in).c_str());
		system(("cp "+name+id[i]+"."+in+" "+name+".in").c_str());
		system(("time ./"+name).c_str());
		system(("./cmp "+name+id[i]+"."+in+" "+name+".out "+name+"."+ans).c_str());
	}
	return 0;
}