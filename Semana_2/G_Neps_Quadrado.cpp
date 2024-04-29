// https://neps.academy/br/exercise/494
// Quadrado

#include <iostream>

int main(){
	
	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	
	short int N;
	std::cin>>N;
	
	short int M[N+1][N+1];
	
	for(int j=0; j<N; j++) //so para zerar (n deu pra inicializar zerado)
		M[N][j]=0;
		
	for(int i=0; i<N; i++){
		M[i][N]=0;
		for(int j=0; j<N; j++){
			std::cin>>M[i][j];
			M[i][N]+=M[i][j];
			M[N][j]+=M[i][j];
		}
	}
				
	short int magic; //a soma das linhas/colunas
	
	if( M[0][N]==M[1][N] || M[0][N]==M[2][N] )
		magic=M[0][N];
	else
		magic=M[1][N];
	
	short int linha;
	for(linha=0; M[linha][N] == magic; linha++);
	
	short int coluna;
	for(coluna=0; M[N][coluna] == magic; coluna++);
	
	std::cout<< M[linha][coluna] - (M[linha][N]-magic) <<" "<<M[linha][coluna]<<std::endl;
	
	return 0;
}
