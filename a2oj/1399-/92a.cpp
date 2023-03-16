#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  int i = 1;
  while (m >= i) {
    m -= i;
    if (i == n)
      i = 1;
    else
      i++;
  }
  cout << m << endl;

  return 0;
}
