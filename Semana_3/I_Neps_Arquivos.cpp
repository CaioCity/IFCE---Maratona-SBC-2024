// https://neps.academy/br/exercise/64
// Arquivos

#include <bits/stdc++.h>

int main(){
	
	int N,B,file=0;
	std::cin>>N>>B;
	
	int V[N];
	for(int i=0; i<N; i++)
		std::cin>>V[i];
		
	std::sort(V,V+N);
	
	int i=0,j=N-1;
	for(; i<=j; file++){
		if((V[i]+V[j])<=B){
			i++;
			j--;
		}
		else j--;
	}
	
	std::cout<<file<<std::endl;

	return 0;
}
