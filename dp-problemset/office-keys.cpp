#include <bits/stdc++.h>
using namespace std;

#define fastio()                                                               \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)
#define MOD 1e9 + 7
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#define LOG(x)                                                                 \
  cerr << #x << ": ";                                                          \
  _print(x);                                                                   \
  cerr << endl;
#else
#define LOG(x)
#endif

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V> void _print(pair<T, V> p);
template <class T> void _print(vector<T> v);
template <class T> void _print(set<T> v);
template <class T, class V> void _print(map<T, V> v);
template <class T> void _print(multiset<T> v);
template <class T, class V> void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.ff);
  cerr << ",";
  _print(p.ss);
  cerr << "}";
}
template <class T> void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T> void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T> void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V> void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
const ll MAX_N = 1e9;

int main() {
  fastio();
  // PUSH DP: dp(pos, last) -> dp(pos+1, last+1)
  //
  // from dp(pos, last) -> two transitions: take or not
  // take-> dp(pos+1, last+1)
  // not -> dp(pos+1, last)
  // BASE CASE: dp(0, 0) = 0, dp(*, *) = INF
  //
  // state dp(i, n) = min cost of at ith position and have n people covered
  // final state = min of all dp(i, n)
  ll n, k, p;
  cin >> n >> k >> p;
  vector<ll> a(n);
  vector<ll> b(k);
  for (ll i = 0; i < n; i++)
    cin >> a[i]; // people positions
  sort(all(a));

  for (ll i = 0; i < k; i++)
    cin >> b[i]; // key positions
  sort(all(b));

  // state dp(i, j) = min cost of at ith position and have j people covered
  vector<vector<ll>> dp(k + 1, vector<ll>(n + 1, INF));
  dp[0][0] = 0;

  for (ll i = 0; i < k; i++) {
    for (ll j = 0; j <= n; j++) {
      // don't take the person
      dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
      // take the person
      if (j < n) {
        dp[i + 1][j + 1] = min(dp[i + 1][j + 1],
                               max(dp[i][j], abs(a[j] - b[i]) + abs(b[i] - p)));
        // cost = dist. of person to key + dist. of key to office
      }
    }
  }
  cout << dp[k][n] << endl;

  return 0;
}
