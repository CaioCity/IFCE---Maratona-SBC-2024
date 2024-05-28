// https://neps.academy/br/exercise/2696
// Crescimento da Floresta

#include <stdio.h>

int main(){

    int T,M,A,n=0;

    scanf("%d%d%d",&T,&M,&A);

    while(T<A){
        T*=(1+M);
        n++;
    }

    printf("%d\n",n);
    
    return 0;
}
