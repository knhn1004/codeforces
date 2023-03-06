#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int N, x = 0, y = 0, z = 0;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int tx, ty, tz;
    cin >> tx >> ty >> tz;
    x += tx;
    y += ty;
    z += tz;
  }
  bool res = (x == 0) && (y == 0) && (z == 0);
  cout << (res ? "YES" : "NO") << endl;

  return 0;
}
