// https://neps.academy/br/exercise/51
// Jogo de Par ou Ímpar
#include <bits/stdc++.h>

using namespace std;

int p,d1,d2;

int main() {

  cin>>p>>d1>>d2;

  d1+=d2;
  if(p==0){
    if(d1%2==0){
      cout<<"0"<<endl;
    }else{
      cout<<"1"<<endl;
    }
  }else{
    if(d1%2==0){
      cout<<"1"<<endl;
    } else{
      cout<<"0"<<endl;
    }
  }
    return 0;
}
