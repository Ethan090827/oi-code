#include<bits/stdc++.h>
#define rp(i,a,b) for(int i=a,_=b;i<=_;++i)
#define pr(i,a,b) for(int i=a,_=b;i>=_;--i)
using namespace std;
#define T (1<<15)
char buf[T],*p1=buf,*p2=buf;
#define nc() (p1==p2&&(p2=buf+fread(p1=buf,1,T,stdin),p1==p2)?-1:*p1++)
int rd(){
	int x=0;char c;bool s=0;
	do c=nc();while(c!=45&&(c<48||c>57));
	if(c==45)c=nc(),s=1;
	do x=10*x+(c&15),c=nc();while(c>=48&&c<=57);
	return s?-x:x;
}
#undef T
int main(){
	return 0;
}