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
    int n; cin >> n;
    if (n == 3) {
      cout << -1; 
    } else if (n & 1) {
      for (int i = n; i > n / 2 + 1; i--) {
        cout << i << " ";
      }
      for (int i = 1; i <= n / 2 + 1; i++)
        cout << i << " ";
    } else {
      for (int i = n; i >= 1; i--)
        cout << i << " ";
    }
    cout << "\n";
  }
  return 0;
}