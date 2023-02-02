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
  ll a, b; cin >> a >> b;
  vector<int> v1(3), v2(3);
  while (true) {
    if (a % 2 == 0)
      v1[0] += 1, a /= 2;
    else if (a % 3 == 0)
      v1[1] += 1, a /= 3;
    else if (a % 5 == 0)
      v1[2] ++, a /= 5;
    else break;
  }
  while (true) {
    if (b % 2 == 0)
      v2[0] += 1, b /= 2;
    else if (b % 3 == 0)
      v2[1] += 1, b /= 3;
    else if (b % 5 == 0)
      v2[2] ++, b /= 5;
    else 
      break;
  }

  if (a != b)
    cout << -1 << "\n";
  else cout << abs(v1[0] - v2[0]) + abs(v1[1] - v2[1]) + abs(v1[2] - v2[2]);

  return 0;
}