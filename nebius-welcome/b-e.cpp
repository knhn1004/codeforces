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
    // n - number of patients,
    // k - number of doses per pack
    // d - duration each pack can live
    // w - max wait time for each patient

    cin >> n >> k >> d >> w;
    int ans = 0;
    vector<int> times(n);
    for (int i = 0; i < n; i++) {
      cin >> times[i];
    }

    // simulate the process and let each patient wait as long as possible
    // because we want to minimize packs
    int cur_doses = 0, exp_time = 0;
    for (int i = 0; i < n; i++) {
      int max_time =
          times[i] +
          w; // latest time for this particular patient to receive dose
      if (cur_doses == 0 ||
          exp_time < times[i]) { // no doses for this particular patient when
                                 // it's his turn
        ans++;                   // open another pack
        // cur_doses += k;
        cur_doses =
            k; // clean all the existing doses, and use packs from a new pack
        exp_time = max_time + d;
        // exp_time = max_time + d + 1;
      }
      cur_doses--; // consume a dose
    }
    cout << ans << endl;
  }

  return 0;
}
