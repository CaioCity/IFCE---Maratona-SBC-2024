// https://neps.academy/br/competition/1883/exercise/2706
// Aeroporto Central

#include <stdio.h>
#include <stdlib.h>

int main(){

    int N,M,u,v;

    scanf("%d %d",&N,&M);

    int *airport = (int*)calloc(N+5, sizeof(int));

    for(int i=0; i<M; i++){
        scanf("%d %d", &u,&v);
        airport[u]++;
    }

    for(int i=1; i<=N; i++)
        if(airport[i]>=(N-1)){
            printf("S\n");
            return 0;
        }
        
    printf("N\n");
    
    return 0;
}
