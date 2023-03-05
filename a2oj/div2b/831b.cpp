// https://codeforces.com/problemset/problem/831/B
#include <bits/stdc++.h>
#include <cctype>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int N = 26;
  string layout1, layout2, s1;
  cin >> layout1 >> layout2 >> s1;

  unordered_map<char, char> hm;
  /* for (int i = 0; i < 26; i++) {
    hm[layout1[i]] = layout2[i];
  }
  for (char c : s1) {
    if (isupper(c)) { // upper case
      cout << (char)toupper(hm[towlower(c)]);
    } else if (islower(c)) { // lowercase
      cout << hm[c];
    } else { // other stuff
      cout << c;
    }
  }

  cout << endl; */

  for (int i = 0; i < 26; i++) {
    hm[layout1[i]] = layout2[i];
    hm[toupper(layout1[i])] = toupper(layout2[i]);
  }
  for (char c : s1) {
    if (isalnum(c)) {
      if (isdigit(c)) {
        cout << c;
      } else {
        cout << hm[c];
      }
    } else {
      cout << c;
    }
  }
  cout << endl;

  return 0;
}
