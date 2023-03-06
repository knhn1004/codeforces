#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  queue<pair<int, int>> q;

  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    q.push({i + 1, tmp});
  }

  while (q.size() > 1) {
    pair<int, int> cur = q.front();
    q.pop();
    if (cur.second > m) {
      q.push({cur.first, cur.second - m});
    }
  }
  cout << q.front().first << endl;

  return 0;
}
