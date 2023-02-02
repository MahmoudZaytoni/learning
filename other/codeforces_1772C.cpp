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
#ifndef ONLINE_JUDGE
  freopen("in.txt", "rt", stdin);
  freopen("out.txt", "wt", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    int k, n; cin >> k >> n;
    int cur = 1;
    int i = 1;
    for (i; i <= k; i++) {
      cout << cur << " ";
      if (n-(cur+i) + 1< k - i)
        break;
      cur += i;
    }
    i++;
    for (i ; i<= k; i++)
      cout << ++cur << " ";
    cout << endl;

  }
  return 0;
}