// for each floor to achive min bright rooms,
// we want to combine consecutive 1's as much as possible

// for max bright rooms,
// we want to split consecutive 1's i.e. make as many bright rooms as possible
// we want to make 2-len rooms (10) or (00)

// we have m/4 len-2 rooms and m/2 len-1 rooms
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int m, n;
  cin >> n >> m;
  int mn = 0, mx = 0;
  string s;
  while (n--) {
    cin >> s; // each floor
    int ones = count(s.begin(), s.end(), '1');
    int c1 = 0, c2 = 0; // number of rooms with 2 1's
    for (int j = 0; j < m - 1; j++) {
      if (s[j] == '1' && s[j + 1] == '1') {
        c1++, j++; // we want to minimize rooms, so if possible we make it a
        // 2-len room
      }
    }
    c1 = min(c1, m / 4);

    // if we don't have consecutive 1's make it a 2-len room
    // i.e. make (10) (00) 2-len rooms
    for (int j = 0; j < m - 1; j++) {
      if (s[j] != '1' || s[j + 1] != '1') {
        c2++, j++;
      }
    }
    c2 = max(
        0, // we can't make any 2 len rooms w/ 11
        m / 4 -
            c2); // 2-len rooms w/ 11 = all 2 len rooms - 2len rooms w/ 01 or 00
    // if we can make more than m/4 2-len rooms containing 01 or 00
    // because we want exactly m/4 2-len rooms, we will just do m/4 2-len rooms

    mn += ones - c1;
    mx += ones - c2;
  }
  cout << mn << " " << mx << endl;

  return 0;
}
