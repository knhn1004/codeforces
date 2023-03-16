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
    int x, y;
    cin >> x >> y;

    if (abs(x) == abs(y))
      cout << abs(x) * 2 << endl;
    else {
      cout << max(abs(x), abs(y)) * 2 - 1 << endl;
    }
  }

  return 0;
}
