#include <iostream>

int binary_search (int target, int inicio, int fim, int* R);

int main(){

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    int C,T,Tx,Ty,Points=0;
    std::cin>>C>>T;

    int R[C];

    for(int i=0; i<C; i++){
        std::cin>>R[i];
        R[i]*=R[i];
    }   

    std::cout<<"Raios^2 = ";
    for(int i:R)
        std::cout<<i<<" ";
    std::cout<<std::endl;
        
    while(T--){
        std::cin>>Tx>>Ty;
        int dist = Tx*Tx + Ty*Ty;
        
    if(dist>R[0]){
        int N_circles = binary_search(dist, 0, C-1, R);
        Points+= N_circles;
    }  
        
    }   

    std::cout<<Points<<std::endl;

    return 0;
}

int binary_search (int target, int inicio, int fim, int* R){

    if( (fim-inicio)<2 ){
        if( target == R[fim] || target > R[inicio])
            return fim;
        if( target == R[inicio] || target > R[inicio-1] )
            return inicio;
        return (inicio-1); 
    }

    int meio = (inicio+fim)/2;
    if( target <= R[meio] && R[meio-1] < target )
        return meio;
    if( target > R[meio] )
        return binary_search(target,meio+1, fim, R);
    
    return binary_search(target,inicio,meio-1, R);
}
