// https://neps.academy/br/exercise/52
// Lampadas
#include <bits/stdc++.h>

using namespace std;

int N,C,A,i1,i2;;

int main(){
  
  std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

  for(cin>>N; 0<N; N--){
    cin>>C;
    if (C==1)
      i1++;
    else
      i2++;
  }
  
  A=i1+i2;
  
  cout<<A%2<<endl;
  cout<<i2%2<<endl;
  
  return 0;
}
