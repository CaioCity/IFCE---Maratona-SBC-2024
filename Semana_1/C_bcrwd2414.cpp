// https://judge.beecrowd.com/en/problems/view/2414
// Problema 2414: Desafio do Maior Número

#include <iostream>

int main(){
	
	short int number,resp=0;

	do{
		std::cin>>number;
		if(resp<number)
			resp=number;
	} while(number!=0);
		
	std::cout<<resp<<std::endl;
	return 0;
}
