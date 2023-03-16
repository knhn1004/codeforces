#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, k, d, w;
    cin >> n >> k >> d >> w;
    // the number of patients,
    // the number of doses per vaccine pack,
    // the number of moments of time the vaccine can live outside the fridge,
    // and the number of moments of time each of the patients can wait
    vector<int> times(n);
    for (int i = 0; i < n; i++)
      cin >> times[i];

    // the minimum number of vaccine packs required to vaccinate all n patients
  }

  return 0;
}
