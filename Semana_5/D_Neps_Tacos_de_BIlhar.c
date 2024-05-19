// https://neps.academy/br/exercise/54
// Tacos de Bilhar
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){

    int N,tam,answer;
    bool* Estoque;
    scanf("%d",&N);

    Estoque=(bool*)calloc(1000000,sizeof(bool));

    while(N--){
        scanf("%d",&tam);
        if(Estoque[tam])
            Estoque[tam]=0;
        else{
            Estoque[tam]=1;
            answer+=2;
        } 
    }

    printf("%d\n",answer);

    return 0;
}
