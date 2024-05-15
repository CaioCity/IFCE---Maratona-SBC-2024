// https://neps.academy/br/exercise/499
// Capital

#include <stdio.h>
#include <stdlib.h>

int compara (const void* a, const void* b){
    return (*(short int*)a - *(short int*)b);
}

int main(){
    
    short int V[4];
    scanf("%hd%hd%hd%hd",&V[0],&V[1],&V[2],&V[3]);
    qsort(V,4,sizeof(short int),compara);

    if( (V[0]*V[3]) == (V[1]*V[2]) )
        printf("S\n");
    else 
        printf("N\n");

    return 0;
}
