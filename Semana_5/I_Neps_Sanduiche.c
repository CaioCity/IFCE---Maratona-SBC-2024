// https://neps.academy/br/exercise/60
// Sanduíche

/*
** Esses são alguns recados para vc q está lendo isso
** Já foram gastas cerca de 4h nessa questão
** São exatas 4h da manhã e acabei de levar mais um WA interno, já passou da hora de ninar.
** Nesse arquivo há duas soluções que possuem um considerável grau de semelhança: 
** A 1a é mais inteligente, diria que possui uma implementação mais "delicada". (Está comentada logo abaixo, linha 30)
** Já sobre a 2a, digamos que ela é um pouco mais bruta. (Linha 110)
** Ambas as soluções estão levando WA interno
** Desenvolvi mais 2 casos testes que estarão abaixo dessa seção de recados para te ajudar
** Por último, mas não menos importante, obrigado se vc tiver lido até aqui.
** Que a força esteja com você.
*/

/* Casos testes extras :

20 12
1 3 6 3 5 7 3 8 1 5 2 5 2 4 6 7 2 4 7 5
Resp = 6

30 18
1 8 4 7 2 3 5 6 7 8 2 4 6 7 2 2 1 7 8 4 9 2 11 4 5 3 7 8 4 10
Resp = 4

*/

//Tentativa inteligente que não deu certo pq sim

// #include <stdio.h> 
// #include <stdlib.h>

// int main(){

//     int N,D,sum=0;
//     unsigned long long int answer=0;
//     scanf("%d%d",&N,&D);

//     short int*V=(short int*)calloc(N,sizeof(short int));

//     for(int i=0; i<N; i++)
//         scanf("%hd",V+i);  

//     if(V[0]==D)
//         answer++;  

//     for(int i=0,j=0; j<N; j++){ //caso eu coma pedacos em sequencia
        
//         if(V[j]>=D){
//             j++;
//             i=j;
//             sum=0;
//             continue;
//         }
        
//         sum+=V[j];
        
//         if(sum==D){
//             answer++;
//             sum-=V[i];
//             i++;
//         }
//         else if (sum > D){
//             sum-=(V[i]+V[j]);
//             i++;
//             j--;//cancela o incremento
//         }

//     }

//     if(V[N-1]<=D){ //comendo pelas beiradas
//         sum=V[N-1];
//         int index;

//         for(index=0; sum<D && index<(N-1); index++)
//             sum+=V[index];
//         if(sum==D)
//             answer++;
        
//         index--;
//         sum+=V[N-2];
//         if(sum==D)
//             answer++;
//         for(int j=N-2; index>=0 && j>0; j--){
            
//             if(sum>D){
//                 sum-=V[index];
//                 index--;
//                 j++; //cancela o decremento
//             }
//             else if (sum==D && j>index){
//                 answer++;
//                 sum+=V[j-1];
//             }
//             else /*sum<D*/
//                 sum+=V[j-1];
            
//         }
//     }

//     printf("%llu\n",answer);

//     free(V);
//     return 0;
// }



//Solucao array bruto

#include <stdio.h>
#include <stdlib.h>

int main(){

    int N,D;
    unsigned long long int answer=0;
    scanf("%d%d",&N,&D);

    short int *V,*frente,*tras;

    V=(short int*)calloc(N,sizeof(short int));
    frente=(short int*)calloc(N,sizeof(short int));
    tras=(short int*)calloc(N,sizeof(short int));

    scanf("%d",&V[0]);
    
    frente[0]=V[0];
    for(int i=1; i<N; i++){
        scanf("%hd",V+i); 
        frente[i]=frente[i-1]+V[i];
    }
    tras[N-1]=V[N-1];
    for(int i=(N-2); i>=0; i--){
        tras[i]=tras[i+1]+V[i];
    }

    for(int i=0,tara=0, i_tara=(-1); i<N; i++){ //comendo em sequencia
    // printf("frente[%d] - tara = %d -%d\n",i,frente[i],tara);
        i=(i<i_tara)? i_tara:i;
        if((frente[i]-tara)==D)
            answer++;
        if((frente[i]-tara)>D){
            i_tara++;
            if(i_tara<N)
                tara=frente[i_tara];
            i--;
        }
    }

    // comendo pelas beiradas
    int index;
    for(index=0;frente[index]<D && index<N; index++);
    index--;
    // printf("SAiu index= %d\n",index);
    if((frente[index]+tras[N-1])==D)
        answer++;
    
    for(int j=N-2; index>=0 && j>0; j--){
        // printf("tras[%d]= %d frente[%d]= %d\n",j, tras[j],index,frente[index]);
        if((tras[j]+frente[index]) > D){
            index--;
            j++;
        }
        else if ((tras[j]+frente[index]) == D && j>index)
            answer++;
    }
        
    printf("%llu\n",answer);

    free(V);
    free(frente);
    free(tras);

    return 0;
}
