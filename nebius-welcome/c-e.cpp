#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;

  while (t--) {
    ll n, x, p;
    cin >> n >> x >> p;
    // x + f * (f+1) / 2 = 0 (mod n) // from 1 to f
    // equivalent to x + (f+2n) * (f+2n+1)/2 = 0 (mod n) // from 1 to f+2n
    // try values from 1 to min (2n, p);
    int max_try = min(2 * n, p);
    bool found = false;
    for (ll f = 1; f <= max_try; f++) {
      if ((x + (f + 2 * n) * (f + 2 * n + 1) / 2) % n == 0) {
        found = true;
      }
    }
    cout << (found ? "Yes" : "No") << endl;
  }

  return 0;
}
