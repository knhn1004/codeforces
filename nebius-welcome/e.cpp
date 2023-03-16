// we can assign an aux node to each node
// we can only reach the adj node or adj of aux node, we can also hop aux's
// print if it's possible to reach all nodes for each node
// if yes, print each node's aux node

/* #include <bits/stdc++.h>
#define ll long long
using namespace std;

void bfs(int node, vector<vector<int>> &adj, vector<bool> &visited) {
  queue<int> q;
  q.push(node);
  visited[node] = true;
  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    for (int neighbor : adj[curr]) {
      if (!visited[neighbor]) {
        visited[neighbor] = true;
        q.push(neighbor);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m; // number of nodes, number of edges
  cin >> n >> m;
  vector<vector<int>> adj(2 * n);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u - 1].push_back(v - 1 + n);
    adj[v - 1].push_back(u - 1 + n);
    adj[v - 1 + n].push_back(u - 1);
    adj[u - 1 + n].push_back(v - 1);
  }

  vector<int> aux(n, -1);
  for (int i = 0; i < n; i++) {
    vector<bool> visited(2 * n, false);
    bfs(i, adj, visited);
    bool all_visited = true;
    for (int j = 0; j < n; j++) {
      if (!visited[j] && visited[j + n]) {
        all_visited = false;
        break;
      }
    }
    if (all_visited) {
      aux[i] = i;
    } else {
      for (int j = 0; j < n; j++) {
        if (!visited[j] && visited[j + n]) {
          aux[i] = j;
          break;
        }
      }
    }
  }

  for (int a : aux) {
    cout << a + 1 << " ";
  }
  cout << endl;

  return 0;
} */

#include <bits/stdc++.h>
#define ll long long
using namespace std;

void bfs(int node, vector<vector<int>> &adj, vector<bool> &visited) {
  queue<int> q;
  q.push(node);
  visited[node] = true;
  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    for (int neighbor : adj[curr]) {
      if (!visited[neighbor]) {
        visited[neighbor] = true;
        q.push(neighbor);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m; // number of nodes, number of edges
  cin >> n >> m;
  vector<vector<int>> adj(2 * n);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u - 1].push_back(v - 1 + n);
    adj[v - 1].push_back(u - 1 + n);
    adj[v - 1 + n].push_back(u - 1);
    adj[u - 1 + n].push_back(v - 1);
  }

  vector<int> aux(n, -1);
  vector<bool> used(2 * n, false);
  for (int i = 0; i < n; i++) {
    vector<bool> visited(2 * n, false);
    bfs(i, adj, visited);
    bool all_visited = true;
    for (int j = 0; j < n; j++) {
      if (!visited[j] && visited[j + n]) {
        all_visited = false;
        break;
      }
    }
    if (all_visited) {
      aux[i] = i;
      used[i] = true;
    } else {
      bool assigned = false;
      for (int j : adj[i]) {
        if (!visited[j] && !used[j]) {
          aux[i] = j - n;
          used[j] = true;
          assigned = true;
          break;
        }
      }
      if (!assigned) {
        for (int j = 0; j < n; j++) {
          if (!visited[j] && !used[j + n]) {
            aux[i] = j;
            used[j + n] = true;
            break;
          }
        }
      }
    }
  }

  for (int a : aux) {
    cout << a + 1 << " ";
  }
  cout << endl;

  return 0;
}
