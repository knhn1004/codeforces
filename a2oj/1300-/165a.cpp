#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, res = 0;
  cin >> n;
  vector<pair<int, int>> coords;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    coords.push_back({x, y});
  }

  for (int i = 0; i < n; i++) {
    int up = 0, down = 0, right = 0, left = 0;

    for (int j = 0; j < n; j++) {
      if (i == j)
        continue;

      int x1 = coords[i].first, x2 = coords[j].first, y1 = coords[i].second,
          y2 = coords[j].second;

      if (x1 == x2 && y1 < y2)
        up++;
      if (x1 == x2 && y1 > y2)
        down++;
      if (y1 == y2 && x1 < x2)
        right++;
      if (y1 == y2 && x1 > x2)
        left++;
    }
    if (up && down && right && left)
      res++;
  }
  cout << res << endl;

  return 0;
}
