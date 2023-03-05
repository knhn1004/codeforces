// https://codeforces.com/problemset/problem/967/B
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N, poured, target, ans = 0;
  cin >> N >> poured >> target;
  vector<int> sizes(N, 0);
  // sizes.reserve(N) didn't work

  int sum = 0;
  for (int i = 0; i < N; i++) {
    cin >> sizes[i];
    sum += sizes[i];
  }

  // WE WANT:
  // poured*sizes[0] / (sum -(sum_of_blocked_holes)) >= target
  // minimize blocked holes
  // OR
  // poured*sizes[0] / sum_of_non_blocked_holes >= target
  // maximize non blocked holes

  // sorting + greedy?
  sort(sizes.begin() + 1, sizes.end(),
       [](int a, int b) { return a > b; }); // DESC
  int i = 1;
  while (poured * sizes[0] / sum < target) { // while invalid technique
    ans++;
    sum -= sizes[i++];
  }

  cout << ans << endl;
  return 0;
}
