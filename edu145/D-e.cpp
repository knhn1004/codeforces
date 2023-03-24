#include <bits/stdc++.h>
#include <cassert>
#include <chrono>
#include <ctime>
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
const ll MAX_N = 1e6;

const ll COST = 1e12;

void solve() {
  string s;
  cin >> s;
  int n = s.size();
  if (n == 1) {
    cout << 0 << nline;
    return;
  }
  vector<int> pref1(n + 1,
                    0), // how many 1's so far from the beginning (inclusive)
      suf0(n + 1, 0);   // how many 0's so far from the end (inclusive)
  for (int i = 0; i < n; i++) {
    pref1[i + 1] = pref1[i] + (s[i] == '1');
  }
  for (int i = n - 1; i >= 0; i--) {
    suf0[i] = suf0[i + 1] + (s[i] == '0');
  }

  ll ans = suf0[0] * (COST + 1); // assuming to delete every 0's
  for (int i = 0; i < n; i++) {
    // we can either delete all the 0's or
    // delete all the 1's before index i and delete all the 0's after index i
    ans = min(ans, (pref1[i + 1] + suf0[i + 1]) * (COST + 1));
    if (i + 1 < n && s[i] == '1' && s[i + 1] == '0') {
      // if we have an 10 on index i and i+1, we could also try to swap them
      ans = min(ans, (pref1[i]      // remove all the 1's before i
                      + suf0[i + 2] // remove all the 1's after i + 1
                      ) * (COST + 1) +
                         COST); // swap for i and i + 1
    }
  }
  cout << ans << nline;
}

int main() {
#ifndef ONLINE_JUDGE
  FILE *file = freopen("DEBUG.o", "w", stderr);
  if (file == NULL) {
    fprintf(stderr, "Error: could not open debug file\n");
    exit(EXIT_FAILURE);
  }
  auto start = chrono::high_resolution_clock::now();
#endif
  fastio();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }

#ifndef ONLINE_JUDGE
  auto stop = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
  cerr << "----------------------------------" << endl;
  cerr << "Execution time: " << duration.count() << " milliseconds" << endl;
  auto currentTime =
      chrono::system_clock::to_time_t(chrono::system_clock::now());
  cerr << "Finished at: " << ctime(&currentTime);
#endif
  return 0;
}
