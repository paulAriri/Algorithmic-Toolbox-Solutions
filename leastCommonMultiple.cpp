#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll gcd_efficient(int x, int y){
  if(y == 0) return x;

  return gcd_efficient(y, (x % y));
}

ll lcm_efficient(int a, int b){
  ll gcd;
  if(a > b) gcd = gcd_efficient(a, b);
  else gcd = gcd_efficient(b, a);

  return (a / gcd) * b;
}

ll lcm_naive(int a, int b) {
  for (ll l = 1; l <= (ll) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (ll) a * b;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b;
  cin >> a >> b;

  cout << lcm_efficient(a, b);
  return 0;
}
