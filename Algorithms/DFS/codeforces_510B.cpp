// B. Fox And Two Dots 
/****************************************************
 *** Problem Number : 510B
 *** Diffculty      : B
 *** URL            : https://codeforces.com/contest/510/problem/B
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<char>> GRAPH;
typedef pair<int,int> cell;
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
int n, m;

bool isValid(int r, int c) {
  if (r < 0 || c < 0 || r >= n || c >= m)
    return false;
  return true;
}

void dfs2(GRAPH &adjMatrix, cell current, cell parent, bool &cycle) {
  char save = adjMatrix[current.first][current.second];

  if (save >= 'a' && save <= 'z') {
    cycle = true;
    return;
  }

  adjMatrix[current.first][current.second] = tolower(save);

  for (int d = 0; d < 4; d++) { 
    int nr = dx[d] + current.first, nc = dy[d] + current.second;
    if (!isValid(nr, nc) || make_pair(nr,nc) == parent)
      continue;
    

    if (adjMatrix[nr][nc] == save || adjMatrix[nr][nc] == tolower(save)) {
      dfs2(adjMatrix, make_pair(nr,nc), current, cycle);
    }
  }
  //adjMatrix[current.first][current.second] = save;
}

int main()
{
  int t;cin >>t;
  while (t--) {

    cin >> n >> m;
    GRAPH adj_matrix(n, vector<char> (m));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> adj_matrix[i][j];
    

    bool has_cycle = false;
    for (int i = 0; i < n && !has_cycle; i++) {
      for (int j = 0; j < m && !has_cycle; j++) {
        if (adj_matrix[i][j] >= 'A' && adj_matrix[i][j] <= 'Z') {
          cell current = make_pair(i,j);
          dfs2(adj_matrix, make_pair(i,j), make_pair(-1,-1), has_cycle);
        }
      }
    }
    cout << (has_cycle ? "Yes\n" : "No\n");
  }
  return 0;
}