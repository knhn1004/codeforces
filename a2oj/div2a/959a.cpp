#include <bits/stdc++.h>
using namespace std;

string E = "Ehab";
string M = "Mahmoud";

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int a;
  cin >> a;

  cout << ((a % 2) ? E : M) << endl;

  return 0;
}
