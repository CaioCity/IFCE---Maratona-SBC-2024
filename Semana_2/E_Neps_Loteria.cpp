// https://neps.academy/br/exercise/491
// Loteria

#include <iostream>

int main(){
	
	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	
	short int Flav[6], gab, acertos=0;
	
	for(int i=0; i<6; i++){
		std::cin>>Flav[i];
	}
	
	for(int i=0; i<6; i++){
		std::cin>>gab;
		for(int j=0; j<6; j++){
			if(gab==Flav[j])
				acertos++;
		}
	}
	
	if(acertos<3)
		std::cout<<"azar\n";	
	else if (acertos==3)
		std::cout<<"terno\n";
	else if (acertos==4)
		std::cout<<"quadra\n";
	else if (acertos==5)
		std::cout<<"quina\n";
	else if (acertos==6)
		std::cout<<"sena\n";
		
	return 0;
}
