#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> V(n, vector<int>(m, 0));

  for (int i = 0; i < n; i++) {
    string floor;
    cin >> floor;
    for (int j = 0; j < m; j++) {
      V[i][j] = floor[j] - '0';
    }
  }

  /* for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << V[i][j] << " ";
    }
    cout << endl;
  } */

  // each floor(row) is of length m
  // consists of m/4 len-2 rooms and m/2 len-1 rooms
  // a room is considered a bright room if a room has at least 1 1 in it
  // output min and max possible bright rooms

  int bright_rooms_min = 0, bright_rooms_max = 0;

  for (int i = 0; i < n; i++) {
    int len2_rooms = m / 4;
    int len1_rooms = m / 2;
    if (m % 4 == 2)
      len2_rooms++;
    if (m % 4 == 3)
      len1_rooms++;

    int bright_len2_rooms =
        (i % 2 == 0) ? len2_rooms / 2 : (len2_rooms + 1) / 2;
    int bright_len1_rooms = len1_rooms / 2;

    bool bright_room = false;
    for (int j = 0; j < m; j++) {
      if (V[i][j] == 1) {
        bright_room = true;
        break;
      }
    }
    bright_rooms_min += bright_room ? 1 : 0;
    bright_rooms_max += bright_len2_rooms + bright_len1_rooms;
  }

  cout << bright_rooms_min << " " << bright_rooms_max << "\n";
  return 0;
}
