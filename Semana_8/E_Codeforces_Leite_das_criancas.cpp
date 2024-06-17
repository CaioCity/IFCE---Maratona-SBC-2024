// https://codeforces.com/group/YgJmumGtHD/contest/528947/problem/D
// Leite das crianças

#include <bits/stdc++.h> 

int main(){
    
    std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);

    int N,L;
    std::cin>>N>>L;
    short int array[N];

    for(int i=0; i<N; i++){
        std::cin>>array[i];
        array[i]=100-array[i];
    }
        
    std::sort(array,array+N);

    int i=0,ans=0;
    while(i<N){
        L-=array[i++];
        if(L<0)
            break;
        ans++;
    }

    std::cout<<ans<<'\n';

    return 0;
}
