#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool dfs(int x, int y, vector<vector<char>> &board, char color) {
  board[x][y] = color;

  for (int k = 0; k < 4; k++) {
    int nx = x + dx[k], ny = y + dy[k];
    if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size()) {
      if (board[nx][ny] == '.') {
        if (!dfs(nx, ny, board, (color == 'B') ? 'W' : 'B')) {
          return false;
        }
      } else if (board[nx][ny] == color) {
        return false;
      }
    }
  }

  return true;
}

void solve(vector<vector<char>> &board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[0].size(); j++) {
      if (board[i][j] == '.') {
        if (!dfs(i, j, board, 'B')) {
          return;
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int m, n;
  cin >> m >> n;
  vector<vector<char>> board(m, vector<char>(n, '\0'));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
    }
  }

  solve(board);

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout << board[i][j];
    }
    cout << endl;
  }

  return 0;
}
