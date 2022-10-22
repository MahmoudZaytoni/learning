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
    int a, b, c; cin >> a >> b >> c;
    if (a == b + c) {
      cout << "YES\n";
    }else if (b == a + c)
      cout << "YES\n";
    else if (c == a + b)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}