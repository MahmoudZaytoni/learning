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
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    int seqment = 0, thikness = 0, ans = 2e9;
    for (int i = 0; i < n; i++) {
      seqment += v[i];
      thikness = i + 1;
      int st = i + 1, end = i+1;
      int sum = 0;
      while (end < n) {
        sum += v[end];
        if (sum < seqment)
          end++;
        if (sum == seqment) {
          thikness = max(thikness, end - st + 1);
          st = ++end;
          sum = 0;
        }
        if (sum > seqment) {
          break;
        }
      }
      if (sum == seqment || sum == 0) {
        ans = min(ans, thikness);
      }
    }
    cout << ans << "\n";
  }
  return 0;
}