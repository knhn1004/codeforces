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
const ll MAX_N = 1e6;

int main() {
#ifndef ONLINE_JUDGE
  FILE *file = freopen("DEBUG.o", "w", stderr);
  if (file == NULL) {
    fprintf(stderr, "Error: could not open debug file\n");
    exit(EXIT_FAILURE);
  }
#endif
  fastio();
  int n, k;
  string s;
  cin >> n >> k >> s;

  // change at most k digits in s (of len n) to minimize s
  if (k == 0) {
    cout << s << nline;
    return 0;
  }

  if (n == 1) {
    cout << 0 << nline;
    return 0;
  }

  int i = 0;
  for (; i < n && k > 0; i++) {
    if (i == 0 && s[i] != '1') {
      s[i] = '1';
      k--;
    } else if (i > 0 && s[i] != '0') {
      s[i] = '0';
      k--;
    }
  }

  cout << s << nline;
  return 0;
  return 0;
}
