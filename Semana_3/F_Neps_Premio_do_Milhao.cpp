// https://neps.academy/br/exercise/48
// Premio do milhao

#include <iostream>

using namespace std;

int main() {
  
  int N,A,AT;

  cin>>N;
  N=0;
  AT=0;
  while (AT<1000000){  
  cin>>A;
  AT+=A;
  N++;
  }
  cout<<N<<endl;
  return 0;
}
