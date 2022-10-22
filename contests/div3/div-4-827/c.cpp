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

int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    string grid[8];
    for (int i = 0; i < 8; i++) {
      cin >> grid[i];
    }
    bool same = false;
    char c = '-';
    for (int i = 0; i < 8; i++) {
      same = false;
      for (int j = 1; j < 8; j++) {
        if (grid[i][j] == grid[i][j-1] && grid[i][j] == 'R')
          same = true;
        else {
          same = false;
          break;
        }
      }
      if (same) 
        c = 'R';
    }
    for (int i = 0; i < 8; i++) {
      same = false;
      for (int j = 1; j < 8; j++) {
        if (grid[j][i] == grid[j-1][i] && grid[j][i] == 'B')
          same = true;
        else {
          same = false;
          break;
        }
      }
      if (same) {
        c = 'B';
      }
    }

    cout << c << "\n";
  }
  return 0;
}