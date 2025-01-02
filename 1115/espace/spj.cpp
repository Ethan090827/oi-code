#include<iostream>
#include<cstdio>
#include"testlib.h"
#define N 250000
using namespace std;
int n,k;
char c[N+1];
string w,s[N+1],t[N+1];
int main(int argc,char *argv[])
{
	int cnt=0;
	registerTestlibCmd(argc,argv);
	n=inf.readInt(),w=inf.readToken(),k=inf.readInt();
	for (int i=1;i<=k;++i)
	{
		s[i]=ouf.readToken();
		if (s[i]!="yes"&&s[i]!="no") quitf(_wa,"Wrong Answer");
	}
	for (int i=1;i<=k;++i) t[i]=ans.readToken();
	for (int i=1;i<=k;++i)
		if (s[i]==t[i])
			cnt++;
	if (cnt==0) quitf(_wa,"Wrong Answer");
	else if (cnt==k) quitf(_ok,"Accepted!");
	else quitp((int)(floor(10*pow(1.0*cnt/k,3.5))),"Partically Correct. Correct answer=%d",cnt);
}
