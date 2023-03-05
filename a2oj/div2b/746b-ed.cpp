#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N;
  string s;
  cin >> N >> s;

  // if n == odd
  // add one to end, then begining and so on
  // if n == even
  // add one to begin, then end, and so on
  vector<char> output;
  int i = 0;
  while (N) {
    if (N % 2 == 1) { // add to end
      output.push_back(s[i++]);
    } else {
      output.insert(output.begin(), s[i++]);
    }
    N--;
  }
  for (char c : output) {
    cout << c;
  }
  cout << endl;
  return 0;
}
