// https://neps.academy/br/exercise/72
// Cobra Coral

#include <stdio.h>

int main(){
	
	char a,b,c,d;
	scanf("%c %c %c %c", &a,&b,&c,&d);
	
	printf("%c\n", (a==c || b==d)?'V':'F');	
	
	return 0;
}
