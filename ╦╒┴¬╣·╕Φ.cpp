#include <cstdio>
#include <windows.h>
#define do 262 
#define re 294
#define mi 330
#define fa 349
#define so 392
#define la 440
#define si 494
#define do1 523
#define re1 578
#define mi1 659
#define fa1 698
#define so1 784
#define la1 880
#define si1 988
#define b(a,b) Beep(a,b);
#define s(b) Sleep(b);
using namespace std;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int pai,ban;
	scanf("%d",&pai);
	pai=60000/pai;
	ban=pai/2; 
	b(do1,3*pai)
	s(ban)
	b(so,ban)
	
	for(int i=1;i<=3;i++)
	{
		b(do1,pai)
		b(so,1.5*ban)
		b(la,0.5*ban)
		b(si,pai)
		b(mi,ban)
		b(mi,ban)
		
		b(la,pai)
		b(so,1.5*ban)
		b(fa,0.5*ban)
		b(so,pai)
		b(do,ban)
		b(do,ban)
		
		b(re,pai)
		b(re,1.5*ban)
		b(mi,0.5*ban)
		b(fa,pai)
		b(fa,1.5*ban)
		b(so,0.5*ban)
		
		b(la,pai)
		b(si,ban)
		b(do1,ban)
		b(re1,1.5*pai)
		b(so,ban) 
		
		b(mi1,pai)
		b(re1,1.5*ban)
		b(do1,0.5*ban)
		b(re1,pai)
		b(si,ban)
		b(so,ban)
		
		b(do1,pai)
		b(si,1.5*ban)
		b(la,0.5*ban)
		b(si,pai)
		b(mi,ban)
		b(mi,ban)
		
		b(la,pai)
		b(so,1.5*ban)
		b(fa,0.5*ban)
		b(so,pai)
		b(do,ban)
		b(do,ban)
		
		b(do1,pai)
		b(si,1.5*ban)
		b(la,0.5*ban)
		b(so,2*pai)
		
		b(mi1,2*pai)
		b(re1,ban)
		b(do1,ban)
		b(si,ban)
		b(do1,ban)
		
		b(re1,1.5*pai)
		b(so,ban)
		b(so,2*pai)
		
		b(do1,2*pai)
		b(si,ban)
		b(la,ban)
		b(so,ban)
		b(la,ban)
		
		b(si,1.5*pai)
		b(mi,ban)
		b(mi,pai)
		s(pai)
		
		b(do1,pai)
		b(la,1.5*ban)
		b(si,0.5*ban)
		b(do1,pai)
		b(la,1.5*ban)
		b(si,0.5*ban)
		
		b(do1,pai)
		b(la,1.5*ban)
		b(do1,0.5*ban)
		b(fa1,1.5*pai)
		s(ban)
		
		b(fa1,2*pai)
		b(mi1,ban)
		b(re1,ban)
		b(do1,ban)
		b(re1,ban)
		
		b(mi1,1.5*pai)
		b(do1,ban) 
		b(do1,2*pai)
		
		b(re1,2*pai)
		b(do1,ban)
		b(si,ban)
		b(la,ban)
		b(si,ban)
		
		b(do1,1.5*pai)
		b(la,ban) 
		b(la,2*pai)
		
		b(do1,pai)
		b(si,ban)
		b(la,ban)
		b(so,pai)
		b(do,1.5*ban)
		b(do,0.5*ban)
		
		if(i<=2)
		{
			b(do1,pai)
			b(si,1.5*ban)
			b(la,0.5*ban)
			b(so,pai)
			s(ban)
			b(so,ban)
		}
		
		else
		{
			b(so,2*pai)
			b(la,pai)
			b(si,pai)
			
			b(do1,4*pai)
		}

	}
	return 0;
}

