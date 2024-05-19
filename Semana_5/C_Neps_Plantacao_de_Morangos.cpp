// https://neps.academy/br/exercise/53
// Plantação de Morangos
#include <iostream>

using namespace std;

int main(){

  std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

  int D1A, D2A , D1B ,D2B;

  cin>>D1A>>D2A>>D1B>>D2B;

  if((D1A*D2A)>(D1B*D2B))
    cout<<(D1A*D2A)<<endl;
  else
    cout<<(D1B*D2B)<<endl;

  return 0;
}
