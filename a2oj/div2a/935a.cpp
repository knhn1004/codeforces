#include <bits/stdc++.h>
using namespace std;

int divisors(int n) {
  bool hash[n + 1];
  memset(hash, true, sizeof(hash));
  for (int p = 2; p * p < n; p++) {
    if (hash[p]) {
      for (int i = p * 2; i < n; i += p) {
        hash[i] = false;
      }
    }
  }

  int total = 1;
  for (int p = 2; p <= n; p++) {
    if (hash[p]) {
      int count = 0;
      if (n % p == 0) {
        while (n % p == 0) {
          n /= p;
          count++;
        }
        total *= (count + 1);
      }
    }
  }
  return total;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int x;
  cin >> x;
  cout << divisors(x) - 1 << endl;

  return 0;
}
