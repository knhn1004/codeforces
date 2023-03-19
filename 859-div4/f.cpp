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
  int n, m, i1, j1, i2, j2;
  string d; // initial direction
  // enum dir { DR, DL, UR, UL };
  // dir d;
  int dx[] = {1, -1, -1, 1}; // i
  int dy[] = {1, 1, -1, -1}; // j
  // string dir[] = {"DR", "DL", "UL", "UR"};
  unordered_map<string, int> dir{
      {"DR", 0},
      {"DL", 1},
      {"UL", 2},
      {"UR", 3},
  };

  while (t--) {
    cin >> n >> m >> i1 >> j1 >> i2 >> j2 >> d;
    // number of bounces before ball from i1,j1 reachs i2, j2
    // if not reachable print -1
    int x = i1, y = j1, bounces = 0;
    bool flag = false;
    do {
      x = x + dx[dir[d]], y = y + dy[dir[d]];
      if (x == 1 || x == n || y == 1 || y == m) {
        // change direction

        // 4 corners
        if (x == 1 && y == 1)
          d = "DR";
        else if (x == 1 && y == m)
          d = "UR";
        else if (x == n && y == 1)
          d = "DL";
        else if (x == n && y == m)
          d = "UL";
        else {
          if (x == 1 && d == "UL") {
            d = "UR";
          } else if (x == 1 && d == "DL") {
            d = "DR";
          } else if (x == n && d == "UR") {
            d = "UL";
          } else if (x == n && d == "DR") {
            d = "DL";
          } else if (y == 1 && d == "UR") {
            d = "DR";
          } else if (y == 1 && d == "UL") {
            d = "DL";
          } else if (y == m && d == "DR") {
            d = "UR";
          } else if (y == m && d == "DL") {
            d = "UL";
          }
        }
        // add bounces
        bounces++;
      }

      if (x == i2 && y == j2) {
        flag = true;
        break;
      }
    } while (!(x == i1 && y == j1));
    cout << (flag ? bounces : -1) << nline;
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
