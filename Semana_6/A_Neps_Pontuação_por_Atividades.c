// https://neps.academy/br/exercise/2695
// Pontuação por atividades

#include <stdio.h>

int main(){

    int E,A,C,points;

    scanf("%d%d%d",&E,&A,&C);

    points=E*2+A*3+C*5;

    if(points>=200)
        printf("O\n");
    else if(points>=150)
        printf("S\n");
    else if(points>=100)
        printf("B\n");
    else
        printf("N\n");

    return 0;
}
