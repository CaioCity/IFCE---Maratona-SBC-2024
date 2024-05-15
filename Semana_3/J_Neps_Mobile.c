// https://neps.academy/br/exercise/50
// Mobile

#include <stdio.h>

int main(){
	
	short int a,b,c,d;
	
	scanf("%hd%hd%hd%hd",&a,&b,&c,&d);
	
	printf("%c\n", (b==c && (b+c)==d && a==(b+c+d))?'S':'N');
	
	return 0;
}
