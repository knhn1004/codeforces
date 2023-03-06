/* #include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m; // n = array  size, m = num of queries
  cin >> n;
  vector<int> arr(n, -1);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cin >> m;

  vector<int> queries(m, -1);
  int u = 0, v = 0;
  for (int k = 0; k < m; k++) {
    cin >> queries[k];
    for (int i = 0; i < n; i++) {
      if (queries[k] == arr[i]) {
        u += i + 1;
        v += n - i;
      }
    }
  }
  cout << u << " " << v << endl;

  return 0;
} */
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m; // n = array size, m = num of queries
  cin >> n;
  vector<int> arr(n);
  unordered_map<int, int> indices;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    indices[arr[i]] = i;
  }
  cin >> m;

  long long u = 0, v = 0;
  for (int i = 0; i < m; i++) {
    int q;
    cin >> q;
    if (indices.find(q) != indices.end()) {
      int j = indices[q];
      u += j + 1;
      v += n - j;
    }
  }
  cout << u << " " << v << endl;

  return 0;
}
