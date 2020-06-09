#include <bits/stdc++.h>
using namespace std;

#define ll long long

int pisano_period(int m){
  int previous = 0, current = 1, temp;

  for(int i = 0; i < (m * m); ++i){
    temp = previous;
    previous = current;
    current = (temp + current) % m;

    if(previous == 0 && current == 1) return (i + 1);
  }

  return -1;
}
ll get_fibonacci_huge_efficient(ll n, ll m){
  int pisano = (n % pisano_period(m));
  ll previous = 0, current = 1, temp;

  if(pisano == 0) return 0;
  else if(pisano == 1) return 1;

  for(int i = 0; i < pisano - 1; ++i){
    temp = previous;
    previous = current;
    current = (temp + current) % m;
  }

  return current;
}

ll get_fibonacci_huge_naive(ll n, ll m) {
    if (n <= 1)
        return n;

    ll previous = 0;
    ll current  = 1;

    for (ll i = 0; i < n - 1; ++i) {
        ll tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, m;
  cin >> n >> m;

  cout << get_fibonacci_huge_efficient(n, m);
  return 0;
}
