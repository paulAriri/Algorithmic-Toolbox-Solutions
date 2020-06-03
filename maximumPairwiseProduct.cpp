#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll maxPairwiseProduct(int arr[], int n){
  int max = -1;
  for(int i = 0; i < n; ++i){
    if(arr[i] > arr[max] || max == -1) max = i;
  }

  int max2 = -1;
  for(int i = 0; i < n; ++i){
    if((arr[i] > arr[max2] || max2 == -1) && i != max) max2 = i;
  }

  return (ll)arr[max] * arr[max2];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  int arr[n];
  for(int i = 0; i < n; ++i){
    cin >> arr[i];
  }

  cout << maxPairwiseProduct(arr, n);
  return 0;
}
