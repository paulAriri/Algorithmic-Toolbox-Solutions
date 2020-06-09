#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll get_fibonacci_partial_sum_efficient(ll n){
  ll previous = 0, current = 1, temp;

  // Base case
  if (n == 0) return 0;
  if (n == 1) return 1;

  ll rem = n % 60;
  if(rem == 0) return 0;

  for(ll i = 2; i < rem + 3; i++)
  {
    temp = (previous + current) % 60;
    previous = current;
    current = temp;
  }

  return (current - 1);
}

ll get_fibonacci_partial_sum_naive(ll from, ll to) {
    ll sum = 0;

    ll current = 0;
    ll next  = 1;

    for (ll i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        ll new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, m, temp;
  cin >> n >> m;

  if(n < m){
    temp = n;
    n = m;
    m = temp;
  }

  temp = abs(get_fibonacci_partial_sum_efficient(n) - get_fibonacci_partial_sum_efficient(m - 1));
  cout << temp % 10;
  return 0;
}
