// https://codeforces.com/problemset/problem/867/A
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  string s;
  cin >> n >> s;
  int S2F = 0; // Seattle to SF
  int F2S = 0; // SF to Seattle
               //
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == 'S' && s[i + 1] == 'F')
      S2F++;
    if (s[i] == 'F' && s[i + 1] == 'S')
      F2S++;
  }
  cout << ((S2F > F2S) ? "YES" : "NO") << endl;

  return 0;
}
