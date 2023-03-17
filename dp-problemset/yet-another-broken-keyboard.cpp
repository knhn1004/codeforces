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

ll n, k; // n - len string, k - num of letters available
const ll TEMPLATE_ARRAY_SIZE = 1e6;
ll a[TEMPLATE_ARRAY_SIZE];
ll b[TEMPLATE_ARRAY_SIZE];
ll c[TEMPLATE_ARRAY_SIZE];
string s, t;
ll ans = 0;

int main() {
#ifndef ONLINE_JUDGE
  freopen("DEBUG.o", "w", stderr);
#endif

  fastio();

  // convert typable chars to 1's and untypable chars to 0's
  // state: f(i): number of substrings constting of only one's ending at i
  // transition: a(i)==1 -> f(i) = f(i-1) + 1
  // a(i) == 0 -> f(i) = 0
  // final problem = sum(f(i))
  // base case: sring of length 0 -> 0 substrings => f(0) = 0

  cin >> n >> k;
  cin >> s;
  bool typable[26] = {false}; // [a-z] -> [0->25]
  for (ll i = 0; i < k; i++) {
    char c;
    cin >> c;
    typable[c - 'a'] = true;
  }

  for (ll i = 0; i < n; i++) {
    if (typable[s[i] - 'a']) {
      a[i] = 1;
    } else {
      a[i] = 0;
    }
  }
  ll f[n + 1];
  ll ans = 0;
  f[0] = 0;
  for (ll i = 0; i < n; i++) {
    if (a[i] == 0) {
      f[i + 1] = 0; // 1-index
    } else {
      f[i + 1] = f[i] + 1;
    }
    ans += f[i + 1];
  }

  cout << ans << endl;

  return 0;
}
