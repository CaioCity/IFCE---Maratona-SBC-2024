// https://neps.academy/br/exercise/385
// Triangulo

#include <bits/stdc++.h>

int main(){
	
	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	
	short int V[4];
	for(int i=0; i<4; i++)
		std::cin>>V[i];
	
	std::sort(V,V+4);
	
	
	if(V[0]>(V[2]-V[1]) || V[3]<(V[1]+V[2]))
		std::cout<<"S\n";
	else
		std::cout<<"N\n";
	return 0;
}
