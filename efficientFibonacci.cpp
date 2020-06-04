#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll efficientFib(int n){
  ll dp[n + 1];
  dp[0] = 0; dp[1] = 1;

  for(int i = 2; i <= n; ++i){
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  return dp[n];
}

int naiveFibonacci(int n){
  if(n <= 1) return n;

  return naiveFibonacci(n - 1) + naiveFibonacci(n - 2);
}

void test_solution() {
    assert(efficientFib(3) == 2);
    assert(efficientFib(10) == 55);

    for (int n = 0; n < 20; ++n)
        assert(efficientFib(n) == naiveFibonacci(n));
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  cout << efficientFib(n);
  return 0;
}
