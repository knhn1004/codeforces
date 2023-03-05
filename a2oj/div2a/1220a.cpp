// cards
// https://codeforces.com/problemset/problem/1220/A
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n; // length of string
  string s;
  cin >> n >> s;
  int zeros = 0, ones;
  for (char c : s) {
    if (c == 'z')
      zeros++;
  }
  ones = (n - 4 * zeros) / 3;

  while (ones--)
    cout << "1 ";

  while (zeros--)
    cout << "0 ";
  cout << endl;

  return 0;
}
