// https://neps.academy/br/competition/1883/exercise/2703
// Extremos de uma sequência

#include <stdio.h>

int main(){

    short int a=0,b=101,aux;

    for(short int i=0; i<4; i++){
        scanf("%hd",&aux);
        b= (b<aux)? b : aux;
        a= (a>aux)? a : aux;
    }

    printf("%hd\n",a+b);

    return 0;
}
