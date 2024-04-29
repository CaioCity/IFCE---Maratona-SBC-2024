// https://judge.beecrowd.com/en/problems/view/2409
// Problema 2409: Colchão

#include <iostream>

int main(){

	short int A,B,C,H,L;
	short int M1,M2;
	
	std::cin>>A>>B>>C>>H>>L;
	
	if(A<B && A<C){
		M1=A;
		M2= B<C? B:C;
	}
	else if (B<A && B<C){
		M1=B;
		M2= A<C?A:C;
	}
	else {
		M1=C;
		M2= A<B?A:B;	
	}
	
	if( (M1<=H && M2<=L) || (M1<=L && M2<=H))
		std::cout<<"S\n";
	else 
		std::cout<<"N\n";
	
	return 0;
}
