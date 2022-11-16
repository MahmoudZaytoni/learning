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

/*
   *
  ***
 *****
*******
*******
 *****
  ***
   *

*/


int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  while (t--) {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
      int a, b, c; cin >> a >> b >> c;
      if (a - 1 > abs(c - b) + c - 1)
        cout << 2 << "\n";
      else if (a - 1 < abs(c - b) + c - 1)
        cout << 1 << "\n";
      else 
        cout << 3 << "\n";
    }
  }
  return 0;
}