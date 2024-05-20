// https://neps.academy/br/exercise/59
// Lâmpadas do Hotel
#include <stdio.h>

int main(){

    short int ia,ib,fa,fb,answer=0;
    scanf("%hd%hd%hd%hd",&ia,&ib,&fa,&fb);
    
    if(ib==fb){
        if(ia!=fa)
            answer++;
    } else {
        answer++;
        ia++;
        if (ia%2 != fa)
            answer++;
    }

    printf("%hd\n",answer);

    return 0;
}
