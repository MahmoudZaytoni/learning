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
  //cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    if (((n * n) + 1) / 2 < k)
      cout << "NO\n";
    else {
      cout << "YES\n";
      for (int i = 0; i < n; i++) {
        for (int j = 1; j <= n; j++) {
          if ((i + j) & 1 && k) {
            cout << 'L';
            k--;
          }
          else 
            cout << 'S';
        }
        cout << "\n";
      }
    }
  }
  return 0;
}