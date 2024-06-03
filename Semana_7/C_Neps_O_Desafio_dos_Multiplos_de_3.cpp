// https://neps.academy/br/competition/1883/exercise/2704
// O Desafio dos Múltiplos de 3

#include <bits/stdc++.h>

int main(){

    short int sum=0,tam;
    std::string S;

    std::cin>>S;

    tam=S.length();

    for(short int i=0; i<tam; i++)
        sum+=S[i];
    
    if(sum%3!=0)
        std::cout<<"-1\n";
    else{
        std::sort(S.begin(),S.end(),std::greater<short int>());
        std::cout<<S<<'\n';
    }
    
    return 0;
}
