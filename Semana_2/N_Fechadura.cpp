// https://neps.academy/br/exercise/391
// Fechadura

#include <iostream>

int main(){
	
	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	
	short int N,M,moves=0;
	std::cin>>N>>M;
	
	short int Pinos[N];
	for(short int i=0; i<N; i++)
		std::cin>>Pinos[i];
		
	for(short int i=0; i<(N-1); i++){
		if(Pinos[i]<M){
			moves+=(M-Pinos[i]);
			Pinos[i+1]+=(M-Pinos[i]);
		}
		if(Pinos[i]>M){
			Pinos[i+1]-=(Pinos[i]-M);
			moves+=(Pinos[i]-M);
		}
	}
	
	std::cout<<moves<<std::endl;
	
	return 0;
}
