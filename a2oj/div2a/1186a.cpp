#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m, k;
  cin >> n >> m >> k;
  if (min(m, k) < n) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }

  return 0;
}
