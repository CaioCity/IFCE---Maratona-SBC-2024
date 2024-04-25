// https://judge.beecrowd.com/en/problems/view/2408
// Problema : Vice-Campeão

#include <iostream>

int main(){
	
	short int p1,p2,p3;
	
	std::cin>>p1>>p2>>p3;
	
	if( (p1>p2 && p1<p3) || (p1<p2 && p1>p3) )
		std::cout<<p1<<std::endl;
	else if( (p2>p1 && p2<p3) || (p2<p1 && p2>p3) )
		std::cout<<p2<<std::endl;
	else
		std::cout<<p3<<std::endl;
		
	return 0;
}
