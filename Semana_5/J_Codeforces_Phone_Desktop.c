// https://codeforces.com/contest/1974/problem/A
// Phone Desktop

#include <stdio.h>
#include <math.h>

int main(){

    int t,x,y;
    double n_telas;
    scanf("%d",&t);

    while(t--){
        scanf("%d%d",&x,&y);
        n_telas=ceil(y/2.0);
        y=y&1;
        if( ! y ){
            if(x<= 7*n_telas)
                printf("%.0lf\n",n_telas);
            else 
                printf("%.0lf\n", (n_telas+ceil((x - 7*n_telas)/15.0)));
        }
        else {
            if(x<=(n_telas*7+4))
                printf("%.0lf \n",n_telas);
            else{
                x-=(n_telas*7+4);
                n_telas+=ceil(x/15.0);
                printf("%.0lf\n", n_telas);
            }
        }
    }

    return 0;
}
