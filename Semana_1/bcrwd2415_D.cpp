// https://judge.beecrowd.com/en/problems/view/2415
// Problema 2415: Consecutivos

#include <iostream>

int main(){
	
	int N,number,last, seq=1, maiorseq=1;
	
	std::cin>>N>>number;
	last=number;
	
	for(int i=1; i<N; i++){
		std::cin>>number;
		if(number==last){
			seq++;
			if(seq>maiorseq)
				maiorseq=seq;	
		}
		else
			seq=1;
			
		last=number;
	}

	std::cout<<maiorseq<<std::endl;
	
	return 0;
}
