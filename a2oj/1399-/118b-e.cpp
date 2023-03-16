#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  int width = 2 * n + 1;

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < n - i; j++) {
      cout << "  ";
    }
    for (int j = 0; j <= i; j++) {
      cout << setw(2) << j << " ";
    }
    for (int j = i - 1; j >= 0; j--) {
      cout << setw(2) << j << " ";
    }
    cout << endl;
  }

  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < n - i; j++) {
      cout << "  ";
    }
    for (int j = 0; j <= i; j++) {
      cout << setw(2) << j << " ";
    }
    for (int j = i - 1; j >= 0; j--) {
      cout << setw(2) << j << " ";
    }
    cout << endl;
  }

  return 0;
}
