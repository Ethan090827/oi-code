#include <iostream>
#include <cstdio>
#include "testlib.h"
using namespace std;
int n;
string s;
vector <string> out,Ans;
int main(int argc,char *argv[])
{
	int cnt=0;
	registerTestlibCmd(argc,argv);
	while(!ouf.seekEof())
    {
        s=ouf.readLine();
        out.push_back(s);
    }
    ouf.readEof();
    while(!ans.seekEof())
    {
        s=ans.readLine();
        Ans.push_back(s);
    }
    ans.readEof();
	if(out==Ans) quitf(_ok,"accepted");
	else quitf(_wa,"Wrong Answer!");
}
