#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll fibonacci_sum_efficient(ll n){
  n = (n + 2) % 60;
  int dp[n + 1];
  dp[0] = 0; dp[1] = 1;

  for(int i = 2; i <= n; ++i){
      dp[i] = (dp[i - 1] % 10 + dp[i - 2] % 10) % 10;
  }

  if(dp[n] == 0) return 9;
  return ((dp[n] % 10) - 1);
}

int fibonacci_sum_naive(ll n) {
  if (n <= 1)
      return n;

  ll previous = 0;
  ll current = 1;
  ll sum = 1;

  for (ll i = 0; i < n - 1; ++i) {
      ll tmp_previous = previous;
      previous = current;
      current = tmp_previous + current;
      sum += current;
  }

  return sum % 10;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin >> n;

  cout << fibonacci_sum_efficient(n);
  return 0;
}
