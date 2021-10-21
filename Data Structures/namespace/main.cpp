#include<bits/stdc++.h>
using namespace std;
namespace ghozt {
  int n = 10;
}
namespace test {
  string foo = "foo";
  // you can add functions inside of namespace as well
  void printName(string name){
    cout << "\n" <<"Hello " << name;
    return ;
  }
}
using namespace test;

int main() {
  double n = 20.00;
  cout << n ;
  cout << "\n" << ghozt::n;
  cout << "\n" << foo; 
  printName("ghozt");
  return 0;
}