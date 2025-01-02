#include <bits/stdc++.h>
#define ll long long
#define FileI(a) auto abc=freopen(a,"r",stdin);while(abc!=abc);
#define FileO(a) auto Abc=freopen(a,"w",stdout);while(Abc!=Abc);
#define scanf int ABC=scanf;while(ABC!=ABC);
using namespace std;
string s;
int main()
{
	FileO("change.out");
	while(getline(cin,s))
	{
		if(s=="stop") break;
		cout<<"\"";
		for(char c:s)
		{
			if(c=='\t') cout<<"\\t";
			else if(c=='\"') cout<<"\\\"";
			else cout<<c;
		}
		cout<<"\",\n";
	}
	return 0;
}
