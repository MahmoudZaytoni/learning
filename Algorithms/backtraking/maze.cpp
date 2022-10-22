#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};

int total_paths = 0;
char grid[MAX][MAX];
int rows, cols;

bool valid(int r, int c) {
  if (r < 0 || c < 0 || r >= rows || c >= cols) 
    return false;
  
  if (grid[r][c] != '.')
    return false;
  
  return true;
}

int path = 0;
void cntWays(int r, int c) {
  if (r == rows - 1 && c == cols - 1) {
    total_paths += 1;
    cout << "path " << path << endl;
    return;
  }

  for (int d = 0; d < 4; d++) {
    int nr = r + dx[d], nc = c + dy[d];
    if (!valid(nr, nc))
      continue;
    
    grid[nr][nc] = 'z';
    path += 1;
    cntWays(nr, nc);
    grid[nr][nc] = '.';
    path -= 1;
  }
}

int main()
{
  cin >> rows >> cols;
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
      cin >> grid[i][j];

  grid[0][0] = 'z';
  cntWays(0, 0);

  cout << total_paths << "\n";

}

/*
4 4
....
.X.X
...X
.X..
4 4
....
...X
....
.X..
*/