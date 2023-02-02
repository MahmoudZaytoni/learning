#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};

int total_paths = 0;
char grid[MAX][MAX];
int rows, cols;
int best_path_so_far = INT_MAX;
int total_steps = 0;
bool valid(int r, int c) {
  if (r < 0 || c < 0 || r >= rows || c >= cols) 
    return false;
  
  if (grid[r][c] != '.')
    return false;
  
  return true;
}

void cntWays(int r, int c) {
  if (r == rows - 1 && c == cols - 1) {
    if (best_path_so_far > total_steps) {
      best_path_so_far = total_steps;
      total_paths = 1;
    } else if (best_path_so_far == total_steps)
      total_paths += 1;
    return;
  }

  for (int d = 0; d < 4; d++) {
    int nr = r + dx[d], nc = c + dy[d];
    if (!valid(nr, nc))
      continue;
    
    total_steps += 1;
    grid[nr][nc] = 'z';

    cntWays(nr, nc);

    grid[nr][nc] = '.';
    total_steps -= 1;
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