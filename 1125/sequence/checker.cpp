#include <bits/stdc++.h>
#include "testlib.h"
#define ll long long
using namespace std;
ll a[500005],b[500005];
int main(int argc,char *argv[])
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	registerTestlibCmd(argc,argv);
	string s=ouf.readString();
	if(s=="NO")	quitf(_ok,"Not sure whether it's right.");
	string S=inf.readString();
//	inf.readEoln();
	string T=inf.readString();
	string ans="";
	for(unsigned int i=0;i<T.length();i++)
	{
		a[i]=ouf.readInt();
		ans+=S[a[i]-1];
		if(i==0) continue;
		for(int j=a[i]-1;j>a[i-1]+1;j--)
			if(S[j-1]!=S[j-2])
				quitf(_wa,"Wrong on No.3!");
	}
	memcpy(b,a,sizeof(a));
	sort(a,a+T.length());
	for(unsigned int i=0;i<T.length();i++)
		if(a[i]!=b[i]) quitf(_wa,"Wrong on No.1!");
	if(ans!=T) quitf(_wa,"Wrong on No.2!");
	quitf(_ok,"Accepted!");
	return 0;
}