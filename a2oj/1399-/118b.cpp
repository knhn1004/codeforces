#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, k = -1;
  cin >> n;
  for (int r = 0; r <= 2 * n; r++) {
    bool printedNonSpace = false; // flag to keep track of whether a non-space
                                  // character has been printed in this row
    for (int c = 0; c <= 2 * n; c++) {
      k = n - abs(n - r) - abs(n - c);

      if (k >= 0) {
        cout << k << " ";
        printedNonSpace =
            true; // set the flag to true when a non-space character is printed
      } else if (!printedNonSpace) { // print spaces until the first non-space
                                     // character is printed
        cout << "  ";
      }
      k = -1;
    }
    cout << endl;
  }

  return 0;
}
