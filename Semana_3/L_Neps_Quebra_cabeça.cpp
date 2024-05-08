// https://neps.academy/br/exercise/70
// Quebra-cabeça

#include <bits/stdc++.h>

typedef struct{
	int Left,Right; 
	char Char; 
}peca;

int binary_search (int target, int inicio, int fim, peca* array);

int cmpfunc (peca a, peca b) {	
    return ( a.Left < b.Left);
}

int main(){
	
	int N,i,j;
	peca* V;
	char* frase;
	scanf("%d",&N);
	
	V=(peca*)calloc(N+2, sizeof(peca));
	frase=(char*)calloc(N+2, sizeof(char));
	
	for(i=0; i<N; i++)
		scanf("%d %c %d", &(V[i].Left), &(V[i].Char), &(V[i].Right));
		
	
	std::sort( V, V+N, cmpfunc);
	
	frase[N]='\0';
	frase[0]=V[0].Char;
	
	for(i=1,j=0; i<N; i++){
		j= binary_search( V[j].Right, 0, N, V); //o index da próxima peca
		frase[i]=V[j].Char;
	}	
		
	printf("%s\n", frase);	
	
	free(V);
	free(frase);
	return 0;
}

int binary_search (int target, int inicio, int fim, peca* array){
	
	int meio=(fim-inicio)/2;

	if((fim-inicio)<2){
		if( array[inicio].Left == target )
			return inicio;
		if( array[fim].Left == target )
			return fim;
	}
	
	if( array[meio].Left == target )
		return meio;
	
	if( array[meio].Left < target )
		return binary_search(target, meio+1, fim, array);

	if( array[meio].Left > target )
		return binary_search(target, inicio, meio-1, array);

	return 0;
}


/*
em C
#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int Left,Right; 
	char Char; 
}peca;

int binary_search (int target, int inicio, int fim, peca* array);

int cmpfunc (const void * a, const void * b) {	
	peca *pa = (peca*)a, *pb= (peca*)b;
    return ( pa->Left - pb->Left);
}

int main(){
	
	int N,i,j;
	peca* V;
	char* frase;
	scanf("%d",&N);
	
	V=(peca*)calloc(N+2, sizeof(peca));
	frase=(char*)calloc(N+2, sizeof(char));
	
	for(i=0; i<N; i++)
		scanf("%d %c %d", &(V[i].Left), &(V[i].Char), &(V[i].Right));
		
	
	qsort( V, N, sizeof(peca), cmpfunc);
	
	frase[N]='\0';
	frase[0]=V[0].Char;
	
	for(i=1,j=0; i<N; i++){
		j= binary_search( V[j].Right, 0, N, V); //o index da próxima peca
		frase[i]=V[j].Char;
	}	
		
	printf("%s\n", frase);	
	
	free(V);
	free(frase);
	return 0;
}

int binary_search (int target, int inicio, int fim, peca* array){
	
	int meio=(fim-inicio)/2;

	if((fim-inicio)<2){
		if( array[inicio].Left == target )
			return inicio;
		if( array[fim].Left == target )
			return fim;
	}
	
	if( array[meio].Left == target )
		return meio;
	
	if( array[meio].Left < target )
		return binary_search(target, meio+1, fim, array);

	if( array[meio].Left > target )
		return binary_search(target, inicio, meio-1, array);

	return 0;
}

o DREAM em C

#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int Left,Right; 
	char Char; 
}peca;

int binary_search (int target, int inicio, int fim, peca** array);

int cmpfunc (const void * a, const void * b) {
	peca **ppa= (peca**)a, **ppb= (peca**) b;
	peca* pa = *ppa, *pb= *ppb;
	
//   return ( *(int*)a - *(int*)b );
   return ( pa->Left - pb->Left);
}

int main(){
	
	int N,i,j;
	peca* V;
	char* frase;
	scanf("%d",&N);
	
	V=(peca*)calloc(N+2, sizeof(peca));
	frase=(char*)calloc(N+2, sizeof(char));
	
	peca** pointers;
	pointers=(peca**)calloc(N+1, sizeof(peca*));
	
	for(i=0; i<N; i++){
		scanf("%d %c %d", &(V[i].Left), &(V[i].Char), &(V[i].Right));
		pointers[i]=&V[i];
	}
	
	qsort( pointers, N, sizeof(peca), cmpfunc);
//	for(i=0; i<N; i++)
//		for(j=i+1; j<N; j++)
//			if( (*pointers[j]).Left < (*pointers[i]).Left ){
//				peca* aux = pointers[i];
//				pointers[i]=pointers[j];
//				pointers[j]=aux;
//			}
	
	frase[N]='\0';
	frase[0]=(*pointers[0]).Char;
	
	for(i=1,j=0; i<N; i++){
		j= binary_search( (*pointers[j]).Right, 0, N, pointers); //o index da próxima peca
		frase[i]=(*pointers[j]).Char;
	}	
		
	printf("%s\n", frase);	
	
	free(V);
	free(pointers);
	free(frase);
	return 0;
}

int binary_search (int target, int inicio, int fim, peca** array){
	
	int meio=(fim-inicio)/2;

	if((fim-inicio)<2){
		if( (*array[inicio]).Left == target )
			return inicio;
		if( (*array[fim]).Left == target )
			return fim;
	}
	
	if( (*array[meio]).Left == target )
		return meio;
	
	if( (*array[meio]).Left < target )
		return binary_search(target, meio+1, fim, array);

	if( (*array[meio]).Left > target )
		return binary_search(target, inicio, meio-1, array);

	return 0;
}
*/
