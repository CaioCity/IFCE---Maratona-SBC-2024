// https://neps.academy/br/exercise/2697
// Análise de Texto

#include <iostream>

int main(){

    std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    std::string frase,letras;
    int tam1,tam2,answer=0;
    bool word;

    getline(std::cin, frase);
    std::cin>>letras;
    tam1=frase.length();
    tam2=letras.length();   

    for(int i=0; i<tam1; i++)
        for(int j=0; j<tam2; j++)
            if(frase[i]==letras[j]){
                answer++;
                while(i<tam1){
                    if(frase[i]==' ')
                        break;
                    i++;
                }
                break;
            }
        
    std::cout<<answer<<'\n';

    return 0;
}
