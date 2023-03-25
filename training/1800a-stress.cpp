#include <bits/stdc++.h>
// #include <x86intrin.h>
// #include <sys/resource.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// Pragmas
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")

#define v vector
// Aliases
using ll = long long;
using ull = unsigned long long;
using ld = long double;
// template<typename T>
// using oset =  tree<T, null_type, less<T>, rb_tree_tag,
// tree_order_statistics_node_update>;

// Constants
constexpr ll INF = 4e18;
constexpr ld EPS = 1e-9;
constexpr ll MOD = 1e9 + 7;

// Macros
#define F first
#define S second
#define all(x) begin(x), end(x)
#define allr(x) rbegin(x), rend(x)
#define int long long
#define pb push_back
#define py cout << "YES\n";
#define pm cout << "-1\n";
#define pn cout << "NO\n";
// #define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])
#define fl(i, n) for (int i = 0; i < n; i++)

// srand(time(NULL));
mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());

typedef struct testcase {
  int n;
  string s;
} testcase;

int random_number(int a, int b) { return a + (rng() % b); }

testcase generate_testcase() {
  testcase randomTest;
  randomTest.n = random_number(1, 51);
  randomTest.s.resize(randomTest.n);
  char a[8] = {'m', 'e', 'o', 'w', 'M', 'E', 'O', 'W'};
  for (int i = 0; i < randomTest.n; i++) {
    int k = random_number(0, 8);
    randomTest.s[i] = a[k];
  }
  return randomTest;
}

// ofc the below code is correct since it's a brute force
bool brute_force(testcase T) {
  int n = T.n;
  string s = T.s;
  transform(s.begin(), s.end(), s.begin(), ::tolower);
  s.resize(unique(all(s)) - s.begin());
  return (s == "meow");
}

// Your optimized code but it's giving TLE or WA or RT or something >_<
bool optimized_solution(testcase T) {
  int n = T.n;
  string s = T.s;
  char a[4] = {'m', 'e', 'o', 'w'};

  int cur = 0;
  for (int i = 0; i < n && cur < 4; i++) {
    if (tolower(s[i]) == a[cur]) {
      continue;
    }
    if (++cur < 4 && tolower(s[i]) != a[cur]) {
      return false;
    }
  }
  return (cur < 4);
}

void debugger() {
  testcase random = generate_testcase();
  bool ans1 = brute_force(random);
  bool ans2 = optimized_solution(random);
  if (ans1 != ans2) {
    cout << random.s << ' ' << ans1 << ' ' << ans2 << endl;
  }
}

int32_t main() {
  cout << fixed << setprecision(6);
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 10000;
  while (t--) {
    debugger();
  }
}
