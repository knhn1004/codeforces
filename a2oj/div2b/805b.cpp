#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  // given n
  // using only a, b, c
  // min number of c's'
  // no substring of length 3 being palindrome
  // provide any possible solution

  int N;
  cin >> N;
  // just generate aabbaabb... and so on
  for (int i = 0; i < N; i++) {
    cout << ((i & 2) ? 'a' : 'b');
  }
  cout << endl;

  return 0;
}
