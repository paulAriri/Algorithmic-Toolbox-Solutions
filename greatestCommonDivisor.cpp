#include <bits/stdc++.h>
using namespace std;

int gcd_efficient(int x, int y){
  if(y == 0) return x;

  return gcd_efficient(y, (x % y));
}

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int x, y;
  cin >> x >> y;

  cout << gcd_efficient(x, y);
  return 0;
}
