// https://neps.academy/br/exercise/500
// Corrida

#include <stdio.h>
#include <stdlib.h>

int main(){
    
    short int N1,N2,D,V;
    float time1;

    scanf("%hd%hd%hd",&N1,&D,&V);
    time1=D*1.0/V;

    scanf("%hd",&N2);
    scanf("%hd%hd",&D,&V);
    printf("%hd\n", ((D*1.0/V) < time1)?N2:N1);
        
    return 0;
}
