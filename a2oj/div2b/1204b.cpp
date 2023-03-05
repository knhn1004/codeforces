#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, l, r;
  cin >> n >> l >> r;

  // number can only be 2^n while n>=0
  // must start from 1, 2, 4 (can have duplicates)
  // l: min distinct numbs, r: max distinct nums
  // min number: 2^(l-1)
  // max number: 2^(r-1)
  // WANT:
  // min and max sum of all elements in the array

  // min: 1->2->2^(l-1) + rest of 1's
  // max: 1->2->2^(r-1) + rest of 2^(r-1)'s

  int min_ans = pow(2, l) - 1 + (n - l);
  int max_ans = pow(2, r) - 1 + (n - r) * pow(2, r - 1);
  cout << min_ans << " " << max_ans;

  return 0;
}
