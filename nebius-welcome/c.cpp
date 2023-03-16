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
    int n, x, p;
    cin >> n >> x >> p;

    int ans = -1;
    for (int k = 1; k <= p; k++) {
      if ((k * (k + 1) / 2 + x) % n == 0) {
        ans = k;
        break;
      }
    }

    if (ans == -1) {
      cout << "No\n";
    } else {
      cout << "Yes\n";
    }
  }
  return 0;
}
