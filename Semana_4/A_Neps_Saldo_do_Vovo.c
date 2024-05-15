// https://neps.academy/br/exercise/332
// Saldo do vovo

#include <stdio.h>

int main(){
    
    short int N,mov;
    int S;

    scanf("%hd%d",&N,&S);
    
    int min=S;
    while(N--){
        scanf("%hd",&mov);
        S+=mov;
        min= (min<S)? min : S;
    }

    printf("%d\n",min);
   
    return 0;
}
