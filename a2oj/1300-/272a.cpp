#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int friends, sum = 0, ans = 0;
  cin >> friends;
  for (int i = 0; i < friends; i++) {
    int tmp;
    cin >> tmp;
    sum += tmp;
  }

  // (fingers + x)%(friends+1)!=1
  // where x = 1~5
  for (int x = 1; x <= 5; x++) {
    if ((sum + x) % (friends + 1) != 1) {
      ans++;
    }
  }
  cout << ans << endl;

  return 0;
}
