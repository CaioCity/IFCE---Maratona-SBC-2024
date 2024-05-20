// https://neps.academy/br/exercise/60
// Sanduíche

/*
** Esses são alguns recados para vc q está empenhado a resolver/entender essa questão
** Já foram gastas cerca de 4h nessa questão
** São exatas 4h da manhã e acabei de levar mais um WA interno, já passou da hora de ninar.
** Nesse arquivo há duas soluções que possuem um considerável grau de semelhança: 
** A 1a é mais inteligente, diria que possui uma implementação mais "delicada". (Está comentada logo abaixo, linha 30)
** Já sobre a 2a, digamos que ela é um pouco mais bruta. (Linha 110)
** Ambas as soluções estão levando WA interno
** Desenvolvi mais alguns casos testes que estarão abaixo desses recados para te ajudar (foram diferenciais para o meu sucesso)
** Por último, mas não menos importante, obrigado se vc tiver lido até aqui.
** Que a força esteja com você.
*/

/* Atualização:
** São 11:30 da manhã, após algumas poucas horas de sono, voltei minhas energias novamente para essaa questão
** Após criar mais casos testes, consegui levar a solução 1 ao accepted, oo objetivo foi alcançado.
** Ao todo, foram gastas umas 6h para tal feito. Restam algumas reflexões... Essa questão era da 1a fase da OBI N2 . . .
** Por fim, agradeço pela conquista. Espero que este arquivo sirva a você, que possui uma longa caminhada pela frente.
** Em frente, persevere!
*/

/* Casos testes extras :

20 12
1 3 6 3 5 7 3 8 1 5 2 5 2 4 6 7 2 4 7 5
Resp = 6

30 18
1 8 4 7 2 3 5 6 7 8 2 4 6 7 2 2 1 7 8 4 9 2 11 4 5 3 7 8 4 10
Resp = 4

Esse foi crucial para a vitória...
7 3
1 2 3 2 1 2 1
Resp 5

12 6
2 1 1 2 16 4 1 15 1 10 8 4
Resp = 2

*/

#include <stdio.h> 
#include <stdlib.h>

int main(){

    int N,D,sum=0;
    unsigned long long int answer=0;
    scanf("%d%d",&N,&D);

    short int*V=(short int*)calloc(N,sizeof(short int));

    for(int i=0; i<N; i++)
        scanf("%hd",V+i);  

    if(V[0]==D)
        answer++;  

    for(int i=0,j=0; j<N; j++){ //caso eu coma pedacos em sequencia
        
        if(V[j]>=D){
            if(V[j]==D)
                answer++;
            i=j+1;
            sum=0;
            continue;
        }
        
        sum+=V[j];
        
        if(sum==D){
            answer++;
            sum-=V[i];
            i++;
        }
        else if (sum > D){
            sum-=(V[i]+V[j]);
            i++;
            j--;//cancela o incremento
        }
    }

    if(V[N-1]<=D){        //comendo pelas beiradas
        sum=V[N-1];
        int index;

        for(index=0; sum<D && index<(N-1); index++)
            sum+=V[index];
        if(sum==D)
            answer++;
        
        index--;
        sum+=V[N-2];
        if(sum==D)
            answer++;
        for(int j=N-2; index>=0 && j>0; j--){
            
            if(sum>D){
                sum-=V[index];
                index--;
                j++; //cancela o decremento
            }
            else if (sum==D && j>index){
                answer++;
                sum+=V[j-1];
            }
            else /*sum<D*/
                sum+=V[j-1];
        }
            
    }

    printf("%llu\n",answer);

    free(V);
    return 0;
}

// Tentativa inteligente que deu certo (com alguns debugs)

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
//             if(V[j]==D)
//                 answer++;
//             i=j+1;
//             sum=0;
//             continue;
//         }
        
//         sum+=V[j];
//         // printf("sum= %d i= %d j=%d ",sum,i,j);
        
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
//         // printf("answer= %d\n",answer);
//     }

//     if(V[N-1]<=D){//comendo pelas beiradas
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


// 2a tentativa: Um pouco mais de força bruta

// #include <stdio.h>
// #include <stdlib.h>

// int main(){

//     int N,D;
//     unsigned long long int answer=0;
//     scanf("%d%d",&N,&D);

//     short int *V,*frente,*tras;

//     V=(short int*)calloc(N,sizeof(short int));
//     frente=(short int*)calloc(N,sizeof(short int));
//     tras=(short int*)calloc(N,sizeof(short int));

//     scanf("%d",&V[0]);
    
//     frente[0]=V[0];
//     for(int i=1; i<N; i++){
//         scanf("%hd",V+i); 
//         frente[i]=frente[i-1]+V[i];
//     }
//     tras[N-1]=V[N-1];
//     for(int i=(N-2); i>=0; i--){
//         tras[i]=tras[i+1]+V[i];
//     }

//     for(int i=0,tara=0, i_tara=(-1); i<N; i++){ //comendo em sequencia
//     // printf("frente[%d] - tara = %d -%d\n",i,frente[i],tara);
//         i=(i<i_tara)? i_tara:i;
//         if((frente[i]-tara)==D)
//             answer++;
//         if((frente[i]-tara)>D){
//             i_tara++;
//             if(i_tara<N)
//                 tara=frente[i_tara];
//             i--;
//         }
//     }

//     // comendo pelas beiradas
//     int index;
//     for(index=0;frente[index]<D && index<N; index++);
//     index--;
//     // printf("SAiu index= %d\n",index);

//     for(int i=index; i>=0; i--)
//         if((frente[i]+tras[N-1])==D)
//         answer++;
    
//     for(int j=N-2; index>=0 && j>0; j--){
//         // printf("tras[%d]= %d frente[%d]= %d\n",j, tras[j],index,frente[index]);
//         if((tras[j]+frente[index]) > D){
//             index--;
//             j++;
//         }
//         else if ((tras[j]+frente[index]) == D && j>index)
//             answer++;
//     }
        
//     printf("%llu\n",answer);

//     free(V);
//     free(frente);
//     free(tras);

//     return 0;
// }
