// https://judge.beecrowd.com/en/problems/view/2417
// Problema 2417: Campeonato

#include <iostream>

int main(){
	
	short int Cv,Ce,Cs,Fv,Fe,Fs;

	std::cin>>Cv>>Ce>>Cs>>Fv>>Fe>>Fs;
	
	short int pontC=(3*Cv + Ce), pontF=(3*Fv + Fe);
	
	if( pontC>pontF || (pontC==pontF && Cs>Fs))
		std::cout<<"C\n";
	else if( pontF>pontC || (pontC==pontF && Fs>Cs))
		std::cout<<"F\n";
	else 
		std::cout<<"=\n";
		
	return 0;
}
