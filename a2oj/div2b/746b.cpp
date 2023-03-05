#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int N;
  string s;
  cin >> N >> s;
  // 0, 1, 2 ,3 ,4
  // 2->1->3->0->4
  // 0, 1, 2, 3
  // 1->2->0->3
  vector<int> tmp;
  for (int i = 0; i < N; i++) {
    tmp.push_back(i);
  }
  vector<int> indices;
  while (tmp.size() > 0) {
    int mid = (tmp.size() - 1) / 2;
    indices.push_back(tmp[mid]);
    tmp.erase(tmp.begin() + mid);
  }
  vector<char> output(N, '\0');
  for (int i = 0; i < indices.size(); i++) {
    // cout << indices[i] << " ";
    output[indices[i]] = s[i];
  }

  for (char c : output) {
    cout << c;
  }
  cout << endl;

  return 0;
}
