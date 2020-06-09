#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll fib(ll n)
{
  ll f[n + 1] = { 0 };
	if (n == 0)
		return 0;
	if (n == 1 || n == 2)
		return (f[n] = 1);

	if (f[n])
		return f[n];

	ll k = (n & 1) ? (n + 1) / 2 : n / 2;

	f[n] = (n & 1) ? (fib(k) * fib(k) + fib(k - 1) * fib(k - 1))
				: (2 * fib(k - 1) + fib(k)) * fib(k);

	return f[n];
}

int fibonacci_sum_squares_efficient(int n)
{
	return (fib(n) * fib(n + 1)) % 10;
}

int fibonacci_sum_squares_naive(ll n) {
    if (n <= 1)
        return n;

    ll previous = 0;
    ll current  = 1;
    ll sum      = 1;

    for (ll i = 0; i < n - 1; ++i) {
        ll tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin >> n;

  cout << fibonacci_sum_squares_efficient(n);
  return 0;
}
