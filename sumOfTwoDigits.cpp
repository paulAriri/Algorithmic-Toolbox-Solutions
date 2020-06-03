#include <iostream>
using namespace std;

int sumOfTwoDigits(int x, int y){
  return (x + y);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b;
  cin >> a >> b;

  cout << sumOfTwoDigits(a, b);

  return 0;
}
