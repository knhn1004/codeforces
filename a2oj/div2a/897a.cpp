#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  string s;

  cin >> n >> m;
  cin >> s;

  while (m--) {
    int l, r;
    char c1, c2;
    cin >> l >> r >> c1 >> c2;

    string tmp = s.substr(l - 1, r - l + 1);
    for (int i = 0; i < tmp.size(); i++) {
      if (tmp[i] == c1) {
        tmp[i] = c2;
      }
    }
    s.replace(l - 1, r - l + 1, tmp);
  }

  cout << s << endl;

  return 0;
}
