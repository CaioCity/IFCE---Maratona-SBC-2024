// https://neps.academy/br/exercise/2698
// Colheita

// Duas soluções (a ideia é a mesma, primeira apenas está mais otimizada)

// Primeira:
#include <stdio.h>
#include <stdlib.h>

int main(){

    short int N,M,maximo=0,aux;
    scanf("%hd%hd",&N,&M);

    short int *maior_da_linha=calloc(N,sizeof(short int)), *maior_da_coluna=calloc(M,sizeof(short int));
    short int terra[N][M], saldo_ao_sair[N][M];
    
    for(short int i=0; i<N; i++)
        for(short int j=0; j<M; j++){
            scanf("%hd",&terra[i][j]);
            saldo_ao_sair[i][j]=(-1)*terra[i][j];
        }

    for(short int i=0; i<N; i++)
        maior_da_linha[i]=(-1)*terra[i][0];
    for(short int j=0; j<M; j++)
        maior_da_coluna[j]=(-1)*terra[0][j];
        
    for(short int i=0; i<N; i++)
        for(short int j=0; j<M; j++){
            
            if(saldo_ao_sair[i][j]<maior_da_coluna[j])
                saldo_ao_sair[i][j]=maior_da_coluna[j];
          
            if(((-1)*terra[i][j])<maior_da_linha[i] && saldo_ao_sair[i][j]<maior_da_linha[i])
                saldo_ao_sair[i][j]=maior_da_linha[i];

            if(saldo_ao_sair[i][j]>maior_da_coluna[j])
                maior_da_coluna[j]=saldo_ao_sair[i][j];
            if(saldo_ao_sair[i][j]>maior_da_linha[i])
                maior_da_linha[i]=saldo_ao_sair[i][j];
        }
        
    for(short int i=0; i<N; i++)
        for(short int j=0; j<M; j++)    
            if( (saldo_ao_sair[i][j] + terra[i][j]) > maximo && saldo_ao_sair[i][j]!=((-1)*terra[i][j]) )
                maximo= saldo_ao_sair[i][j]+terra[i][j];
                     
    printf("%hd\n",maximo);
    
    return 0;
}

// Segunda:
#include <stdio.h>
#include <stdlib.h>

int main(){

    short int N,M,maximo=0,aux;
    scanf("%hd%hd",&N,&M);

    short int terra[N][M], saldo_ao_sair[N][M];
    
    for(short int i=0; i<N; i++)
        for(short int j=0; j<M; j++){
            scanf("%hd",&terra[i][j]);
            saldo_ao_sair[i][j]=(-1)*terra[i][j];
        }
        
    for(short int i=0; i<N; i++)
        for(short int j=0; j<M; j++){
            aux=0;
            for(short a=i-1; a>=0; a--)
                if(terra[i][j]>saldo_ao_sair[a][j])
                    aux= aux>(saldo_ao_sair[a][j]+terra[i][j])? aux : (saldo_ao_sair[a][j]+terra[i][j]);
                saldo_ao_sair[i][j]=aux-terra[i][j];
            aux=0;
            for(short b=j-1; b>=0; b--)
                if(terra[i][j]>saldo_ao_sair[i][b])
                    aux= aux>(saldo_ao_sair[i][b]+terra[i][j])? aux : (saldo_ao_sair[i][b]+terra[i][j]);
                saldo_ao_sair[i][j]= saldo_ao_sair[i][j]>(aux-terra[i][j])? saldo_ao_sair[i][j] : (aux-terra[i][j]);
        }

    for(short int i=0; i<N; i++)
        for(short int j=0; j<M; j++)    
            if( (saldo_ao_sair[i][j] + terra[i][j]) > maximo)
                maximo= saldo_ao_sair[i][j]+terra[i][j];
            
    printf("%hd\n",maximo);
    
    return 0;
}
