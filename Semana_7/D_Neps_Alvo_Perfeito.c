// https://neps.academy/br/competition/1883/exercise/2705
// Alvo perfeito

#include <stdio.h>

int main(){

    int N,S;

    scanf("%d %d",&N,&S);

    int V[N];
    scanf("%d", V);

    if(V[0]==S){
        printf("S\n");
        return 0;
    }

    for(int i=1; i<N; i++){
        scanf("%d",&V[i]);
        V[i]+=V[i-1];
    }

    for(int i=0,j=1; j<N; ){

        j=(j<i)? i : j;
        
        if(i>0){
            if((V[j]-V[i-1])==S){
                printf("S\n");
                return 0;
            }
            else if ((V[j]-V[i-1]) < S)
                j++;
            else if ((V[j]-V[i-1]) > S)
                i++;
        }
        else {
            if(V[j]==S){
                printf("S\n");
                return 0;
            }
            else if(V[j]<S)
                j++;
            else if( V[j]>S )
                i++;
        }
    }

    printf("N\n");

    return 0;
}
