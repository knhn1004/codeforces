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

int main() {
#ifndef ONLINE_JUDGE
  freopen("DEBUG.o", "w", stderr);
#endif
  fastio();

  ll n;
  cin >> n;
  // state: min cost of having mask(vitamins) until ith string(juice)
  /* ll f[n + 1][8];
  fill(&f[0][0], &f[0][0] + (n + 1) * 8, INF); */
  vector<vector<ll>> f(n + 1, vector<ll>(8, INF));

  f[0][0] = 0; // base case: min cost of having nothing until no string is 0

  for (ll i = 0; i < n; i++) { // n kinds of juice
    ll cost;
    string s; // some A, B, C
    cin >> cost >> s;
    int string_mask = 0; // mask containing A, B, C = 4 + 2 + 1

    for (int pos = 0; pos < 3; pos++) {
      char c = 'C' - pos;
      if (count(s.begin(), s.end(), c)) {
        string_mask += (1 << pos); // 2^pos
      }
    }

    for (ll mask = 0; mask < 8; mask++) {
      // transition

      // the best answer for now before considering buying
      f[i + 1][mask] = min(f[i][mask], f[i + 1][mask]);

      // whether to pick the juice or not
      f[i + 1][mask | string_mask] =
          min(f[i + 1][mask | string_mask], // 1.some how already have a better
                                            // answer for this state
              f[i][mask] + cost);           // buy this juice
    }
  }

  ll ans = f[n][7];
  cout << (ans == INF ? -1 : ans) << endl;

  return 0;
}
