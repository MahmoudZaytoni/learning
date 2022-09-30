#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <cstring>
#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin()),((v).end())
using namespace std;
typedef long long ll;


int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int n, m;
bool isValid(int x, int y) {
  if (x < 0 || y < 0 || x >= n || y >= m)
    return false;
  return true;
}

int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  //cin >> t;
  while (t--) {
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> matrix[i][j];

    vector<vector<int>> matrix2(n, vector<int>(m));
    bool ok = true;
    for (int i = 0; i < n && ok; i++) {
      for (int j = 0; j < m && ok; j++) {
        int row = 0, col = 0;
        if (matrix[i][j]) {
          col++, row++;
          for (int d = 0; d < 4; d++) {
            int nr = i + dx[d], nc = j + dy[d];
            while (nr < n && nc < m && nr >= 0 && nc >= 0) {
              if (matrix[nr][nc] && d <= 1)
                col++;
              if (matrix[nr][nc] && d > 1)
                row++;
              nr += dx[d];
              nc += dy[d];
            }
          }
        }

        if (row + col == n + m)
          matrix2[i][j] = 1;

        if (row == m || col == n || row == 0 || col == 0)
          continue;
        ok = false;
      }
    }
    
    if (matrix2 == vector<vector<int>>(n, vector<int>(m)) && matrix2 != matrix)
      ok = false;
    if (ok) {
      cout << "YES\n";
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
          cout << matrix2[i][j] << " ";
        cout << "\n";
      }
    } else 
      cout << "NO\n";

  }
  return 0;
}